#include <Streaming.h>

#include <PeriodicTimer.h>

PeriodicTimer g_timer;
unsigned int g_count = 0;

void setup() {
  Serial.begin(115200);
  g_timer.start(5);
}

void loop() {
  if (g_timer.update()) {
    if (g_timer.isAlarm()) {
      Serial << ++g_count << endl;
    }
    Serial << g_timer.getTime() << " ";
  }
}
