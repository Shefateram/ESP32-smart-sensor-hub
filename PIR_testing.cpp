#include <Arduino.h>

#define PIR_PIN 27

void setup() {
    Serial.begin(115200);
    pinMode(PIR_PIN, INPUT);

    Serial.println("PIR starting...");
    delay(30000);
    Serial.println("PIR ready!");
}

void loop() {
    int motion = digitalRead(PIR_PIN);

    if (motion == HIGH) {
        Serial.println("MOTION DETECTED!");
    } else {
        Serial.println("No motion");
    }

    delay(500);
}
