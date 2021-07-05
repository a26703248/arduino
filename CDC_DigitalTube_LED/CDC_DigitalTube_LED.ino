#include <DigitalTube.h>
const int CDS_PIN = A3;
const int LED_PIN = 7;

int cdcValuesThreshold = 500;
DigitalTube dis(4, 5, 6);

void setup() {
  delay(100);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  dis.begin();
  Serial.println("Ready");
}

void loop() {
  int cdsValue = analogRead(CDS_PIN); //  0~1023
  String temp = " ";
  if (Serial.available() > 0) {
    String temp = Serial.readString();//讀取字串
    temp.trim();//去除空白
    cdcValuesThreshold = temp.toInt();//字串轉數字
  }
  
  dis.print(cdsValue);
  if (cdsValue < cdcValuesThreshold) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(500);
}
