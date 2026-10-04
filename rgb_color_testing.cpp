#include <Arduino.h>

#define RGB_PIN 5

void setup() {
    pinMode(RGB_PIN, OUTPUT);
}

void loop() {
    digitalWrite(RGB_PIN, HIGH);
}
