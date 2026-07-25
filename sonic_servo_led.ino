#include <Servo.h>

Servo servo;

const int trigPin = 4;
const int echoPin = 5;

const int greenLED = 2;
const int redLED = 3;

void setup() {

  servo.attach(8);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  servo.write(90);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}

long getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  return duration * 0.034 / 2;
}

void loop() {

  long distance = getDistance();

  if (distance <= 10) {

    servo.write(180);

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

  } else {

    servo.write(90);

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(100);
}