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
  int value = analogRead(POT);

  // Six custom colour zones
  if (value < 683) {
    // Pink → Magenta
    int t = map(value, 0, 682, 0, 255);
    showColor(255, 40, 100 + t / 2);
  }
  else if (value < 1366) {
    // Magenta → Purple
    int t = map(value, 683, 1365, 0, 255);
    showColor(255 - t / 2, 0, 255);
  }
  else if (value < 2049) {
    // Purple → Softer blue
    int t = map(value, 1366, 2048, 0, 255);
    showColor(127 - t / 2, 0, 100 + t / 2);
  }
  else if (value < 2732) {
    // Cyan → Green
    int t = map(value, 2049, 2731, 0, 255);
    showColor(0, 255, 180 - t / 2);
  }
  else if (value < 3415) {
    // Green → Yellow
    int t = map(value, 2732, 3414, 0, 255);
    showColor(t, 255, 0);
  }
  else {
    // Yellow → Orange → Red
    int t = map(value, 3415, 4095, 0, 255);
    showColor(255, 255 - t, 0);
  }

  delay(10);
}
