//若 arduino 收到 "on" 表示一直印出 i 的值
//若 arduino 收到 "off" 表示停止印出 i 的值
int i = 1;
boolean play = false;//控制是否要顯示 i 值的變數
void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  i++;
  
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c == '1'){
      play = true;
    }else if(c == '2'){
      play = false;
    }
  }
  if(play){//play==true
    Serial.println(i);
  }
  delay(1000);
}
