/*
接線方式
SIG : A4
VCC : 5V
GND : GND
 */
#include <DigitalTube.h>
const int CDS_PIN = A3;
DigitalTube dis(4, 5, 6);


void setup() {
  delay(100);
  Serial.begin(9600);
  dis.begin();
}

void loop() {
  String cdsValue =(String)(analogRead(CDS_PIN));//  0~1023
  dis.show('0' ,cdsValue.charAt(0) ,cdsValue.charAt(1) ,cdsValue.charAt(2));
  Serial.println(cdsValue);
  delay(500);
}
