//////////////////////////////////Constants////////////////////////////////////////////
#define STEPS_IN_DIRECTION 80
#define STEP_PIN 3
#define DRIVE_PIN 2

//////////////////////////////////Variables////////////////////////////////////////////
int stepLocation = 0;// 0 is the back of the floppy, 79 is the front, 159 is back to the back
double frequency[10] = {45,55,60,65,70,80,90,100,120,150};
double duration[10]= {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
//////////////////////////////////Main setup////////////////////////////////////////////
void setup() {
pinMode(STEP_PIN, OUTPUT);
pinMode(DRIVE_PIN, OUTPUT);
digitalWrite(STEP_PIN, LOW);
digitalWrite(DRIVE_PIN, LOW);
resetMoppy();
//Serial.begin(9600);
//Serial.print(("Hello World"));
}
/////////////////////////////////Main Loop/////////////////////////////////////////////
void loop() {
for(int i = 0; i < 10; i++) {
  playNote(frequency[i], duration[i]);
}
resetMoppy();
delay(500);
}
////////////////////////////////////Functions////////////////////////////////////////////
void playNote(double frequency, double duration){
  long startTime = millis();
  while(millis() - startTime < duration) {
    if (stepLocation < STEPS_IN_DIRECTION){
      digitalWrite(DRIVE_PIN, LOW);
    }  else {
      digitalWrite(DRIVE_PIN, HIGH);
    }
    digitalWrite(STEP_PIN, HIGH);
    delay(500.0/frequency);
    digitalWrite(STEP_PIN, LOW);
    delay(500.0/frequency);
    stepLocation++;
    stepLocation = stepLocation % (STEPS_IN_DIRECTION*2);  // reset direction iff necessary
  }
}
  void resetMoppy(){
    digitalWrite(DRIVE_PIN, HIGH);
    digitalWrite(STEP_PIN, LOW);
    for(int i = 0; i < 80; i++){
      digitalWrite(STEP_PIN, HIGH);
      delay(2);
      digitalWrite(STEP_PIN, LOW);
      delay(2);
     }
  stepLocation = 0;
}








