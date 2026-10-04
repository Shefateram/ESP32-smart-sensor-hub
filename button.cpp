#include <Arduino.h>

void setup() {
    pinMode(4, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
    if (digitalRead(4) == LOW) {
        Serial.println("BUTTON PRESSED!");
    } else {
        Serial.println("Button not pressed");
    }

    delay(200);
}
