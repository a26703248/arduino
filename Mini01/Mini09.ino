#include <MatrixMini.h>

int carSpeed = 40;
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
    int i = Mini.A1.getANG();//416~420紅 900~930深藍
    int d = Mini.D3.US.get();
    Serial.println(i);
    if (d < 10) {
      shortRGB('r', 255);
      Mini.M1.set(carSpeed);
      Mini.M2.set(-carSpeed);
      i = Mini.A1.getANG();
      Turn(i, Mid);
    } else {
      shortRGB('g', 255);
      if (i > Mid) {
        TurnRight();
        delay(10);
      } else {
        TurnLeft();
        delay(10);
      }
    }

  }
}

void loop() {
}
void GO() {
  Mini.M1.set(carSpeed);//右邊
  Mini.M2.set(carSpeed);//左邊
}
void TurnRight() {
  Mini.M1.set(0);
  Mini.M2.set(carSpeed);
}
void TurnLeft() {
  Mini.M1.set(carSpeed);
  Mini.M2.set(0);
}
void TurnBack() {
  Mini.M1.set(-carSpeed);
  Mini.M2.set(-carSpeed);
}
void Turn(int i, int num) {
  while (i > num) {
    i = Mini.A1.getANG();
    Mini.M1.set(carSpeed);
    Mini.M2.set(-carSpeed);
  }
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
void shortRGB(char l, int i) {
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
