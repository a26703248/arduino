#include <MatrixMini.h>

int carSpeed = 30;//車速

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
}
void loop() {
  play();//呼叫play()函式
}
void play() {
  while (true) {//無限迴圈
    int right_Value = IRS_Right();//右邊紅外線感測器數值
    int left_Value = IRS_Left();//左邊紅外線感測器數值
    if (right_Value == 0 && left_Value == 0) {//如果兩側都無偵測到黑線,就向前走
      go();
    } else if (right_Value == 1 && left_Value == 1) {//如果到達貨物區時,將貨物抬起
      RC1();
    } else if (right_Value == 1) {//如果右側偵測到黑線,向左行駛
      turnLeft();
    } else if (left_Value == 1) {//如果左側偵測到黑線,向右行駛
      turnRight();
    }
  }
}
void RC1() {
  Mini.RC2.set(40);
  delay(100);
  go();
  delay(200);
  Mini.RC2.set(20);
  delay(100);
  turnBack();
  delay(300);
  turn();//原地迴轉
  delay(1500);
}
void go() {//前進函式
  Mini.M1.set(carSpeed);
  Mini.M2.set(carSpeed);
}
void down() {//停止函式
  Mini.M1.set(0);
  Mini.M2.set(0);
}
void turnRight() {//向右函式
  Mini.M1.set(carSpeed);
  Mini.M2.set(0);
}
void turnLeft() {//向左函式
  Mini.M1.set(0);
  Mini.M2.set(carSpeed);
}
void turnBack() {//向後函式
  Mini.M1.set(-carSpeed);
  Mini.M2.set(-carSpeed);
}
void turn() {//原地迴轉函式
  Mini.M1.set(carSpeed);
  Mini.M2.set(-carSpeed);
}
int IRS_Right() {
  int i = Mini.A1.getANG();//取得右側紅外線感測器
  Serial.println("A1: " + (String)i);
  if (i > 100) {//如果右側紅外線感測器偵測到黑線,回傳 1
    return 1;
  }
  return 0;
}
int IRS_Left() {
  int i = Mini.A2.getANG();//取得左側紅外線感測器
  Serial.println("A2: " + (String)i);
  if (i > 100) {//如果左側紅外線感測器偵測到黑線,回傳 1
    return 1;
  }
  return 0;
}
