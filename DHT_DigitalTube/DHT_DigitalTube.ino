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
void setup() {
  delay(100);
  Serial.begin(9600);
  dht.begin();//啟動 dht
  tube.init(); //啟動 tube 
  tube.setTextScroll("RADEY...");
  Serial.println("Ready");
}

void loop() {
  float h = dht.readHumidity();//濕度
  float t = dht.readTemperature(); // 溫度 true : 華氏, false(預設):攝氏
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

  tube.setTextScroll("H"+String(h, 1)+" "+String(t, 1)+"C");
  
  delay(1000);
}
