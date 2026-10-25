#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    while (true); // Don't proceed, loop forever
  }
  display.clearDisplay();

  // Character's ears
  display.fillTriangle(36, 22, 42, 5, 53, 22, SSD1306_WHITE); // Left ear
  display.fillTriangle(75, 22, 86, 5, 92, 22, SSD1306_WHITE); // Right ear

  // Head
  display.fillRoundRect(32, 17, 64, 39, 8, SSD1306_WHITE); // Head

  // Eyes
  display.fillRoundRect(43, 29, 12, 14, 3, SSD1306_BLACK); // Left eye
  display.fillRoundRect(73, 29, 12, 14, 3, SSD1306_BLACK); // Right eye

  // Eye highlights
  display.drawPixel(47, 32, SSD1306_WHITE); // Left eye highlight
  display.drawPixel(77, 32, SSD1306_WHITE); // Right eye highlight

  // Mouth
  display.drawLine(55, 45, 73, 45, SSD1306_BLACK); // Mouth
  display.drawPixel(63, 48, SSD1306_BLACK); // Mouth center pixel
  display.drawPixel(65, 48, SSD1306_BLACK); // Mouth center pixel

  display.display();

}

void loop() {
  // Nothing to do here
}
