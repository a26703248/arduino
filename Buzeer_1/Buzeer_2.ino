const int BUZEER_PIN = 8;
const int DELAY = 500;
int frequence[] = {262, 294, 330, 349, 392, 440, 494, 523, };
void setup() {
  Serial.begin(9600);
  pinMode(BUZEER_PIN, OUTPUT);

  for (int i = 0; i < 7; i++) {
    tone(BUZEER_PIN, frequence[i], 500);
    delay(DELAY);
  }
}

void loop() {
}
