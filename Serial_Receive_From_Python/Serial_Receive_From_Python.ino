/*
1.確認資料是否傳輸成功,請查看板子上的 RX 燈號
2.請將收到的資料顯示在LCD上
*/
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //0x27或0x3F 定義 I2C 的 Address 位置 (PCF8574T)

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3,POSITIVE);

char Py = ' ';
String user = " ";

void setup() {
  Serial.begin(9600);
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
  if(Serial.available() > 0 ){
    Py = Serial.read();
    if(Py != '#'){
      user += Py;
    }else{
      lcd.setCursor(7, 0);
      lcd.print("        ");
      lcd.setCursor(7, 0);
      lcd.print(user);
      user = " ";
    }
  }
}
