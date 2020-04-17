
#include <Stepper.h>

const int SPR = 800; //steps per revolution
Stepper myStepper(SPR, 7,8);
int stepSpeed=450;
int Keys[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
int w=400;
int h=200;
int q=100;
int e=500;
int bpm = 60;
int wholeNote =2000; // w in the array
int halfNote =wholeNote/2; // h in the array
int quarterNote =wholeNote/4; //q in the array
int eightNote = wholeNote/8; //o in the array
int flag=0;
int StepCount;//the amounts of steps the motor takes
int flag2=0;
const int buttonPin = 6;
const int tracingPin = 9;
boolean setdir = LOW; 
const int SPK=160;// steps per Key
int led=10;
int solenoidBlack= 11;
int solenoidWhite= 12;
int BoW;
int buttonState = 0;

//This is where you write your song. The keys go form 1 to 59 and then a note type after it to change the duration of the note. You can use my piano sketch to make this procces
//much easier
int Notes[]={41,e,40,e,41,e,40,e,41,e,36,e,39,e,37,e,34,e,22,e,25,e,29,e,34,e,36,q,17,e,21,e,29,e,37,e,36,e,34,q,41,e,40,e,41,e,40,e,41,e,36,e,39,e,37,e,34,e,22,e,25,e,29,e,34,e,36,q,17,e,21,e,29,e,33,e,36,e,37,q,
41,e,40,e,41,e,40,e,41,e,36,e,39,e,37,e,34,e,22,e,25,e,29,e,34,e,36,q,17,e,21,e,29,e,37,e,36,e,34,q};

int oneNote;
void setup() {
  pinMode(buttonPin, INPUT);
   myStepper.setSpeed(stepSpeed);
     pinMode(led, OUTPUT);
Serial.begin(9600);
  pinMode(solenoidBlack, OUTPUT);
    pinMode(solenoidWhite, OUTPUT);
  pinMode(tracingPin, INPUT);
}

void loop() {
while(flag==0){
  while(flag2==0){//To start the motor at the beginning
    buttonState = digitalRead(buttonPin);
  myStepper.step(-SPK); 
  if(buttonState == HIGH){
    flag2++;
    break;}}
    
delay(1000);
StepCount=1;
int Size=(sizeof(Notes)/sizeof(*Notes));
Serial.println(Size);
  for(int i=0;i<Size;i++){
    oneNote=Notes[i];
    SongOne(Notes[i]);
}//Call this method when the songs go from sec 1 to 5 in order
flag++;
}}

  void SongOne(int notes){
  if(notes==w||notes==h||notes==q||notes==e){
  Measures(notes);}

if(notes==Keys[notes]){
aNoteStep(StepCount, Keys[notes]);}
 }
  
void aNoteStep(int SC, int key){

if(SC==key){
aNote();}
else if(SC>key){
  for(int i = SC;i>=key;i--){
    myStepper.step(-SPK);
    StepCount--;
  }
  aNote();
}
else if(SC<key){
  for(int i=SC;i<=key;i++){
    myStepper.step(SPK);
    StepCount++;
  }
    aNote();
}}


// plays the notes
void aNote(){
  int val = digitalRead(tracingPin);
  Serial.println(oneNote);//prints out the note number
  if(val==HIGH){
 digitalWrite(solenoidBlack, HIGH);
 BoW=0;}
 else if(val==LOW){
 digitalWrite(solenoidWhite, HIGH);
 Serial.println(BoW);
 BoW=1;}
 digitalWrite(led, HIGH);
}

//Lifts the finger for the right measure
void Measures(int tempo){

if(tempo==w){  delay(wholeNote);
  Serial.println("wholeNote");
  if(BoW==0)
    digitalWrite(solenoidBlack, LOW);
    else if(BoW==1)
    digitalWrite(solenoidWhite, LOW);
     digitalWrite(led, LOW);
  //lift the finger
}
if(tempo==h){  delay(halfNote);
  Serial.println("halfNote");
   if(BoW==0)
    digitalWrite(solenoidBlack, LOW);
    else if(BoW==1)
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
}
if(tempo==q){ delay(quarterNote);
  Serial.println("quarterNote");
     if(BoW==0)
    digitalWrite(solenoidBlack, LOW);
    else if(BoW==1)
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
}
  if(tempo==e){
    delay(eightNote);
    Serial.println(eightNote);
  Serial.println("eightNote");
      if(BoW==0)
    digitalWrite(solenoidBlack, LOW);
    else if(BoW==1)
    digitalWrite(solenoidWhite, LOW);
      digitalWrite(led, LOW);
}
delay(50);//delays the next note by a little bit to give the solenoidBlack enough time to return
}
