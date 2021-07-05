/*
接線方式:
GND : GND
DIO : 6
RCLK : 5
SCLK : 4
VCC : 5V
*/
#include <DigitalTube.h>
DigitalTube dis(4, 5, 6);
int i = 9999;

void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.print("Ready");
}

void loop() {
  //Show Test
  //Hello 跑馬燈
  dis.print(i);
  i--;
  delay(500);
}
