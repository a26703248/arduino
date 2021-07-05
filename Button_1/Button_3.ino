const int BUTTON_PIN = 9;
const int LED_PIN = 7;

//LOW = 0, HIGH = 1

int ledState = 0;//LED開/關狀態值, ledState = 1(開),0(關)
int perButtonState = 0;//前一次狀態


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  
  int curButtonState = digitalRead(BUTTON_PIN);//現在狀態值
  Serial.println(ledState);
  
  if(curButtonState != perButtonState){
    if(curButtonState == LOW){
      ledState = ledState == 0? 1 : 0;
    }
    perButtonState = curButtonState;
  }

  if (ledState == 1) {
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
