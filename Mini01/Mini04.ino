#include <MatrixMini.h>

void setup() {
  int lotto[7];
  
  int lenght = sizeof(lotto) / sizeof(lotto[7]);
  bool flag = true;
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
  randomSeed(analogRead(1));
  for (int i = 0; i < lenght; i++) {
    int r = random(0, 11);
    for (int j = i-1; j > 0; j--) {
      if (lotto[j] == r) {
        i--;
        break;
      }
    }
    lotto[i] = r;
  }
  for(int i = 0; i < lenght; i++){
    Serial.print(lotto[i]);
    Serial.print(' ');
  }
}
void loop() {

}
