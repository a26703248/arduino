#include <MatrixMini.h>

unsigned long lastTime;
unsigned long nowTime;
const long INTERVAL = 1000;
int i = 0 ;

int c = 0;
char a = ' ';
int b = 0;

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
  randomSeed(analogRead(0));
  lastTime = millis();
}

void loop() {
  nowTime = millis();

  if (nowTime - lastTime >= INTERVAL) {
    lastTime = nowTime;
    c = random(1, 4);
    if (c != b) {
      switch (c) {
        case 1:
          a = 'r';
          break;
        case 2:
          a = 'g';
          break;
        case 3:
          a = 'b';
          break;
      }
      longRGB(a, 255);
    }
    b = c;
  }
}

void longRGB(char l, int i) {
  if (l == 'R' || l == 'r') {
    Mini.RGB1.setRGB(i, 0, 0);
    Mini.RGB2.setRGB(i, 0, 0);
  } else if (l == 'G' || l == 'g') {
    Mini.RGB1.setRGB(0, i, 0);
    Mini.RGB2.setRGB(0, i, 0);
  } else if (l == 'B' || l == 'b') {
    Mini.RGB1.setRGB(0, 0, i);
    Mini.RGB2.setRGB(0, 0, i);
  }
}

void shortRGB(char l, int i) {
  if (l == 'R' || l == 'r') {
    Mini.RGB1.setRGB(i, 0, 0);
    Mini.RGB2.setRGB(i, 0, 0);
    delay(50);
    Mini.RGB1.setRGB(0, 0, 0);
    Mini.RGB2.setRGB(0, 0, 0);
  } else if (l == 'G' || l == 'g') {
    Mini.RGB1.setRGB(0, i, 0);
    Mini.RGB2.setRGB(0, i, 0);
    delay(50);
    Mini.RGB1.setRGB(0, 0, 0);
    Mini.RGB2.setRGB(0, 0, 0);
  } else if (l == 'B' || l == 'b') {
    Mini.RGB1.setRGB(0, 0, i);
    Mini.RGB2.setRGB(0, 0, i);
    delay(50);
    Mini.RGB1.setRGB(0, 0, 0);
    Mini.RGB2.setRGB(0, 0, 0);
  }
}
