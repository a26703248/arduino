/*
LCD i2c 接線方式
GND = GND
VCC = +5V
SDA = A4
SCL = A5
LCD 轉 I2C接線
En, Rw, Rs, d4, d5, d6, d7, BackLight_Pin
2,  1,  0,  4,  5,  6,  7, 3
*/
/*
  LiquidCrystal_I2C(uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs, 
                     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7 );
                     
  LiquidCrystal_I2C(uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs, 
                     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                     uint8_t backlighPin, t_backlighPol pol);
                     
 LiquidCrystal_I2C( uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs);
 
 LiquidCrystal_I2C(uint8_t lcd_Addr, uint8_t En, uint8_t Rw, uint8_t Rs,
                     uint8_t backlighPin, t_backlighPol pol);  
*/
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //0x27或0x3F 定義 I2C 的 Address 位置 (PCF8574T)

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  delay(100);
  Serial.begin(9600);
  lcd.begin(16, 2);
  //lcd.setBacklightPin(3,POSITIVE); //設定背光(POSITIVE 積極的)
  //lcd.bcaklight();//開啟背光
  lcd.setBacklight(HIGH); // HIGH/LOW 控制 LCD 的背光
  //清空LCD
  lcd.clear();
  // 設定cursor
  lcd.setCursor(0, 0);// (欄0-15, 列0-1)
  //印字
  lcd.print("^%$#+-|@!';[]{},");
  // 設定cursor
  lcd.setCursor(0, 1);// (欄0-15, 列0-1)
  //印字
  lcd.print("///~?>*&.");
}

void loop() {
  /*lcd.setBacklight(HIGH);
  delay(1000);
  lcd.setBacklight(LOW);
  delay(1000);*/
}
