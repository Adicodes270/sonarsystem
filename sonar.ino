#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 12;

Servo servo;

void setup() {
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 🔁 Clockwise sweep
  Serial.println("Sweeping Clockwise...");
  servo.write(95);  // Slow clockwise
  for (int i = 0; i <= 36; i++) { // Simulate 360° in 10° steps
    delay(200); // Wait for ~10° rotation
    readDistance(i * 10);
  }
  servo.write(90); // Stop
  delay(1000);

  // 🔁 Counter-clockwise sweep
  Serial.println("Sweeping Counter-Clockwise...");
  servo.write(85);  // Slow counter-clockwise
  for (int i = 36; i >= 0; i--) {
    delay(200);
    readDistance(i * 10);
  }
  servo.write(90); // Stop
  delay(1000);
}

void readDistance(int angle) {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("°, Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
