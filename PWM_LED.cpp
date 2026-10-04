#include <Arduino.h>

void setup() {
    pinMode(5, OUTPUT);
}

void loop() {
    // Fade brighter
    for (int brightness = 0; brightness <= 255; brightness++) {
        analogWrite(5, brightness);
        delay(10);
    }

    // Fade dimmer
    for (int brightness = 255; brightness >= 0; brightness--) {
        analogWrite(5, brightness);
        delay(10);
    }
}
