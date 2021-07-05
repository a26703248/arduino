#include <DigitalTube.h>
DigitalTube dis(4, 5, 6);

void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.print("Ready");
}

void loop() {
  float temp = random(230, 259) / 10.0;
  int tempInt = (int)(temp*10);//234
  dis.show(tempInt/100, tempInt%100+10, tempInt%10, 'C');
  delay(500);
}
