#include <MatrixMini.h>

int carSpeed = 30;
int Min, Max, Mid;

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");

  Min = 420;
  Max = 900;
  Mid = (Max + Min) / 2;
  int h;
  random(analogRead(1));

  while (true) {
    int i = Mini.A1.getANG();//416~420紅 900~892深藍
    Serial.println(i);
    if (i < Mid) {
      RGB('r', 255);
      Stop();
      TurnBack();
      delay(500);
      Mini.M1.set(carSpeed);
      Mini.M2.set(-carSpeed);
      delay(1700);
    }else{
      RGB('g', 255);
      GO();
    }
  }
}

void loop() {

}
void GO() {
  Mini.M1.set(carSpeed);//右邊
  Mini.M2.set(carSpeed);//左邊
}
void TurnBack() {
  Mini.M1.set(-carSpeed);
  Mini.M2.set(-carSpeed);
}
void Stop() {
  Mini.M1.set(0);
  Mini.M2.set(0);
}
void Low() {
  carSpeed -= 10;
}
void High() {
  carSpeed += 10;
}
void RGB(char l, int i) {
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
