#include <Stepper.h>

const int SmallSPR = 200;  // change this to fit the number of steps per revolution
const int LargeSPR = 200;
// for your motor

const int buttonPin = 2;

int buttonState = 0;

// initialize the stepper library on pins 8 through 11:
Stepper smallStepper(SmallSPR, 8, 9, 10, 11);
Stepper largeStepper(LargeSPR, 4, 5, 6, 7);

void setup()
{
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // set the speed at 60 rpm:
  //smallStepper.setSpeed(60);
  //largeStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop()
{
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 20, 200);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, control the small pump
  if (buttonState == HIGH) {
    smallStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    smallStepper.step(SmallSPR);
  } else {
    largeStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    largeStepper.step(LargeSPR);
  }
}
