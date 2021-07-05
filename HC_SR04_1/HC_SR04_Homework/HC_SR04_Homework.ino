/*
  偵測距離在 10cm~5cm 之間亮紅燈, 發出長音bee~ bee~
  偵測距離 <5cm 亮黃燈, 短音bee~ bee~
  偵測距離 >10cm 不亮燈, 不發聲
  距離顯示在DigitalTube
*/
#include <TridentTD_7Segs74HC595.h>
#include <Ultrasonic.h>

#define SCLK 4
#define RCLK 5
#define DIO  6

const int LED_YELLOW_PIN = 10;
const int LED_RED_PIN    = 13;
const int BUZEER_PIN     = 8;
const int CDS_PIN        = A3;

int stat = 0;
int duration = 0;

Ultrasonic ultrasonic(12, 11);
TridentTD_7Segs74HC595  tube(SCLK, RCLK, DIO);

void setup() {
  delay(100);
  Serial.begin(9600);
  tube.init();
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUZEER_PIN, OUTPUT);
  Serial.println("Ready");
}

void loop() {
  play();
  DigitalTube();
}
void play(){
  HCSR();
  if(stat == 1){
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_RED_PIN, HIGH);
    tone(BUZEER_PIN, 880, 100);
  }else if(stat == 2){
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, HIGH);
    tone(BUZEER_PIN, 880, 100);
  }else{
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_RED_PIN, LOW);
    tone(BUZEER_PIN, LOW);
  }
}
void HCSR(){
  duration = ultrasonic.read();
  Serial.print("duration: ");
  Serial.println(duration);
  if(duration < 5){
    stat = 1;
  }else if(duration <= 10){
    stat = 2;
  }
}
void DigitalTube(){
  if (isnan(duration)) return;
  tube.setText(String(duration));
}
