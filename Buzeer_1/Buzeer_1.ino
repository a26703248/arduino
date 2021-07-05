const int BUZEER_PIN = 8;
const int DELAY = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(BUZEER_PIN, OUTPUT);
}

void loop() {
  tone(BUZEER_PIN, 1046);//腳位, Hz, ms
  delay(DELAY);
  
}
