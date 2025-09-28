#include <Arduino.h>
#include "../lib/StepperMotor/stepper_motor.h"

#define PULSE_DELAY 500   

StepperMotor motorX(54, 55, 38, PULSE_DELAY);
StepperMotor motorY(60, 61, 56, PULSE_DELAY);
StepperMotor motorZ(46, 48, 62, PULSE_DELAY);

void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  motorX.setup();
  motorY.setup();
  motorZ.setup();
}

void loop() {
  Serial.println("Moving X forward 1600 steps...");
  motorX.moveForward(1600);

  Serial.println("Moving X backward 1600 steps...");
  motorX.moveBackwards(1600);

  Serial.println("Moving Y forward 1600 steps...");
  motorY.moveForward(1600);

  Serial.println("Moving Y backward 1600 steps...");
  motorY.moveBackwards(1600);

  Serial.println("Moving Z up 1600 steps...");
  motorZ.moveForward(1600);

  Serial.println("Moving Z down 1600 steps...");
  motorZ.moveBackwards(1600);
}
