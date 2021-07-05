#include <MatrixMini.h>
#include <Timer.h>

int A1Stat = 0;//紅外線感測
int carSpeed = 50;//M1左邊,M2右邊

Timer time1;

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
  time1.every(100, A1sonar);
}

void loop() {
  Serial.println(A1Stat);
  time1.update();
}
void play() {
  
}
void GO() {
  Mini.M1.set(carSpeed);
  Mini.M2.set(carSpeed);
}
void TurnRight() {
  Mini.M1.set(-carSpeed);
  Mini.M2.set(carSpeed);
}
void TurnLeft() {
  Mini.M1.set(carSpeed);
  Mini.M2.set(-carSpeed);
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
void A1sonar() {//紅外線
  A1Stat = Mini.A1.getANG();
  
}
