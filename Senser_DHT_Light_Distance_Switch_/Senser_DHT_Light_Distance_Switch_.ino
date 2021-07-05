#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Timer.h"
#include "DHT.h"
#include <Ultrasonic.h>

#define I2C_ADDR   0x27 //0x27或0x3F 定義 I2C 的 Address 位置 (PCF8574T)
#define DHT_TYPE   DHT11
#define TRIG_PIN   12
#define ECHO_PIN   11
#define BUZEER_PIN 8

const int DHT_PIN     = 2;
const float DHT_RANGE = 2;
const int BUTTON_PIN  = 9;
const int CDS_PIN     = A3;

int perButtonState = 0;
float h = 0;
float t = 0;
int buttonStat = 0;
int distance = 0;
int cdsValue = 0;
int buzeerStat = 0;
char user;

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);
DHT dht(DHT_PIN, DHT_TYPE);
Timer time1, time2, time3, time4, time5, time6;
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  delay(100);
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUTTON_PIN, OUTPUT);
  lcd.begin(16, 2);
  dht.begin();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("H:");
  lcd.setCursor(9,0);
  lcd.print("L:");
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.setCursor(9,1);
  lcd.print("cm:");
  
  time1.every(100, button);
  time2.every(300, consoleInt);
  time3.every(500, setDHT);
  time4.every(1000, checkLight);
  time5.every(500, printLcd);
  
}
void loop() {
  time1.update();
  time2.update();
  time3.update();
  time4.update();
  time5.update();
}
void consoleInt(){
  if(Serial.available() > 0){
    user = Serial.read();
  }
  switch(user){
    case '1':
      detect();
      break;
  }
  user = 0;
}
void printLcd(){
  lcd.setCursor(3,0);
  lcd.print(h);
  lcd.setCursor(13,0);
  lcd.print("   ");
  lcd.setCursor(13,0);
  lcd.print(cdsValue);
  lcd.setCursor(3,1);
  lcd.print(t);
  lcd.setCursor(13,1);
  lcd.print("   ");
  lcd.setCursor(13,1);
  lcd.print(distance);
  distance = 0;
}
void setDHT(){
  h = dht.readHumidity();
  t = dht.readTemperature();
  if(isnan(h) || isnan(t)){ // nan -> not a number
    Serial.println("No dht data !!");
    delay(1000);
    return;
  }
  t = t - DHT_RANGE;
}
void button(){
  int curButtonState = digitalRead(BUTTON_PIN);
  
  if(curButtonState != perButtonState){
    if(curButtonState == LOW){
      buttonStat++;
    }
    perButtonState = curButtonState;
  }
  if(buttonStat > 1){
    buttonStat = 0;
  }
  lcdlight();
}
void lcdlight(){
  if(buttonStat == 0){
    lcd.setBacklight(LOW);
  }else{
    lcd.setBacklight(HIGH);
  }
}
void checkLight(){
  cdsValue = analogRead(CDS_PIN);
}
void detect() {
  distance = ultrasonic.read();
  if(distance < 0){
    distance = 0;
  }
}
void buzeer(){
  if(buzeerStat = 1){
    tone(BUZEER_PIN, 2000, 500);
  }else{
    noTone(BUZEER_PIN);
  }
}
