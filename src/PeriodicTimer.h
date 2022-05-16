#ifndef _PERIODIC_TIMER__H_
#define _PERIODIC_TIMER__H_

#include <StateMachine.h>

/**
 * PeriodicTimer
 *
 * This class extends the StateMachine class to set a boolean flag to true
 * periodically.  The flag will be reset to false when it is read.
 * A PeriodicTimer object is defined to be a real-time StateMachine object.
 */
class PeriodicTimer : public StateMachine
{
    private:
        unsigned int m_period;
        unsigned int m_remaining;
        unsigned int m_substep;
        bool m_alarm;

public:
    /**
     * Constructor
     */
    PeriodicTimer();
    
    /**
     * Update this object's state
     *
     * @return true if object's state was updated
     */
    virtual bool update();
  
    /**
     * Start the timer object with a specific repeat period
     *
     * @param sec timer period in seconds
     */
     void start(const unsigned int sec);
  
    /**
     * Stop the periodic timer
     */
     void stop();
  
    /**
     * Get time remaining before next alarm
     *
     * @return time in seconds until next alarm occurs
     */
     unsigned int getTime() const;
  
    /**
     * Test if alarm has occurred, resetting it if so
     *
     * @return true if alarm has occurred since last reset
     */
     bool isAlarm();
};

#endif
