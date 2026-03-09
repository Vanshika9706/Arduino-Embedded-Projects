#define MIC_PIN A0

// ✅ CONFIRMED RGB PIN MAPPING
#define BLUE_PIN  9
#define RED_PIN   10
#define GREEN_PIN 11

int state = 0;
int lastVal = 0;
bool clapLock = false;

// Tuned for your setup
const int SPIKE   = 20;    // sudden jump needed
const int SILENCE = 139;   // silence baseline

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setup() {
  Serial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  setColor(0, 0, 0); // LED OFF initially
  Serial.println("System ready. Clap or play music.");
}

void loop() {
  int currentVal = analogRead(MIC_PIN);
  int diff = currentVal - lastVal;

  // Detect clap / beat
  if (diff > SPIKE && !clapLock) {
    clapLock = true;
    state++;

    int color = state % 8;

    Serial.print("CLAP detected | Mic=");
    Serial.print(currentVal);
    Serial.print(" | Color = ");

    switch (color) {
      case 0:
        setColor(255, 0, 0);
        Serial.println("RED");
        break;

      case 1:
        setColor(0, 255, 0);
        Serial.println("GREEN");
        break;

      case 2:
        setColor(0, 0, 255);
        Serial.println("BLUE");
        break;

      case 3:
        setColor(255, 255, 0);
        Serial.println("YELLOW");
        break;

      case 4:
        setColor(0, 255, 255);
        Serial.println("CYAN");
        break;

      case 5:
        setColor(255, 0, 255);
        Serial.println("MAGENTA");
        break;

      case 6:
        setColor(255, 255, 255);
        Serial.println("WHITE");
        break;

      case 7:
        setColor(0, 0, 0);
        Serial.println("OFF");
        break;
    }
  }

  // Unlock when sound returns to silence
  if (currentVal < SILENCE) {
    clapLock = false;
  }

  lastVal = currentVal;
  delay(2);   // fast sampling for beats
}
