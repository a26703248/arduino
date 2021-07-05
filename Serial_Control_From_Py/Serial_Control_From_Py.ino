/*
R : 1 -> D2
G : 2 -> D3
S : 4 -> D4
Python 傳送指定數值可以控制設備
傳送過來的值要顯示在 LCD 上
*/
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define I2C_ADDR 0x27 //0x27或0x3F 定義 I2C 的 Address 位置 (PCF8574T)
#define LED_RED_PIN    2
#define LED_GREEN_PIN  3
#define SER_PIN        4

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);
Servo svo;
SoftwareSerial BTserial(5, 6);

char Py = ' ';
int user = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  svo.attach(SER_PIN);
  svo.write(0);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Python:");
}
void loop() {
  scanner();
}
void scanner(){
  if(Serial.available()){
    Py = BTserial.read();
    if(Py != '#'){
      user =((int)Py)-48;
      lcd.setCursor(7, 0);
      lcd.println(" ");
      lcd.setCursor(7, 0);
      lcd.println((String)user);
    }    
    equal();
  }
}
void equal(){
  bool r = (user & 1) > 0;
  bool g = (user & 2) > 0;
  bool s = (user & 4) > 0;
  Serial.print(r);
  Serial.print(g);
  Serial.println(s);
  if(r == 1 && g == 0 && s == 0){//001 -> 1
    device(1,0,0);
  }else if(r == 0 && g == 1 && s == 0){//010 -> 2
    device(0,1,0);
  }else if(r == 0 && g == 0 && s == 1){//100 -> 4
    device(0,0,1);
  }else if(r == 1 && g == 1 && s == 1){//111 -> 7
    device(1,1,1);
  }else if(r == 1 && g == 1 && s == 0){//110 -> 6
    device(1,1,0);
  }else if(r == 1 && g == 0 && s == 1){//101 -> 5
    device(1,0,1);
  }else if(r == 0 && g == 1 && s == 1){//011 -> 3
    device(0,1,1);
  }else{// 000 -> 0
    device(0,0,0);
  }
}
void device(bool r, bool g, bool s){
  if(r){
    digitalWrite(LED_RED_PIN, HIGH);
  }else{
    digitalWrite(LED_RED_PIN, LOW);
  }
  if(g){
    digitalWrite(LED_GREEN_PIN, HIGH);
  }else{
    digitalWrite(LED_GREEN_PIN, LOW);
  }
  if(s){
    svo.write(90);
  }else{
    svo.write(0);
  }
}
