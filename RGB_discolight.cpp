#include <Arduino.h>

const int BLUE = 5; // Pin for blue LED
const int GREEN = 18;  // Pin for green LED
const int RED = 19; // Pin for red LED

void setup() {
  // Initialize the LED pins as outputs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void showColor(int r, int g, int b) {
  // Set the LED colors based on the input values
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void loop() {
  showColor(255, 0, 0); // Red
  delay(1000);          // Wait for 1 second

  showColor(0, 255, 0); // Green
  delay(1000);          // Wait for 1 second

  showColor(0, 0, 255); // Blue
  delay(1000);          // Wait for 1 second

  showColor(255, 255, 0); // Yellow
  delay(1000);            // Wait for 1 second

  showColor(0, 255, 255); // Cyan
  delay(1000);            // Wait for 1 second

  showColor(255, 0, 255); // Magenta
  delay(1000);            // Wait for 1 second

  showColor(255, 255, 255); // White
  delay(1000);              // Wait for 1 second

  showColor(0, 0, 0); // Off
  delay(1000);        // Wait for 1 second
}
