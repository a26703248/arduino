#include <DigitalTube.h>
DigitalTube dis(4, 5, 6);
const int v_pin = A0;


void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.println("Ready");
}

void loop() {
  int data = analogRead(v_pin); //類比資料讀取(0~1023)
  Serial.print("data= ");
  Serial.println(data);
  float volatge = data / 1024.0 * 5.0;//電壓換算
  Serial.print(", volatge= ");
  Serial.println(volatge);
  int temp = (int)(volatge*100);
  dis.show(' ', temp/100+10, temp/10%10, temp%10);
  delay(1000);
}
