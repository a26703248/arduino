#include <MatrixMini.h>
void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
  
}

void loop() {
  Serial.println(Mini.A1.getANG());
  delay(500);
}
