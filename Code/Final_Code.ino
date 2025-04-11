#include <AccelStepper.h>
#include <Servo.h>
const int dirPin = 26;
const int stepPin = 3;
Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4; // create servo object to control a servo
int pos=0 ;// variable to store the servo position
int in1 = 9; //Declaring the pins where in1 in2 from the driver are wired 
int in2 = 46; //here they are wired with D9 and D46 from Arduino
#define motorInterfaceType 1 // Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);
void TurnMotorA(){              
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}                         // Defining function to turn on the vacuum pump

void TurnOFFA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}                        // Defining function to turn off the vacuum pump
void PickWhite(){
  myservo1.write(30);
  myservo4.write(59); 
  myservo2.write(85); 
  for (pos = 90; pos <= 150; pos += 1) { 
    myservo3.write(pos); 
    delay(20);           
  }
  delay(1000);
  TurnMotorA();
  for (pos = 85; pos >= 70; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  delay(1000);  
  for (pos = 70; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
}                      // Defining function to pic white disc
void PickBlack(){
  myservo2.write(100);
  myservo1.write(0);
  myservo4.write(68); 
  for (pos = 90; pos <= 155; pos += 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 100; pos >= 90; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  delay(1000);
  TurnMotorA();
  for (pos = 90; pos >= 70; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  delay(1000);
  
  for (pos = 70; pos <= 80; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 80; pos <= 100; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
}                      // Defining function to pic white disc
void setup() {
  pinMode(in1, OUTPUT); //Declaring the pin modes, obviously they're outputs
  pinMode(in2, OUTPUT);
  myStepper.setMaxSpeed(1000);
	myStepper.setAcceleration(50);
	myStepper.setSpeed(200);
  myservo1.attach(5); // Declaring pins to attach Servos
  myservo2.attach(6);
  myservo3.attach(10);
  myservo4.attach(11);
  myservo1.write(150); // Declaring initial positions of servos
  myservo2.write(90); 
  myservo3.write(90);  
  myservo4.write(45);
  myStepper.moveTo(-218);
  myStepper.runToPosition();
  TurnMotorA();
  delay(1000);
  TurnOFFA();
  Serial.begin(9600); // Bot is at a distance of 5.5 cm from the center
  // Initiates picking sequence for disc 1
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 30; pos <= 146; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=86; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 1  
  delay(1000);
  // Initiates picking sequence for disc 2
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 0; pos <= 132; pos += 1) {
    myservo1.write(pos);
    delay(20);             
  }
  for (pos = 120; pos >= 75; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo3.write(pos);
    delay(20);              
  } 
  for (pos =60; pos <=90; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 2
  delay(1000);
  // Initiates picking sequence for disc 3
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 30; pos <= 121; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);           
  }
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=96; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 3
  delay(1000);
  // Initiates picking sequence for disc 4
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  // Move the bot backwards by 0.5 cm
  myStepper.moveTo(-211);
  myStepper.runToPosition();
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 0; pos <= 150; pos += 1) {
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 120; pos >= 75; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 110; pos -= 1) { 
    myservo3.write(pos);
    delay(20);              
  }
  for (pos =60; pos <=105; pos += 1) { 
    myservo4.write(pos); 
    delay(20);            
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 4
  delay(1000);
  // Initiates picking sequence for disc 5
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
   for (pos = 0; pos <= 134; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 120; pos >= 75; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  for (pos = 120; pos >= 110; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=107; pos += 1) {
    myservo4.write(pos); 
    delay(20);            
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops Disc 5
  delay(1000);
  // Initiates picking sequence for disc 6
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 30; pos <= 122; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);           
  }
  for (pos = 120; pos >= 99; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=102; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 6
  delay(1000);
  // Initiates picking sequence for disc 7
  // Move the  bot backwards by 1 cm  
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }  
  for (pos = 30; pos <= 111; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 120; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);           
  }
  for (pos = 120; pos >= 100; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=117; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 7
  delay(1000);
  // Initiates picking sequence for disc 8
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  myStepper.moveTo(-203);
  myStepper.runToPosition();
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 119; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 30; pos <= 160; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 180; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=90; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 20; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 8
  delay(1000);   
  // Initiates picking sequence for disc 9
  for (pos = 20; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 30; pos <= 145; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 180; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=93; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 20; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 9
  delay(1000);   
  // Initiates picking sequence for disc 10
  for (pos = 20; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  // Initiates picking sequence for disc 10
  myservo1.write(62);
  myservo4.write(62); 
  myservo2.write(85); 
  for (pos = 90; pos <= 150; pos += 1) { 
    myservo3.write(pos); 
    delay(20);           
  }
  delay(1000);
  TurnMotorA();
  for (pos = 85; pos >= 70; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  delay(1000);  
  for (pos = 70; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos =60; pos <= 125; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 180; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=93; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 21; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 10
  delay(1000);  
  // Initiates picking sequence for disc 11
  for (pos = 21; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos =0; pos <= 107; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 120; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 180; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=104; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 20; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 11
  delay(1000);   
  // Initiates picking sequence for disc 12
  for (pos = 21; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos =30; pos <= 101; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 180; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=113; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 20; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 12
  delay(1000);
  // Initiates picking sequence for disc 13
  for (pos = 21; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  // Move the bot backwards by 5.5 cm
  myStepper.moveTo(-159);
  myStepper.runToPosition();
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 0; pos <= 150; pos += 1) {
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 120; pos >= 75; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 110; pos -= 1) { 
    myservo3.write(pos);
    delay(20);              
  }
  for (pos =60; pos <=106; pos += 1) { 
    myservo4.write(pos); 
    delay(20);            
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 13
  delay(1000);
  // Initiates picking sequence for disc 14
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickBlack();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
   for (pos = 0; pos <= 134; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 120; pos >= 75; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  for (pos = 120; pos >= 110; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=109; pos += 1) {
    myservo4.write(pos); 
    delay(20);            
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops Disc 5
  delay(1000);
  // Initiates picking sequence for disc 15
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 30; pos <= 122; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);           
  }
  for (pos = 120; pos >= 99; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=101; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 6
  delay(1000);
  // Initiates picking sequence for disc 16
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  myservo1.write(0); 
  myservo2.write(120); 
  myservo3.write(120);  
  myservo4.write(60);
  delay(1000);
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo2.write(pos);
    delay(20);             
  }
  myservo4.write(70);  
  for (pos = 80; pos >= 72; pos -= 1) { 
    myservo2.write(pos);
    delay(20);             
  }
  for (pos = 70; pos >= 60; pos -= 1) { 
    myservo4.write(pos);
    delay(20);              
  }
  myservo2.write(90);
  myservo4.write(68);
  for (pos = 120; pos <= 155; pos += 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  delay(1000);
  TurnMotorA();
  for (pos = 90; pos >= 70; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  delay(1000);
  
  for (pos = 70; pos <= 80; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 80; pos <= 100; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }  
  for (pos = 30; pos <= 111; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 120; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);           
  }
  for (pos = 120; pos >= 100; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=117; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 7
  delay(1000);
  // Initiates picking sequence for disc 17
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  // Move backwards my 5 cm
  myStepper.moveTo(-114);
  myStepper.runToPosition();
  PickWhite();
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 30; pos <= 146; pos += 1) { 
    myservo1.write(pos);
    delay(20);             
  } 
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=86; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 1  
  delay(1000);
  // Initiates picking sequence for disc 18
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  myservo1.write(0); // Declaring initial positions of servos
  myservo2.write(120); 
  myservo3.write(120);  
  myservo4.write(60);
  delay(1000);
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo2.write(pos);
    delay(20);             
  }
  myservo4.write(70);  
  for (pos = 80; pos >= 70; pos -= 1) { 
    myservo2.write(pos);
    delay(20);             
  }
  for (pos = 70; pos >= 50; pos -= 1) { 
    myservo4.write(pos);
    delay(20);              
  }
  myservo2.write(90);
  myservo4.write(70);
  for (pos = 120; pos <= 155; pos += 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  delay(1000);
  TurnMotorA();
  for (pos = 90; pos >= 70; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  delay(1000);
  
  for (pos = 70; pos <= 80; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 80; pos <= 100; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 100; pos <= 120; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 0; pos <= 129; pos += 1) {
    myservo1.write(pos);
    delay(20);             
  }
  for (pos = 120; pos >= 75; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo3.write(pos);
    delay(20);              
  } 
  for (pos =50; pos <=91; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  TurnOFFA();
  // Drops disc 18
  delay(1000);
  // Initiates picking sequence for disc 19
 for (pos =0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  myservo1.write(150);
  myservo2.write(120);
  myservo1.write(19); 
  myservo3.write(120);  
  myservo4.write(65);
  //delay(1000);
  for(pos=120; pos>=75; pos-=1){
    myservo2.write(pos);
    delay(20);
  }
  for(pos=120; pos<=143; pos+=1){
    myservo3.write(pos);
    delay(20);
  }
  myservo4.write(70);
  for (pos = 75; pos <=90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 140; pos >=90; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  for (pos = 24; pos <= 30; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 65; pos >=62; pos -= 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 90; pos >=85; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  for (pos = 90; pos <= 150; pos += 1) { 
    myservo3.write(pos); 
    delay(20);            
  }
  delay(1000);
  TurnMotorA();
  for (pos = 85; pos >= 70; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  delay(1000);
  for (pos = 70; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);           
  }
  // Completes picking the disc and initiates dropping sequence
  for (pos = 150; pos >= 120; pos -= 1) { 
    myservo3.write(pos); 
    delay(20);             
  }
  for (pos = 30; pos <= 121; pos += 1) { 
    myservo1.write(pos);
    delay(20);              
  }
  for (pos = 90; pos >= 75; pos -= 1) {
    myservo2.write(pos); 
    delay(20);           
  }
  for (pos = 120; pos >= 80; pos -= 1) { 
    myservo3.write(pos);
    delay(20);             
  }
  for (pos =60; pos <=97; pos += 1) { 
    myservo4.write(pos); 
    delay(20);             
  }
  for (pos = 75; pos >= 0; pos -= 1) { 
    myservo2.write(pos); 
    delay(20);             
  }
  TurnOFFA();
  // Drops disc 3
  delay(1000);
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo2.write(pos); 
    delay(20);            
  }
  myservo4.write(45);
  myservo1.write(150);
  myStepper.moveTo(0);
  myStepper.runToPosition();
}
void loop() { 
}