const int LED_PIN = 9;
const int DELAY = 15;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, 0);//不亮
  delay(1000);
  analogWrite(LED_PIN, 80);//亮一半
  delay(1000);
  analogWrite(LED_PIN, 255);//全亮
  delay(1000);
}
