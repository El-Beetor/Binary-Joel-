
#include <Stepper.h>

const int SPR = 800; //steps per revolution
Stepper myStepper(SPR, 7,8);
int stepSpeed=450;
int Keys[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
int w=400;
int h=200;
int q=100;
int e=500;
int r=600;
int bpm = 60;
int wholeNote =2000; // w in the array
int halfNote =wholeNote/2; // h in the array
int quarterNote =wholeNote/4; //q in the array
int eightNote = wholeNote/8; //o in the array
int sixthNote = wholeNote/16;
int flag=0;
int StepCount;//the amounts of steps the motor takes
int flag2=0;
const int buttonPin = 6;
boolean setdir = LOW; 
const int SPK=270;// steps per Key
int led=10;
int solenoidBlack= 11;
int solenoidWhite= 12;
int buttonState = 0;
//int Notes[]={1,h,2,h,3,h,14,h,25,h,16,h};
int Notes[]={41,e,40,e,41,e,40,e,41,e,36,e,39,e,37,e,34,q,22,e,25,e,29,e,34,e,36,q,17,e,21,e,29,e,37,e,36,e,34,q,41,e,40,e,41,e,40,e,41,e,36,e,39,e,37,e,34,q,22,e,25,e,29,e,34,e,36,q,17,e,21,e,29,e,33,e,36,e,37,q,
41,e,40,e,41,e,40,e,41,e,36,e,39,e,37,e,34,q,22,e,25,e,29,e,34,e,36,q,17,e,21,e,29,e,37,e,36,e,34,w};
int oneNote;
void setup() {
  pinMode(buttonPin, INPUT);a
   myStepper.setSpeed(stepSpeed);
     pinMode(led, OUTPUT);
Serial.begin(9600);
  pinMode(solenoidBlack, OUTPUT);
    pinMode(solenoidWhite, OUTPUT);
}

void loop() {
while(flag==0){
 while(flag2==0){//To start the motor at the beginning
   buttonState = digitalRead(buttonPin);
   if(buttonState == HIGH){
    flag2++;
    break;}
    myStepper.setSpeed(150);
  myStepper.step(-SPK/2); 
  }
    myStepper.setSpeed(stepSpeed);
delay(1000);
StepCount=1;
int Size=(sizeof(Notes)/sizeof(*Notes));
Serial.print("Size ");
Serial.println(Size);
  for(int i=0;i<Size;i++){
    oneNote=Notes[i];//track where it is
    Serial.print("StepCount ");
    Serial.println(StepCount);
        SongOne(Notes[i]);
}
flag++;
}
}

  void SongOne(int notes){
  if(notes==w||notes==h||notes==q||notes==e||notes==r){
  Measures(notes);}

if(notes==Keys[notes]){
aNoteStep(StepCount, Keys[notes]);}
 }
  
void aNoteStep(int SC, int key){

if(SC==key){
aNote(key);}
else if(SC>key){
  for(int i = SC;i>key;i--){
    myStepper.step(-SPK);
    StepCount--;
  }
  aNote(key);
}
else if(SC<key){
  for(int i=SC;i<key;i++){
    myStepper.step(SPK);
    StepCount++;
  }
    aNote(key);
}
}

// plays the notes
void aNote(int KEY){
  Serial.println(oneNote);//prints out the note number
  if(KEY==2||KEY==4||KEY==7||KEY==9||KEY==11||KEY==14||KEY==16||KEY==19||KEY==21||KEY==23||
  KEY==26||KEY==28||KEY==31||KEY==33||KEY==35||KEY==38||KEY==40||KEY==43||KEY==45||KEY==47||KEY==50||KEY==52||KEY==55||KEY==57||KEY==59){
 digitalWrite(solenoidBlack, HIGH);
}
 else {
 digitalWrite(solenoidWhite, HIGH);
}
 digitalWrite(led, HIGH);
}

//Lifts the finger for the right measure
void Measures(int tempo){

if(tempo==w){  delay(wholeNote);
  Serial.println("wholeNote");
    digitalWrite(solenoidBlack, LOW);
    digitalWrite(solenoidWhite, LOW);
     digitalWrite(led, LOW);
  //lift the finger
}
if(tempo==h){  delay(halfNote);
  Serial.println("halfNote");
    digitalWrite(solenoidBlack, LOW);
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
}
if(tempo==q){ delay(quarterNote);
  Serial.println("quarterNote");
    digitalWrite(solenoidBlack, LOW);
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
}
  if(tempo==e){
    delay(eightNote);
  Serial.println("eightNote");
    digitalWrite(solenoidBlack, LOW);
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
}
if(tempo==r){
    delay(sixthNote);
  Serial.println("sixthtNote");
    digitalWrite(solenoidBlack, LOW);
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
 
}
Serial.println("delay");
delay(100);//delays the next note by a little bit to give the solenoidBlack enough time to return
}
