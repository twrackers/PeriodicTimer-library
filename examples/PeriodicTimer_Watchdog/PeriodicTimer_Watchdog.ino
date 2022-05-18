#include <PeriodicTimer.h>

PeriodicTimer g_watchdog;
StateMachine g_timer(1000, true);
unsigned int g_time = 0;

void setup() {
  Serial.begin(115200);
  // Seed the random number generator.
  randomSeed(analogRead(0));
}

void loop() {
  g_watchdog.update();
  if (g_time == 0) {
    g_time = random(5, 15);
    g_watchdog.start(10);
    Serial.println();
  }
  if (g_timer.update()) {
    Serial.println(g_time--);
  }
  if (g_watchdog.isAlarm()) {
    Serial.println("beep");
  }
}
