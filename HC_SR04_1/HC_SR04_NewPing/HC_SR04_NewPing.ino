#include <NewPing.h>
const int TRIG_PIN = 12;
const int ECHO_PIN = 11;

NewPing sonar(TRIG_PIN, ECHO_PIN, 200);// 200表示最遠測具

void setup() {
  delay(10);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  //int duration = sonar.ping();
  //int cm = sonar.convert_cm(duration);
  int cm2 = sonar.ping_cm();
  //Serial.print("duration: ");
  //Serial.println(duration);
  //Serial.print("cm: ");
  //Serial.println(cm);
  Serial.print("cm2: ");
  Serial.println(cm2);
  delay(200);
}
