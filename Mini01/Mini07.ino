#include <MatrixMini.h>

int right = 40;
int left = 20;

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
}

void loop() {
  go();
  delay(7000);
  left += 15;
  right += 10;
  if (right >= 100 || left >= 100) {
    right = 40;
    left = 20;
  }
}
void go () {
  Mini.M1.set(right);
  Mini.M2.set(left);
}
