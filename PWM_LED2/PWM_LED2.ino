const int LED_PIN = 9;
const int DELAY = 15;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}
//呼吸燈
void loop() {
  for(int i = 0; i < 256; i++){
    analogWrite(LED_PIN, i);
    delay(DELAY);
  }
  for(int i = 255; i >= 0; i--){
    analogWrite(LED_PIN, i);
    delay(DELAY);
  }
}
