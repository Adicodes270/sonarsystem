#include <Servo.h>

Servo myServo;
const int servoPin = 12;

void setup() {
  Serial.begin(9600);
  delay(200);  // Wait for Serial Monitor to open
  Serial.println("Servo sweep test starting...");
  myServo.attach(servoPin);
}

void loop() {
  // Sweep from 0° to 180°
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    Serial.print("Servo angle → ");
    Serial.println(pos);
    delay(15);  // Allow servo motion
  }

  delay(500);  // Small pause between sweeps

  // Sweep back from 180° to 0°
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    Serial.print("Servo angle → ");
    Serial.println(pos);
    delay(15);
  }

  delay(500);
}
