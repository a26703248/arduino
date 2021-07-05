#include <DigitalTube.h>
DigitalTube dis(4, 5, 6);
int i = 9999;

void setup() {
  Serial.begin(9600);
  dis.begin();
  Serial.print("Ready");
}

void loop() {
  //Show Test
  //Hello 跑馬燈
  dis.show(' ', ' ', ' ', ' ');
  delay(500);
  dis.show(' ', ' ', ' ', 'F');
  delay(500);
  dis.show(' ', ' ', 'F', 'U');
  delay(500);
  dis.show(' ', 'F', 'U', 'C');
  delay(500);
  dis.show('F', 'U', 'C', 'K');
  delay(500);
  dis.show('U', 'C', 'K', ' ');
  delay(500);
  dis.show('C', 'K', ' ', ' ');
  delay(500);
  dis.show('K', ' ', ' ', ' ');
  delay(500);
  dis.show(' ', ' ', ' ', ' ');
  delay(500);

  for(int i = 9; i > 0; i--){
    dis.print(i);
    delay(500);
  }
  dis.show('S', 'T', 'O', 'P');
  delay(500);
  dis.show(' ', ' ', ' ', ' ');
  delay(500);
  dis.show('S', 'T', 'O', 'P');
  delay(500);
  dis.show(' ', ' ', ' ', ' ');
  delay(500);
  dis.show('S', 'T', 'O', 'P');
  delay(500);
}
