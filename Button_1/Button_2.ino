const int BUTTON_ON = 9;
const int BUTTON_OFF = 7;
const int LED_PIN = 8;
//LOW = 0, HIGH = 1
int ledState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_ON, INPUT);
  pinMode(BUTTON_OFF, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  if (digitalRead(BUTTON_ON) == LOW) {
    ledState = 1;
    Serial.println("ON");
  }

  if (digitalRead(BUTTON_OFF) == LOW) {
    ledState = 0;
    Serial.println("OFF");
  }

  if (ledState == 1) {
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
}
