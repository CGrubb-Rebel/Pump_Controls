#include <Stepper.h>

//Assign the number of steps native to the motor (can go up to 400, at the expense of torque)
const int stepsPerRevolution = 200;


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // Used to count the number of steps the motor has taken

void setup() {
  // Opens the serial communication line for printing
  Serial.begin(9600);
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  int flow = 0;
  
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 20, 200);
  
  // set the motor speed and step rate:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution);

    //calculate and diplay the flow rate
    flow = motorSpeed * 3.5;
    char buf[10];
    sprintf(buf, "%d mL/min", flow);
    Serial.println(buf);
  }
}
