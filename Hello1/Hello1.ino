int i = 0;
void setup() {
  Serial.begin(9600);  //傳輸速率 bps
  Serial.println("call setup....");
}

void loop() {
  ++i;
  if(i % 2 == 0){
    Serial.print("call loop: ");
    Serial.println(i);
  }
  delay(500);
}
