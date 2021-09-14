//#define dirPin 2
//#define stepPin 3
//void setup() {
//// Declare pins as output:
// pinMode(stepPin, OUTPUT);
// pinMode(dirPin, OUTPUT);
//// Set the spinning direction CW/CCW:
// digitalWrite(dirPin, HIGH);
//}
//void loop() {
//// These four lines result in 1 step:
// digitalWrite(stepPin, HIGH);
// delay(1930); // lower this number for an increased flow rate
// digitalWrite(stepPin, LOW);
// delay(1930); // lower this number for an increased flow rate
//}


#include <Stepper.h>

const int stepsPerRevolution = 1600;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 3);

void setup() {
  // 58 RPM for big pump, 116 for little pump
  myStepper.setSpeed(58);
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(stepsPerRevolution);
}
