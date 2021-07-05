const int LED_BLUE_PIN  = 9;
const int LED_RED_PIN   = 10;
const int LED_GREEN_PIN = 11;
const int DELAY         = 500;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);

  Serial.print("R: ");
  Serial.print(r);
  Serial.print("G: ");
  Serial.print(g);
  Serial.print("B: ");
  Serial.println(b);

  analogWrite(LED_RED_PIN, r);
  analogWrite(LED_GREEN_PIN, g);
  analogWrite(LED_BLUE_PIN, b);
  delay(DELAY);

}
