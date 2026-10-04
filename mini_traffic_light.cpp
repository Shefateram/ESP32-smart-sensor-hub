#include <Arduino.h>

void setup() {
    pinMode(5, OUTPUT);   // Red
    pinMode(18, OUTPUT);  // Green
    pinMode(19, OUTPUT);  // Yellow
}

void loop() {
    // RED
    digitalWrite(5, HIGH);
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    delay(3000);

    // GREEN
    digitalWrite(5, LOW);
    digitalWrite(18, HIGH);
    digitalWrite(19, LOW);
    delay(3000);

    // YELLOW
    digitalWrite(5, LOW);
    digitalWrite(18, LOW);
    digitalWrite(19, HIGH);
    delay(1000);
}
