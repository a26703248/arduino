int e = 5;
int line = 0;
void setup() {
  delay(100);
  Serial.begin(9600);
  Serial.println("Ready");
  for (int i = 0; i <= e; i++) {
    if (i < ((e / 2) + 1)) {
      for (int j = e; j > i; j--) {
        Serial.print(' ');
      }
      line++;
      for (int j = 0 ; j < line; j++) {
        Serial.print('*');
        Serial.print(' ');
      }
    }else{
      for (int j = 0; j < i+1; j++) {
        Serial.print(' ');
      }
      line--;
      for (int j = 0 ; j < line; j++) {
        Serial.print('*');
        Serial.print(' ');
      }
    }


    Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
