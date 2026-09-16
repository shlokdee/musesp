#pragma once
#include <Arduino.h>

struct Button {
  uint8_t pin;
  bool lastReading;
  bool stableState;
  unsigned long lastDebounceTime;

  Button(uint8_t p)
    : pin(p), lastReading(HIGH), stableState(HIGH), lastDebounceTime(0) {}
};

const unsigned long DEBOUNCE_MS = 30;

inline bool pressed(Button &b) {
  bool reading = digitalRead(b.pin);

  if (reading != b.lastReading) {
    b.lastDebounceTime = millis();
  }
  b.lastReading = reading;

  if ((millis() - b.lastDebounceTime) > DEBOUNCE_MS) {
    if (reading != b.stableState) {
      b.stableState = reading;
      if (b.stableState == LOW) {
        return true;
      }
    }
  }
  return false;
}