#include <Servo.h>

#define SERVO_PIN 6

Servo myservo;// 建立 Servo 物件
int initDegree = 0;
int maxDegree = 90;

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);// 設定 Servo 腳位
  myservo.write(180);// 0~180 
}

void loop() {
  for(int i=0;i<maxDegree;i+=5){
    myservo.write(i);
    delay(10);
  }
  delay(3000);
  for(int i=maxDegree;i>initDegree;i-=5){
    myservo.write(i);
    delay(10);
  }
  delay(3000);
}
