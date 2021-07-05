#include <DigitalTube.h>
DigitalTube dis(4, 5, 6);
const int v_pin = A0;
/*
透過PC輸入STOP顯示STOP
透過PC輸入1234顯示1234
透過PC輸入12.34顯示12.34
透過PC輸入123.4顯示123.4
 */
void setup() {
  delay(10);
  Serial.begin(9600);
  dis.begin();
  Serial.println("Ready");
}

void loop() {
  play();
}
void play(){
  if(Serial.available()>0){
    String str =Serial.readString();
    char a = str.charAt(0);
    char b = str.charAt(1);
    char c = str.charAt(2);
    char d = str.charAt(3);
    char e = str.charAt(4);
    int doc = str.indexOf('.');
    
    switch(doc){
      case -1:
        dis.show(a, b, c, d);
        break;
      case 0:
        dis.show(10+0, b, c, d);
        break;
      case 1:
        dis.show(a-48+10, c, d, e);
        break;
      case 2:
        dis.show(a, b-48+10, d, e);
        break;
      case 3:
        dis.show(a, b, c-48+10, e);
        break;
      case 4:
        dis.show(a, b, c, d-48+10);
        break;
      default:
        dis.show('E', 'R', 'R', ' ');
    }
    
  }
  delay(500);
}
