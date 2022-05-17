#include <PeriodicTimer.h>

// Constructor
//
// A PeriodicTimer object sets an internal boolean true periodically
// which remains true until it is read, at which it is set back to false
// to wait for the next time it is set true.  It acts like an alarm
// which goes off on a regular basis, and persists each time until
// someone resets it.
//
// Note that interval is set in full seconds, but the state of this object
// is updated 10 times a second.
PeriodicTimer::PeriodicTimer() : StateMachine(100, true),
    m_period(0), m_remaining(0), m_substep(0),
    m_alarm(false)
{
}

// Performs the update cycle for this object.
bool PeriodicTimer::update()
{
    // Time to update?
    if (StateMachine::update()) {
        // Is timer running?
        if (m_period > 0) {
            // Have we counted down a whole second?
            if (--m_substep == 0) {
                // If so, decrement remaining time in seconds,
                // and test if that completes alarm interval.
                m_substep = 10;
                // Has remaining time reached zero?
                if (--m_remaining == 0) {
                    // If so, set alarm state and restart timing interval.
                    m_alarm = true;
                    m_remaining = m_period;
                }
            }
        }
        // Was updated.
        return true;
    }
    // No update now.
    return false;
}

// Start timer with a period specified in seconds.
// Clears any lingering alarm status.
void PeriodicTimer::start(const unsigned int sec)
{
    m_substep = 10;
    m_remaining = m_period = sec;
    m_alarm = false;
}

// Stop timer.  Does not clear alarmed status.
void PeriodicTimer::stop()
{
    m_period = m_remaining = m_substep = 0;
}

// Get time remaining until next alarm occurs.
unsigned int PeriodicTimer::getTime() const
{
    return m_remaining;
}

// Test if alarm has occurred since last reset.
bool PeriodicTimer::isAlarm()
{
    // Get the current alarm status before resetting it.
    bool alarm = m_alarm;
    m_alarm = false;
    // Return status.
    return alarm;
}
