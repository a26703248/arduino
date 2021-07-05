const int P_PIN[] = {9, 10, 11, 12, 13};
int curSpeed = 100;
int level = 10;
char c = '0', temp = ' ';
boolean stat = true, play = true;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(P_PIN[0], OUTPUT);
  pinMode(P_PIN[1], OUTPUT);
  pinMode(P_PIN[2], OUTPUT);
  pinMode(P_PIN[3], OUTPUT);
  pinMode(P_PIN[4], OUTPUT);
}

void loop() {
  play = true;
  LED();


  //1.offAll();
  //2.onAll();
  //3.antiPililed();
  //4.pililed();
  //5.randomLED();
  //6.加速
  //7.減速
}

void LED() {
  if (Serial.available() > 0) {
    if (stat) {
      c = Serial.read();
    }
    switch (c) {
      case '1':
        temp = '1';
        onAll();
        stat = true;
        break;
      case '2':
        temp = '2';
        offAll();
        stat = true;
        break;
      case '3':
        while (play) {
          temp = '3';
          antiPililed();
          c = Serial.read();
          if (Serial.available() > 0) {
            stat = false;
            play = false;
          }
        }
        break;
      case '4':
        while (play) {
          temp = '4';
          pililed();
          c = Serial.read();
          if (Serial.available() > 0) {
            stat = false;
            play = false;
          }
        }
        break;
      case '5':
        while (play) {
          temp = '5';
          randomLED();
          c = Serial.read();
          if (Serial.available() > 0) {
            stat = false;
            play = false;
          }
        }
        break;
      case '6':
        up();
        c = temp;
        break;
      case '7':
        low();
        c = temp;
        break;
    }
  }
}

//全亮
void onAll() {
  digitalWrite(P_PIN[0], HIGH);
  digitalWrite(P_PIN[1], HIGH);
  digitalWrite(P_PIN[2], HIGH);
  digitalWrite(P_PIN[3], HIGH);
  digitalWrite(P_PIN[4], HIGH);
}
//全暗
void offAll() {
  digitalWrite(P_PIN[0], LOW);
  digitalWrite(P_PIN[1], LOW);
  digitalWrite(P_PIN[2], LOW);
  digitalWrite(P_PIN[3], LOW);
  digitalWrite(P_PIN[4], LOW);
}
//反向跑馬燈
void antiPililed() {
  for (int p = P_PIN[0]; p < P_PIN[0] + 5; p++) {
    onAll();
    digitalWrite(p, LOW);
    delay(curSpeed);
  }
  for (int p = P_PIN[4]; p > P_PIN[4] - 5; p--) {
    onAll();
    digitalWrite(p, LOW);
    delay(curSpeed);
  }
}

//跑馬燈
void pililed() {
  for (int p = P_PIN[0]; p < P_PIN[0] + 5; p++) {
    offAll();
    digitalWrite(p, HIGH);
    delay(curSpeed);
  }
  for (int p = P_PIN[4]; p > P_PIN[4] - 5; p--) {
    offAll();
    digitalWrite(p, HIGH);
    delay(curSpeed);
  }
}
//亂碼燈
void randomLED() {
  int pin = random(9, 14);
  offAll();
  digitalWrite(pin, HIGH);
  delay(curSpeed);
}
//加速
void up() {
  Serial.println("0");
  if (curSpeed > 10) {
    curSpeed -= level;
  } else {
    Serial.println("已最快");
  }
}
//減速
void low() {
  if (curSpeed < 200) {
    curSpeed += level;
  } else {
    Serial.println("已最慢");
  }
}
/*測試用
  for(int p = 0; p < 2; p++){
    onAll();
    delay(100);
    offAll();
    delay(100);
  }*/
