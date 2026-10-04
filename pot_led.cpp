#include <Arduino.h>

#define POT_PIN 32
#define LED_PIN 25

void setup() {
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int potValue = analogRead(POT_PIN);

    int brightness = map(potValue, 0, 4095, 0, 255);

    analogWrite(LED_PIN, brightness);

    Serial.print("Potentiometer: ");
    Serial.print(potValue);
    Serial.print(" | Brightness: ");
    Serial.println(brightness);

    delay(50);
}
