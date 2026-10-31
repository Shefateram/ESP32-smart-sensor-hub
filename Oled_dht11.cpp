#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN 23
#define DHTTYPE DHT11
#define LED_PIN 25

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);

    Wire.begin(21, 22);

    dht.begin();

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED not found!");
        while (true);
    }

    display.clearDisplay();
    display.display();
}

void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read DHT11!");

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 25);
        display.println("DHT11 Error");
        display.display();

        delay(2000);
        return;
    }

    // Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Temperature warning LED
    if (temperature >= 35.0) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    // OLED
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("Weather Station");

    display.setTextSize(2);

    display.setCursor(0, 18);
    display.print("Temp ");
    display.print(temperature, 1);
    display.println(" C");

    display.setCursor(0, 43);
    display.print("Hum  ");
    display.print(humidity, 1);
    display.println("%");

    display.display();

    delay(2000);
}
