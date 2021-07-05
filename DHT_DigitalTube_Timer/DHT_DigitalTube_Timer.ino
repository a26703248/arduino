#include "Timer.h"
#include "DHT.h"
#include <TridentTD_7Segs74HC595.h>

#define DHT_TYPE DHT11
#define SCLK        4
#define RCLK        5
#define DIO         6

const int DHT_PIN = 2;
const float DHT_RANGE = 2;

DHT dht(DHT_PIN, DHT_TYPE);
TridentTD_7Segs74HC595  tube( SCLK, RCLK, DIO);
Timer timer;// 宣告timer物件

float h = 0; //濕度
float t = 0; // 溫度 true : 華氏, false(預設):攝氏

void setup() {
  delay(100);
  Serial.begin(9600);
  dht.begin();//啟動 dht
  tube.init(); //啟動 tube 
  tube.setTextScroll("RADEY...");
  //配置排程
  timer.every(1000, setDHT); // 每1000ms取得最新溫濕度
  timer.every(1000, playScroll); // 每1000ms執行一次跑馬燈
  
  Serial.println("Ready");
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
  Serial.print("H:");
  Serial.print(h);
  Serial.print("%T");
  Serial.print(t);
  Serial.println("*C");
}

void playScroll(){
  tube.setTextScroll("H"+String(h, 1)+" "+String(t, 1)+"C");
}
void loop() {
  timer.update();
}
