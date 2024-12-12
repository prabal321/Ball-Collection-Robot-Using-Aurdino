#include <Servo.h>

const int motor1In1 = 3;
const int motor1In2 = 4;
const int motor2In3 = 5;
const int motor2In4 = 8;
const int motor1Enable = 10;
const int motor2Enable = 11;

const int irSensorPin = 2;
const int trigPin = 6;
const int echoPin = 7;

const int gripperServoPin = 9;
Servo gripperServo;

void setup() {
  pinMode(motor1In1, OUTPUT);
  pinMode(motor1In2, OUTPUT);
  pinMode(motor2In3, OUTPUT);
  pinMode(motor2In4, OUTPUT);
  pinMode(motor1Enable, OUTPUT);
  pinMode(motor2Enable, OUTPUT);

  pinMode(irSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gripperServo.attach(gripperServoPin);
  openGripper();

  Serial.begin(9600);
}

void openGripper() {
  gripperServo.write(90);
  delay(1000);
}

void closeGripper() {
  gripperServo.write(0);
  delay(1000);
}

void moveLeftMotorBackward() {
  digitalWrite(motor1In1, LOW);
  digitalWrite(motor1In2, HIGH);
  analogWrite(motor1Enable, 255);
}

void stopMotors() {
  analogWrite(motor1Enable, 0);
  analogWrite(motor2Enable, 0);
}

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034) / 2;
}

void moveForward() {
  digitalWrite(motor1In1, HIGH);
  digitalWrite(motor1In2, LOW);
  digitalWrite(motor2In3, HIGH);
  digitalWrite(motor2In4, LOW);
  analogWrite(motor1Enable, 255);
  analogWrite(motor2Enable, 255);
}

void loop() {
  openGripper();
  moveLeftMotorBackward();

  while (digitalRead(irSensorPin) == LOW) {
  }
  stopMotors();

  delay(1000);

  long distance = measureDistance();
  while (distance > 5) {
    moveForward();
    distance = measureDistance();
  }
  stopMotors();

  closeGripper();

  while (true) {
  }
}
