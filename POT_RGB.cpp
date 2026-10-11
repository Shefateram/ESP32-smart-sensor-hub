#include <Arduino.h>

const int BLUE = 5;
const int GREEN = 18;
const int RED = 19;
const int POT = 32;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void showColor(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void loop() {
  int potValue = analogRead(POT);

  int section = map(potValue, 0, 4095, 0, 5);
  int amount = map(potValue % 820, 0, 819, 0, 255);

  switch (section) {
    case 0: showColor(255, amount, 0); 
  break; // Red to Yellow
    case 1: showColor(255 - amount, 255, 0);
  break; // Yellow to Green
    case 2: showColor(0, 255, amount);
  break; // Green to Cyan
    case 3: showColor(0, 255 - amount, 255);
  break; // Cyan to Blue
    case 4: showColor(amount, 0, 255);
  break; // Blue to Magenta
    case 5: showColor(255, 0, 255 - amount);
  break; // Magenta to Red
  } 

  delay(10);
  }
