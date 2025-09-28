#include <Arduino.h>
#include "../lib/StepperMotor/stepper_motor.h"

#define PULSE_DELAY 500   

StepperMotor motorX(54, 55, 38, PULSE_DELAY, 3200 / 104);
StepperMotor motorY(60, 61, 56, PULSE_DELAY, 3200 / 40);
StepperMotor motorZ(46, 48, 62, PULSE_DELAY, 3200 / 7);

void setup() {
  Serial.begin(115200);
  Serial.println("Start");

  motorX.setup();
  motorY.setup();
  motorZ.setup();
}

void loop() {
  motorZ.moveBackwardMillimeters(70);

  delay(3000);
  
  motorZ.moveForwardMillimeters(70);

  delay(3000);
}
