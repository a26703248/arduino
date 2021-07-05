#include <MatrixMini.h>


void turn() {
  int interval = 3600; //時間控制(旋轉時間)
  int motorSpeed = 40;
  int index = 0;
  unsigned long startTime;
  unsigned long startTime1;
  unsigned long times[20]; //儲存時間
  int distances[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //儲存距離

  Mini.M1.set(motorSpeed);
  Mini.M2.set(-motorSpeed);
  startTime = millis(); //存儲初始時間
  while (true) {
    unsigned currentTime = millis(); //currentTime為當前時間
    if (currentTime - startTime1 >= interval / 20) { //將總時數切分為20個時間點
      recordTimeAndDistance(times, distances, index); //取得時間陣列、距離陣列及位置
      index++; //紀錄超音波的偵測次數
      startTime1 = currentTime; //更新計算時間
    }

    //控制車子的旋轉時間
    if (millis() - startTime >= interval) {
      Mini.M1.set(0);
      Mini.M2.set(0);
      break;
    }
  }

  //輸出測試距離與時間
  for (int i = 0; i < index; i++) {
    Serial.println(times[i]);
    Serial.println(distances[i]);
  }

}

void recordTimeAndDistance(unsigned long ts[], int ds[], int n) {
  ts[n] = millis(); //n為0~19
  int uS = Mini.D3.US.get();
  ds[n] = uS < 5 ? 200 : uS; //如果距離為0，代表超過測試距離，所以直接使用最大值
}

void btnStart() {
  while (true) {
    bool btn = 1;
    if (btn == Mini.BTN1.get()) {
      delay(50);
      while (btn == Mini.BTN1.get()) {
      }
      break;
    }
  }
}

void setup() {
  Mini.begin();
  Serial.begin(9600);
  btnStart();
  turn();

}

void loop() {
  // put your main code here, to run repeatedly:

}
