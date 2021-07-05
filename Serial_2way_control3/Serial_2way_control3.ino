//若 arduino 收到 "+" 每次 +50
//若 arduino 收到 "-" 每次 -50
//若 arduino 收到 "r" 字元表示還原 200ms 的速度

int i = 1;
int s = 200;
int r = 50;
boolean play = true;//控制是否要顯示 i 值的變數
void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  i++;
  Serial.println(i);
  
  if(Serial.available() > 0){
    char c = Serial.read();
    /*if(c == '+'){
      s += r;
      Serial.print("現在速度: ");
      Serial.println(s);
    }else if(c == '-'){
      s -= r;
      Serial.print("現在速度: ");
      Serial.println(s);
    }else if(c == 'r'){
      s = 200;
      Serial.print("現在速度: ");
      Serial.println(s);
    }*/
    
    switch(c){
      case '+':
        if(s > 50){
          s -= r;
        }
        Serial.print("現在速度: ");
        Serial.println(s);
        break;
      case '-':
        if(s < 1000){
          s += r;
        }
        Serial.print("現在速度: ");
        Serial.println(s);
        break;
      case 'r':
        s=200;
        Serial.print("現在速度: ");
        Serial.println(s);
        break;
    }
  }
  delay(s);
}
