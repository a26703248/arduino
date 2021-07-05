/*
  藍芽收發程式 HC-05(從端)
  接線方式:
  RXD: D6
  TXD: D5
  VCC: 5V
  GND: GND
*/
#include <SoftwareSerial.h>
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //0x27或0x3F 定義 I2C 的 Address 位置 (PCF8574T)
#define BUTTON_PIN 7

SoftwareSerial BTserial(5, 6);// (RX, TX)
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);


void setup() {
  Serial.begin(9600);   // 0, 1 接腳
  BTserial.begin(9600); // 5, 6 接腳 (基本頻率38400,9600也可以)
  pinMode(BUTTON_PIN, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("RX:");
  lcd.setCursor(0, 1);
  lcd.print("TX:");
  lcd.setCursor(7, 0);
  lcd.print("Ser:");
}
void loop() {
  //檢查是否有資料透過藍芽傳進來
  if(BTserial.available()){
    String data = BTserial.readString();// 讀取藍芽資料
    Serial.print("BTserial: ");
    Serial.println(data);
    lcd.setCursor(3, 0);
    lcd.print("      ");
    lcd.setCursor(3, 0);
    lcd.print(data);
  }
  //透過藍芽將資料送給 App
  if(digitalRead(BUTTON_PIN) == LOW){
    int n = random(0, 100);
    BTserial.println(n);
    Serial.print("Serial Sand: ");
    Serial.println(n);
    lcd.setCursor(3, 1);
    lcd.print("      ");
    lcd.setCursor(3, 1);
    lcd.print(n);
    delay(300);
  }
  //檢查是否有資料透過USB傳進來
  if(Serial.available()){
    String data = Serial.readString();// 讀取 USB 資料
    Serial.print("Serial Receive: ");
    Serial.println(data);
    lcd.setCursor(12, 0);
    lcd.print("      ");
    lcd.setCursor(12, 0);
    lcd.print(data);
  }
  delay(200);
}
