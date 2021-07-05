/*
將CDS與DHT11(溫溼度)都可以顯示在Tube上
可以利用Timer 來實現
 */
#include "Timer.h"
#include "DHT.h"
#include <TridentTD_7Segs74HC595.h>


#define DHT_TYPE DHT11
#define SCLK        4
#define RCLK        5
#define DIO         6

const int DHT_PIN     = 2;
const float DHT_RANGE = 2;
const int CDS_PIN     = A3;
const int LED_PIN     = 7;
const int BUZEER_PIN  = 8;
const int BUTTON_PIN  = 9;

DHT dht(DHT_PIN, DHT_TYPE);
TridentTD_7Segs74HC595  tube( SCLK, RCLK, DIO);
Timer timer;// 宣告timer物件

float h = 0; //濕度
float t = 0; // 溫度 true : 華氏, false(預設):攝氏
int cdsValue = 0;
int cdcValuesThreshold = 200;
int perButtonState = 0;// 按鈕狀態直
int at = 0;

void setup() {
  delay(100);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZEER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  dht.begin();//啟動 dht
  tube.init(); //啟動 tube 
  tube.setTextScroll("RADEY...");
  //配置排程
  timer.every(1000, setDHT); // 每1000ms取得最新溫濕度
  timer.every(100, updataCdcValuesThreshold);// 檢查門檻值是否有異動
  timer.every(100, checkLight);// 檢查門檻值是否有異動
  timer.every(500, light); // 每500ms檢查明亮度
  timer.every(1000, playScroll);// 每1000ms執行一次跑馬燈
  Serial.println("Ready");
}

void loop() {
  button();
  timer.update();
}

//取得新溫溼度
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

void playScroll(){
  Serial.println(at);
  switch(at){
    case 0:
      tube.setText("H"+String(h, 1));
      break;
    case 1:
      t = t - 2;
      tube.setText("T"+String(t, 1)+"C");
      break;
    case 2:
      tube.setText("L"+((String)cdsValue));
      break;
  }
  if(at > 2){
    at = 0;
  }
}

void light(){
  cdsValue = analogRead(CDS_PIN); //  0~1023
}
void checkLight(){
  if (cdsValue < cdcValuesThreshold) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
void updataCdcValuesThreshold(){
  if(Serial.available() > 0){
    String str = Serial.readString();
    str.trim();
    cdcValuesThreshold = str.toInt();
    Serial.println(cdcValuesThreshold);
  }
}
void buzeer(){
  tone(BUZEER_PIN, 494, 100);
}
void button(){
  int curButtonState = digitalRead(BUTTON_PIN);
  Serial.println(at);
  if(curButtonState != perButtonState){
    if(curButtonState == LOW){
      at++;
      buzeer();
    }
    perButtonState = curButtonState;
  }
}
