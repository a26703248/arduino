#include <dht.h>

#define DHT_PIN A1 // dht類比腳位 A1
dht DHT;

void setup() {
  delay(10);
  Serial.begin(9600);
  DHT.read11(DHT_PIN);
  Serial.println("Ready");
}

void loop() {
  // 讀取溫溼度
  float h = DHT.humidity;
  float t = DHT.temperature;
  Serial.print("H: ");
  Serial.print(h, 2);
  Serial.print("%, T: ");
  Serial.print(t, 2);
  Serial.println("*C");
  delay(1000);
}
