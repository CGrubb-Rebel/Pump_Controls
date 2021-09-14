#include <Adafruit_ILI9341.h>
#include <memorysaver.h>
#include <UTFT.h>
#include <URTouch.h>

// Creating Objects
UTFT    myGLCD(ILI9341_16,38,39,40,41);

// Define stepper motor connections:
#define dirPin 8
#define stepPin 9

void setup() {
  // Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  // Declare stepper pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
