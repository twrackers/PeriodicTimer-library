#include <PeriodicTimer.h>

// PeriodicTimer object's timeout period is set by start() method,
// so it can be changed at any time, whether the object is already
// started or stopped.
PeriodicTimer g_watchdog;

// Timeout will be checked ~33 times per second (30 msec).
const unsigned int g_samplePeriod = 30;
StateMachine g_timer(g_samplePeriod, true);
unsigned int g_sample = 0;

// On each pass, a random interval in range [5, 15) seconds is selected.
unsigned int g_time = 0;

void setup() {
  Serial.begin(115200);
  // Seed the random number generator.
  randomSeed(analogRead(0));
}

void loop() {
  
  // If time interval has run out...
  if (g_time == 0) {
    
    // Choose tne next time interval, print starting message.
    g_time = random(5, 15);
    Serial.println();
    Serial.print("Count down from ");
    Serial.print(g_time);
    Serial.print("...\t");
    
    // Reset the watchdog to 10 seconds.
    // It may or may not have run out from the last interval.
    g_watchdog.start(10);
    
  }

  // Time to display countdown?
  if (g_timer.update()) {
    if (g_sample > 0) {
      --g_sample;
    } else {
      // Decrement and show remaining time.
      Serial.print(--g_time);
      Serial.print("...\t");
      g_sample = 1000 / g_samplePeriod;
    }
  }

  // Update PeriodicTimer object.
  g_watchdog.update();
  
  // Has watchdog timed out?
  if (g_watchdog.isAlarm()) {
    Serial.print("beep\t");
  }
}
