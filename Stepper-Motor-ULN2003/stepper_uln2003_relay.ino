#include <Stepper.h>

#define STEPS 2048

Stepper stepperMotor(STEPS, 8, 10, 9, 11);
int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);   // Turn relay ON
  stepperMotor.setSpeed(10);      // RPM
}

void loop() {
  stepperMotor.step(512);   // Rotate 90°
  delay(2000);

  stepperMotor.step(-512);  // Reverse
  delay(2000);
}
