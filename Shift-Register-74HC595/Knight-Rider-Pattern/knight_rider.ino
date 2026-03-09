int dataPin  = 4;
int clockPin = 6;
int latchPin = 5;

byte pattern = 1;
bool forward = true;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, pattern);
  digitalWrite(latchPin, HIGH);
  delay(150);

  if (forward) {
    pattern <<= 1;
    if (pattern == 0b10000000) forward = false;
  } else {
    pattern >>= 1;
    if (pattern == 0b00000001) forward = true;
  }
}
