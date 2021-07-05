const int LED_BLUE_PIN  = 9;
const int LED_RED_PIN   = 10;
const int LED_GREEN_PIN = 11;
const int BUTTON_PIN    = 7;
const int DELAY         = 100;
const int Long          = 10;

int count = 0;
int rgbcolor = 1;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

}

void loop() {
  Serial.println(digitalRead(BUTTON_PIN));
  Serial.println(count);
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (count == 0) {
      analogWrite(LED_RED_PIN, rgbcolor % 3 == 1 ? 255 : 0);
      analogWrite(LED_GREEN_PIN, rgbcolor % 3 == 1 ? 255 : 0);
      analogWrite(LED_BLUE_PIN, rgbcolor % 3 == 1 ? 255 : 0);
      rgbcolor++;
    }
    count++;
  }
  if (count >= Long) {
    analogWrite(LED_RED_PIN, 255);
    analogWrite(LED_GREEN_PIN, 255);
    analogWrite(LED_BLUE_PIN, 255);
  }
  if(count >= Long && digitalRead(BUTTON_PIN) == HIGH){
    count = 0;
  }
  if(count < Long && digitalRead(BUTTON_PIN) == HIGH){
    count = 0;
  }
  Serial.print("count: ");
  Serial.println(count);
  delay(DELAY);
}
