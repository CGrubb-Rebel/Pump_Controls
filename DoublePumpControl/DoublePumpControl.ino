#include <Stepper.h>

//Assign the number of steps native to the motor, our motors have a 1.8degree step meaning the can run at 200 steps per revolution
const int smallSPR = 200;
const int largeSPR = 200;

//Assign the motor speed, which can be caluculated by taking the desired flow rate and dividing it my the motors flow rate:
//Nominal flow of the small stepper is .145mL per revolution using the 2mm tube
//Nominal flow of the large stepper is 3.5mL per revolution using the 1/4" tube
int smallMotorSpeed = 221;
int largeMotorSpeed = 60;

// initialize the stepper library on the comunication pins of the Arduino board
Stepper smallStepper(smallSPR, 4, 5, 6, 7); //Connect the small motors input pins (IN1, IN2, IN3 and IN4), to the Arduino'd digital output pins (8, 9, 10 and 11).
Stepper largeStepper(largeSPR, 8, 9, 10,11); //Connect the large motors input pins (IN1, IN2, IN3 and IN4), to the Arduino'd digital output pins (4, 5, 6 and 7).

void setup()
{
  smallStepper.setSpeed(smallMotorSpeed);
  largeStepper.setSpeed(largeMotorSpeed);
}

void loop()
{
  //Run the motor according to the varibales set-up earlier in the code
//  while (smallMotorSpeed > 20)
//  {
//  smallStepper.step(smallSPR);
//  //
//  }
  //Run the motor according to the varibales set-up earlier in the code

  largeStepper.step(largeSPR);
  //

}
