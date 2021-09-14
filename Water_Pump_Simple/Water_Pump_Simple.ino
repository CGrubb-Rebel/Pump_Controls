// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 1600;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 2, 3);


void setup()
{
  //divde the deired flow rate by 3.5 for the large pump, and .145 for the small pump
  myStepper.setSpeed(58);
}


void loop() 
{
  myStepper.step(stepsPerRevolution);
  //myStepper.setSpeed(58);
}
