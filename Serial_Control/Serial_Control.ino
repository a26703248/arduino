/*SGR  R   G   S  RG  GS  RS
  000 001 010 100 011 110 101
   0   1   2   4   3   6   5
*/ 

int control = 7;

void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()){
    int n = Serial.read() - 48;
    if(n >= 0){
      /*011 = 3
      011 & 001 = 001
      110 = 6
      110 & 001 = 000
      */
      Serial.println((n & 1) > 0? "R on":"R off");
      Serial.println((n & 2) > 0? "G on":"G off");
      Serial.println((n & 4) > 0? "S on":"S off");
    }
  }
}
