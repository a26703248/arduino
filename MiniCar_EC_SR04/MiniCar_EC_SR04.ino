#include <MatrixMini.h>
#include <Timer.h>

int carSpeed = 50;
int cmd = 3;//命令 (3為停止,1為正常)
int right_SW = 0;//右邊磁簧,0為壓住 1為放開
int left_SW = 0;//左邊磁簧,0為壓住 1為放開
int D3Stat = 0;//超音波感測
bool flag = false;//伺服馬達

Timer time1, time2;


void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
  time1.every(100, D3);
  time2.every(100, ACC);
}

void loop() {
  time1.update();
  time2.update();
}
void play() {
  if(Serial.available() > 0){
    cmd = Serial.parseInt();
  }

  if (cmd == 2) {
    RGB(3);
    if(carSpeed < 50){
      High();
    }
    GO();
  } else if (cmd == 1){
    RGB(1);
    if(carSpeed <= 20){
      High();
    }else{
      TurnBack();
      delay(500);
      TurnLeft();
      delay(500);
    }
  }
}
void ACC() {
  Serial.println(cmd);
  if (cmd == 2) {
    RGB(3);
    if(carSpeed < 50){
      High();
    }
    GO();
  } else if (cmd == 1){
    RGB(1);
    Stop();
  } else if(cmd == 3){
    TurnBack();
  }
}
void GO() {
  Mini.M1.set(carSpeed);//左邊
  Mini.M2.set(carSpeed);//右邊
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
void D3() {
  D3Stat = Mini.D3.US.get();
  Serial.println(D3Stat);
  if (D3Stat < 10) { //距離小於20停止
    cmd = 3;
    Serial.println(1);
  } else if(D3Stat < 20){
    cmd = 1;
  }else {//正常行駛
    cmd = 2;
  }
  D1D2();
}

void D1D2() {
  Serial.print(right_SW);
  Serial.println(left_SW);
  right_SW = Mini.D1.get();
  left_SW = Mini.D2.get();
  if (right_SW == 0 || left_SW == 0) {
    cmd = 1;
  }
}

void RGB(int stat) {
  if (stat == 1) { //停止紅燈
    Mini.RGB1.setRGB(255, 0, 0);
    Mini.RGB2.setRGB(255, 0, 0);
  } else if (stat == 2) { //減速黃燈
    Mini.RGB1.setRGB(127, 127, 0);
    Mini.RGB2.setRGB(127, 127, 0);
  } else { //正常綠燈
    Mini.RGB1.setRGB(0, 255, 0);
    Mini.RGB2.setRGB(0, 255, 0);
  }
}
void rc1(){
  while(flag){
    Mini.RC1.set(90);
    delay(1000);
    Mini.RC1.set(0);
  }
}
