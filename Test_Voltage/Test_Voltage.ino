const int v_pin = A0;
//電池電量

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  int data = analogRead(v_pin); //類比資料讀取(0~1023)
  Serial.print("data= ");
  Serial.println(data);
  
  float volatge = data / 1024.0 * 5.0;//電壓換算
  Serial.print(", volatge= ");
  Serial.println(volatge);
  delay(1000);
}
