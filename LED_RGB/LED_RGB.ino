const int LED_BLUE_PIN  = 9;
const int LED_RED_PIN   = 10;
const int LED_GREEN_PIN = 11;
const int DELAY         = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
  //顯示紅色
  analogWrite(LED_RED_PIN, 255);
  analogWrite(LED_GREEN_PIN, 127);
  analogWrite(LED_BLUE_PIN, 20);
  delay(DELAY);


  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 0);
  delay(DELAY);
}
