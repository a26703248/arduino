#include "DHT.h"
#define DHT_TYPE DHT11
const int DHT_PIN = 2;
const float DHT_RANGE = 2; 
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  delay(100);
  Serial.begin(9600);
  dht.begin();//啟動
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
  delay(1000);
  
}
