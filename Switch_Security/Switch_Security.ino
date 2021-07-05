/*
  1.Button
  在防盜模式啟動(ON)/關閉(OFF)
  2.LCD 顯示現在
  Security: ON/OFF
  3.RED LED
  在防盜模式啟動(ON)= HIGH
  在防盜模式啟動(OFF)= LOW
  4.Switch
  在防盜模式啟動(ON)+ Switch(偵測門開) = Buzeer 響起
  按下 Button關閉防盜模式, Buzeer 停止響
  在防盜模式啟動(ON)+ Switch(一樣可以進行偵測) = Buzeer 不響
*/
#include <Timer.h>
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SWITCH_PIN     13
#define BUZEER_PIN     8
#define LED_PIN        3
#define BUTTON_PIN     9
#define I2C_ADDR       0x27 

int switchValue;
int buzeer = 0;
int start = 0;
int perButtonState;

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);

Timer time1, time2, time3, time4;

void setup() {
  delay(100);
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(BUZEER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lcd.begin(16, 2);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Security:");
  lcd.setCursor(0,1);
  lcd.print("Switch:");

  time1.every(50, Button);
  time2.every(100, LED);
  time3.every(300, Switch);
  time4.every(300, printLCD);
  
  Serial.println("Ready");
}

void loop() {
  time1.update();
  time2.update();
  time3.update();
  time4.update();
}
void printLCD(){
  lcd.setCursor(11,0);
  lcd.print("   ");
  lcd.setCursor(11,0);
  lcd.print(start == 0? "Off":"On");
  lcd.setCursor(8,1);
  lcd.print("   ");
  lcd.setCursor(8,1);
  lcd.print(switchValue == 0? "CLOSE":"OPEN");
}
void LED() {
  if (start == 1) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
void Button() {
  int curButtonState = digitalRead(BUTTON_PIN);
  if (curButtonState != perButtonState) {
    if (curButtonState == LOW) {
      start ++;
    }
    perButtonState = curButtonState;
  }
  if (start > 1) {
    start = 0;
  }
}
void Switch() {
  switchValue = digitalRead(SWITCH_PIN);
  if (start == 1) {
    Serial.print("switchValue: ");
    Serial.println(switchValue);
    if (switchValue == 1) {
      tone(BUZEER_PIN, 2000);
    }
    delay(1000);
  }
  if(start == 0){
    noTone(BUZEER_PIN);
  }
}
