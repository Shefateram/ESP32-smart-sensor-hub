#include <Arduino.h>

 #define POT_PIN 32
 #define LED_PIN 25

void setup() {
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int potValue = analogRead(POT_PIN);

    int Brightness = map(potValue, 0, 4095, 255, 0);

    analogWrite(LED_PIN, Brightness);

    Serial.print("Potentiometer: ");
    Serial.println(potValue);
    Serial.print(" | Brightness: ");
    Serial.println(Brightness);

    delay(50);
}
