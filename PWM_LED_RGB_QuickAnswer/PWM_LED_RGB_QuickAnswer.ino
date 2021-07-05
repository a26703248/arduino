#include "pitches.h"
#include "mypin.h"

int blueCount = 0;
int greenCount = 0;
boolean gameover = false;
int flag = 0;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
  pinMode(BLUE_LED_1, OUTPUT);
  pinMode(BLUE_LED_2, OUTPUT);
  pinMode(BUTTON_GREEN_PIN, INPUT);
  pinMode(BUTTON_BLUE_PIN, INPUT);

  ledAllOff();

  Serial.println("READY!");
}

void loop() {
  if (gameover == false) {
    play();

    if (greenCount == 2 || blueCount == 2) {
      gameover == true;
      if (greenCount == 2) {
        Serial.println("Green Win!");
        ledGreenOn();
        gmaeOverSong();
      }else{
        Serial.println("Blue Win!");
        ledBlueOn();
        gmaeOverSong();
      }
    }
  }
 delay(DELAY);
}

void play() {
  if (flag == 0) {
    ledAllOff();
    delay(random(1000, 500));
    ledRedOn();
    Serial.println("Go...");
    flag = 1;
  }

  if (digitalRead(BUTTON_GREEN_PIN) == LOW && flag == 1) {
    flag = 0;
    greenCount++;
    ledGreenOn();
    printScore();
    tone(Buzeer_PIN, 262, 500);
    delay(1000);
  }

  if (digitalRead(BUTTON_BLUE_PIN) == LOW && flag == 1) {
    flag = 0;
    blueCount++;
    ledBlueOn();
    printScore();
    tone(Buzeer_PIN, 262, 500);
    delay(1000);
  }
  greenTeamLed();
  blueTeamLed();
}
void printScore() {
  Serial.println("GREEN: ");
  Serial.println(greenCount);
  Serial.println("BLUE: ");
  Serial.println(blueCount);
}


void ledAllOff() {
  analogWrite(LED_BLUE_PIN, 255);
  analogWrite(LED_RED_PIN, 255);
  analogWrite(LED_GREEN_PIN, 255);
}


void ledRedOn() {
  analogWrite(LED_BLUE_PIN, 127);
  analogWrite(LED_RED_PIN, 127);
  analogWrite(LED_GREEN_PIN, 127);
}

void ledBlueOn() {
  analogWrite(LED_BLUE_PIN, 255);
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 0);
}
void ledGreenOn() {
  analogWrite(LED_BLUE_PIN, 0);
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 255);
}

void gmaeOverSong() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Buzeer_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(Buzeer_PIN);
  }
}
void greenTeamLed(){
  if(greenCount == 1){
    digitalWrite(GREEN_LED_1, HIGH);
  }else if(greenCount == 2){
    digitalWrite(GREEN_LED_2, HIGH);
  }
}
void blueTeamLed(){
  if(blueCount == 1){
    digitalWrite(BLUE_LED_2, HIGH);
  }else if(blueCount == 2){
    digitalWrite(BLUE_LED_1, HIGH);
  }
}
