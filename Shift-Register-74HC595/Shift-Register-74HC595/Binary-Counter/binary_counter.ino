/*
Binary Counter using 74HC595 Shift Register
Author: Vanshika

Demonstrates a binary counting pattern using LEDs
connected through a 74HC595 shift register.
*/

int dataPin = 4;
int clockPin = 6;
int latchPin = 5;

byte counter = 0;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, counter);
  digitalWrite(latchPin, HIGH);

  delay(500);   // speed of counting
  counter++;    // increment counter

}
