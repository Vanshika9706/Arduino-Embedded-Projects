// ===== Binary LEDs =====
int ledPins[4] = {2, 3, 7, 12};

// ===== 74HC595 =====
const int dataPin  = 4;
const int latchPin = 5;
const int clockPin = 6;

// ===== Digit pins (your polarity) =====
const int digitPins[4] = {8, 9, 10, 11};

// Common Anode segment patterns (gfedcba)
const byte segCA[10] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000  // 9
};

int value = 0;

void setup() {
  // LEDs
  for (int i = 0; i < 4; i++)
    pinMode(ledPins[i], OUTPUT);

  // 74HC595
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Digits OFF
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW);
  }
}

void loop() {

  // 🔢 show binary on LEDs
  for (int b = 0; b < 4; b++) {
    digitalWrite(ledPins[b], (value >> b) & 1);
  }

  // 🔢 break number into digits
  int digits[4];
  digits[0] = value / 1000;
  digits[1] = (value / 100) % 10;
  digits[2] = (value / 10) % 10;
  digits[3] = value % 10;

  // 🧠 multiplex display
  for (int refresh = 0; refresh < 120; refresh++) {
    for (int i = 0; i < 4; i++) {

      // all digits OFF
      for (int j = 0; j < 4; j++)
        digitalWrite(digitPins[j], LOW);

      // load segment data
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, segCA[digits[i]]);
      digitalWrite(latchPin, HIGH);

      // enable digit
      digitalWrite(digitPins[i], HIGH);
      delay(2);
    }
  }

  // increment counter
  value++;
  if (value > 15) value = 0;
}
