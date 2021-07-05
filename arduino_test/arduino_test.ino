int sensor =A0;
int sensorRead = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorRead = analogRead(sensor);
  Serial.println(sensorRead);
  delay(200);
}
