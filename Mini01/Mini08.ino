#include <MatrixMini.h>
void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
}

void loop() {
  while (true) {
    Mini.RC2.set(0);
    delay(1000);
    Mini.RC2.set(90);
    delay(1000);
    Mini.RC2.set(0);
  }
}
