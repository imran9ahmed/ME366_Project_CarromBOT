#include <AccelStepper.h>
#include <Servo.h>

// Define stepper motor control pins
const int dirPin = 26;
const int stepPin = 3;
#define motorInterfaceType 1

// Create stepper motor instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

// Define servo motors
Servo myservo1, myservo2, myservo3, myservo4;
int pos = 0; // Variable to store servo position

// Define vacuum motor control pins
int in1 = 9;
int in2 = 46;

// Function to turn on the vacuum pump
void TurnMotorA() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

// Function to turn off the vacuum pump
void TurnOFFA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

// Function to pick a white disc
void PickWhite() {
  myservo1.write(30);
  myservo4.write(59);
  myservo2.write(85);

  for (pos = 90; pos <= 150; pos++) {
    myservo3.write(pos);
    delay(20);
  }

  delay(1000);
  TurnMotorA();

  for (pos = 85; pos >= 70; pos--) {
    myservo2.write(pos);
    delay(20);
  }

  delay(1000);

  for (pos = 70; pos <= 90; pos++) {
    myservo2.write(pos);
    delay(20);
  }
}

// Function to pick a black disc
void PickBlack() {
  myservo2.write(100);
  myservo1.write(0);
  myservo4.write(68);

  for (pos = 90; pos <= 155; pos++) {
    myservo3.write(pos);
    delay(20);
  }

  for (pos = 100; pos >= 90; pos--) {
    myservo2.write(pos);
    delay(20);
  }

  delay(1000);
  TurnMotorA();

  for (pos = 90; pos >= 70; pos--) {
    myservo2.write(pos);
    delay(20);
  }

  delay(1000);

  for (pos = 70; pos <= 80; pos++) {
    myservo2.write(pos);
    delay(20);
  }

  for (pos = 80; pos <= 100; pos++) {
    myservo2.write(pos);
    delay(20);
  }
}

// Setup function
void setup() {
  // Setup motor control pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Initialize stepper motor
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(200);

  // Attach servo motors to their respective pins
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(10);
  myservo4.attach(11);

  // Set initial positions for the servo motors
  myservo1.write(150);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(45);

  // Move stepper to starting position
  myStepper.moveTo(-218);
  myStepper.runToPosition();
  TurnMotorA();
  delay(1000);
  TurnOFFA();

  Serial.begin(9600);

  // --- SEQUENCE STARTS HERE ---
  // Call your pick and drop sequences from here.
  // Modularize your code from the original if needed to keep this function clean.

  // For example:
  // ExecutePickDropSequence(WHITE);
  // MoveBotBackward(5);
  // ExecutePickDropSequence(BLACK);
  // ...
  // Since the original code had many repetitive blocks, consider moving those into
  // reusable functions if needed.

  // At the end, return the stepper to original position
  myStepper.moveTo(0);
  myStepper.runToPosition();
}

// Loop function (not used here)
void loop() {
  // Empty since all actions are in setup()
}
