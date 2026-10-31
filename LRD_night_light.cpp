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
#define LDR_PIN 34

#define DARK_THRESHOLD 2500

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
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int lightValue = analogRead(LDR_PIN);

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("DHT11 read failed!");
        delay(2000);
        return;
    }

    // Turn LED on when it gets dark
    if (lightValue >= DARK_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    // Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity, 1);
    Serial.print(" % | Light: ");
    Serial.println(lightValue);

    // OLED
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Weather Station");

    display.setCursor(0, 16);
    display.print("T: ");
    display.print(temperature, 1);
    display.println(" C");

    display.setCursor(0, 29);
    display.print("H: ");
    display.print(humidity, 1);
    display.println(" %");

    display.setCursor(0, 42);
    display.print("Light: ");
    display.println(lightValue);

    display.display();

    delay(1000);
}
