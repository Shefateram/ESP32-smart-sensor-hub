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
#define PIR_PIN 27

#define DARK_THRESHOLD 2500

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);

    Wire.begin(21, 22);
    dht.begin();

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    pinMode(PIR_PIN, INPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED not found!");
        while (true);
    }

    display.clearDisplay();
    display.display();

    Serial.println("Smart Monitor started!");
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int lightValue = analogRead(LDR_PIN);
    int motion = digitalRead(PIR_PIN);

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("DHT11 read failed!");
        delay(2000);
        return;
    }

    bool isDark = lightValue >= DARK_THRESHOLD;
    bool motionDetected = (motion == HIGH);

    // LED ON only when it is dark AND motion is detected
    if (isDark && motionDetected) {
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
    Serial.print(lightValue);
    Serial.print(" | ");

    if (isDark) {
        Serial.print("DARK");
    } else {
        Serial.print("BRIGHT");
    }

    Serial.print(" | ");

    if (motionDetected) {
        Serial.println("MOTION DETECTED");
    } else {
        Serial.println("No motion");
    }

    // OLED
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Smart Monitor");

    display.setCursor(0, 12);
    display.print("T: ");
    display.print(temperature, 1);
    display.println(" C");

    display.setCursor(0, 23);
    display.print("H: ");
    display.print(humidity, 1);
    display.println(" %");

    display.setCursor(0, 34);
    display.print("Light: ");
    display.print(lightValue);

    display.setCursor(0, 45);
    display.print("Motion: ");

    if (motionDetected) {
        display.println("YES");
    } else {
        display.println("NO");
    }

    display.setCursor(0, 56);

    if (isDark && motionDetected) {
        display.println("LED: ON");
    } else {
        display.println("LED: OFF");
    }

    display.display();

    delay(500);
}
