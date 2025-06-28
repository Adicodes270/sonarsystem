#include <Servo.h>
const int trigPin = 10, echoPin = 11, servoPin = 12;
Servo myServo;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);  // Show setup ran
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  digitalWrite(13, !digitalRead(13)); // Blink LED
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Dist: "); Serial.print(distance); Serial.println(" cm");
  
  int angle = map(distance, 2, 200, 0, 180); // Scale dist to angle
  angle = constrain(angle, 0, 180);
  myServo.write(angle);
  delay(100);
}