/*
+ = 5V
OUT = 5
- = GND

*/
#include <Servo.h>
#define SENSOR_PIN 5
#define SERVO_PIN 6
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  int moving = digitalRead(SENSOR_PIN);
  Serial.println(moving);
  if(moving){
    Serial.println("Moving");
  }
  delay(100);
}
