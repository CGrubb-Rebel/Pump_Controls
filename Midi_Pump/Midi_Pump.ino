#include <Stepper.h>

const int stepsPerRevolution = 1600;  // change this to fit the number of steps per revolution (dont ask me why this needs to be 1600)
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
