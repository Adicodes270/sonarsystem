#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 12;

long duration;
int distance;
Servo myServo;

void setup() {
  Serial.begin(9600);
  delay(200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time with timeout
  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;

  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    // Map distance (e.g., 2–200 cm) to servo angle (0–180°)
    int angle = map(distance, 2, 200, 0, 180);
    angle = constrain(angle, 0, 180);
    myServo.write(angle);
  }

  delay(200);
}
