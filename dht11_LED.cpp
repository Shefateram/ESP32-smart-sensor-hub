#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 23
#define DHTTYPE DHT11
#define LED_PIN 25

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    Serial.println("Temperature warning system started!");
}

void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT11!");
    } 
    else {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");

        if (temperature >= 35.0) {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("⚠️ HIGH TEMPERATURE!");
        } 
        else {
            digitalWrite(LED_PIN, LOW);
        }
    }

    delay(2000);
}
