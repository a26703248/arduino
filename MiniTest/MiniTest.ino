#include <MatrixMini.h>


void setup() {
  delay(100);
  Serial.begin(9600);
  Mini.begin();
  Serial.println("Ready");
  /*Mini.M1.set(50);//測試直流馬達
  Mini.M2.set(50);
  delay(2000);
  Mini.M1.set(0);
  Mini.M2.set(0);*/
  /*Mini.RC2.set(0);//測試伺服馬達
  Mini.RC2.set(90);
  delay(2000);
  Mini.RC2.set(0);*/
  
}

void loop() {
  /*Serial.print("BTN1 Value:");//測試Mini Matriax arduino按鈕
  Serial.println(Mini.BTN1.get());
  Serial.print("BTN2 Value:");
  Serial.println(Mini.BTN2.get());*/
  
  /*Mini.RGB1.setRGB(255,0,0);//測試Mini Matriax arduino RGB
  Mini.RGB2.setRGB(255,0,0);
  delay(1000);
  Mini.RGB1.setRGB(0,255,0);
  Mini.RGB2.setRGB(0,255,0);
  delay(1000);
  Mini.RGB1.setRGB(0,0,255);
  Mini.RGB2.setRGB(0,0,255);
  delay(1000);*/
  
  Serial.print("cm: ");//測試超音波感測
  Serial.print(Mini.D3.US.get());
  delay(1000);
  
  /*Serial.print(Mini.D1.get());//測試磁簧感測器
  delay(1000);.*/
  
  /*Serial.println(Mini.A1.getANG());//測試紅外線感測器
  delay(500);*/
  
}
