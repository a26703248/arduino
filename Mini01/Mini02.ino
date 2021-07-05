#include <Thread.h>
#include <ThreadController.h>
#include <MatrixMini.h>

int r = 0;
int last = 0;
bool btnStat = false;

Thread timeThread1000 = Thread();
Thread timeThread1300 = Thread();
Thread timeThread500 = Thread();

ThreadController controller = ThreadController();

void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(0));
  timeThread1000.onRun(callback1000);
  timeThread1000.setInterval(1000);
  timeThread1300.onRun(callback1300);
  timeThread1300.setInterval(1300);
  timeThread500.onRun(callback500);
  timeThread500.setInterval(500);
  controller.add(&timeThread1000);
  controller.add(&timeThread1300);
  controller.add(&timeThread500);
}

void loop() {
  controller.run();
}
void callback1000(){
  Serial.println("已經過了1秒");
}
void callback1300(){
  Serial.println("已經過了1.3秒");
}
void callback500(){
  Serial.println("已經過了0.5秒");
}







void LongRGB(int i, int l) {
  switch (l) {
    case 1:
      Mini.RGB1.setRGB(i, 0, 0);
      Mini.RGB2.setRGB(i, 0, 0);
      break;
    case 2:
      Mini.RGB1.setRGB(0, i, 0);
      Mini.RGB2.setRGB(0, i, 0);
      break;
    case 3:
      Mini.RGB1.setRGB(0, 0, i);
      Mini.RGB2.setRGB(0, 0, i);
      break;

  }
}

void shortRGB(int i, int l) {
  switch (l) {
    case 1:
      Mini.RGB1.setRGB(i, 0, 0);
      Mini.RGB2.setRGB(i, 0, 0);
      break;
    case 2:
      Mini.RGB1.setRGB(0, i, 0);
      Mini.RGB2.setRGB(0, i, 0);
      break;
    case 3:
      Mini.RGB1.setRGB(0, 0, i);
      Mini.RGB2.setRGB(0, 0, i);
      break;
  }
  Mini.RGB1.setRGB(0, 0, 0);
  Mini.RGB2.setRGB(0, 0, 0);
}
