#define SWITCH_PIN 13
#define BUZEER_PIN 8

int switchValue;
int buzeer = 0;

void setup() {
  delay(10);
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(BUZEER_PIN, OUTPUT);
  Serial.println("Ready");

}

void loop() {
  switchValue = digitalRead(SWITCH_PIN);
  Serial.print("switchValue: ");
  Serial.println(switchValue);
  if(switchValue == 1){
    tone(BUZEER_PIN, 2000);
  }else{
    noTone(BUZEER_PIN);
  }
  delay(1000);
}
