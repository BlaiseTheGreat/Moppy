int stepPin = 3;
int drivePin=2;
int d = 19.02;


void setup() {
pinMode(stepPin, OUTPUT);
pinMode(drivePin, OUTPUT);
digitalWrite(stepPin, LOW);
digitalWrite(drivePin, LOW);
}

void loop() {
digitalWrite(drivePin, LOW);
for(int i = 0; i < 80; i++){
digitalWrite(stepPin, HIGH);
delay(d);
digitalWrite(stepPin, LOW);
delay(d);
}
digitalWrite(drivePin, HIGH);
for(int j= 0; j < 80; j++){
digitalWrite(stepPin, HIGH);
delay(d);
digitalWrite(stepPin, LOW);
delay(d);
}
}
