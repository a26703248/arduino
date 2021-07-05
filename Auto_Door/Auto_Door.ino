#include <Servo.h>
#define SERVO_PIN  6
#define SENSOR_PIN 5
#define RED_PIN    4
#define GREEN_PIN  3

Servo myservo;
int initDegree = 0;
int maxDegree = 90;
int curDegree = initDegree;

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  myservo.write(initDegree);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  int moving = digitalRead(SENSOR_PIN);
  if (moving) {
    openDoor();
  } else {
    closeDoor();
  }
  Serial.println(moving);
  Serial.println(curDegree);
  delay(100);
}
void openDoor() {
  if (curDegree == initDegree) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    for (; curDegree <= maxDegree; curDegree += 5) {
      myservo.write(curDegree);
      delay(10);
    }
  }
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}
void closeDoor() {
  if (curDegree == maxDegree) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    for (; curDegree >= initDegree; curDegree -= 5) {
      myservo.write(curDegree);
      delay(10);
    }
  }
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}
