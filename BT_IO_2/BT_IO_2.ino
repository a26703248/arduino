#include <SoftwareSerial.h>
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //0x27或0x3F 定義 I2C 的 Address 位置 (PCF8574T)
#define BUTTON_PIN 7

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);


void setup() {
  Serial.begin(9600);   // 0, 1 接腳
  pinMode(BUTTON_PIN, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("RX:");
  lcd.setCursor(0, 1);
  lcd.print("TX:");
}
void loop() {
  //檢查是否有資料透過(RX:0, TX:1)傳進來
  if(Serial.available()){
    String data = Serial.readString();// 讀取藍芽資料
    lcd.setCursor(3, 0);
    lcd.print("      ");
    lcd.setCursor(3, 0);
    lcd.print(data);
  }
  //透過(RX:0, TX:1)將資料傳出
  if(digitalRead(BUTTON_PIN) == LOW){
    int n = random(0, 100);
    lcd.setCursor(3, 1);
    lcd.print("      ");
    lcd.setCursor(3, 1);
    lcd.print(n);
    delay(300);
  }
  delay(200);
}
