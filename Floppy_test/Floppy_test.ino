int stepPin = 3;
int drivePin=2;
int d = 18.02;


void setup() {
pinMode(stepPin, OUTPUT);
pinMode(drivePin, OUTPUT);
digitalWrite(stepPin, LOW);
digitalWrite(drivePin, LOW);
}

void loop() {
  digitalWrite(stepPin, HIGH);
  delay(d);
  digitalWrite(stepPin, LOW);
  delay(d);

}
