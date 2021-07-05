int led_speed_low  = 500;
int led_speed_high = 500;
int led_pin        = 13;
int uplow          = 50;
boolean play       = false;
int p              =led_speed_high;
void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(led_pin, OUTPUT);
}

void loop() {
  readData();
  playled();
}
void readData(){
  if(Serial.available()>0){
    char c = Serial.read();
    Serial.println(c);
    switch(c){
      case '1':
        play = true;
        Serial.println("開啟");
        break;
      case '2':
        play = false;
        Serial.print("關閉");
        break;
      case '3':
        if(led_speed_low > 50 && led_speed_high > 50){
          led_speed_low -= uplow;
          led_speed_high -= uplow;
          p += uplow;
        }else{
          Serial.print("速度最快為950");
        }
        Serial.print("速度為: ");
        Serial.println(p);
        break;
      case '4':
        if(led_speed_low < 950 && led_speed_high < 950){
          led_speed_low += uplow;
          led_speed_high += uplow;
          p -= uplow;
        }else{
          Serial.println("速度最慢為50");
        }
        Serial.print("速度為: ");
        Serial.println(p);
        break;
      case '5':
        led_speed_low = 0;
        Serial.print("恆亮");
        break;
    }
  }
}
void playled(){
  if(play){
    digitalWrite(led_pin, HIGH);
    delay(led_speed_high);
    digitalWrite(led_pin, LOW);
    delay(led_speed_low);
    
  }
}
