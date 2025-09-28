#include "stepper_motor.h"

void StepperMotor::setup() {
  pinMode(step_gpio_pin, OUTPUT);
  pinMode(direction_gpio_pin, OUTPUT);
  pinMode(enable_gpio_pin, OUTPUT);

  digitalWrite(enable_gpio_pin, LOW);
}

void StepperMotor::moveForward(int steps) {
    move(true, steps);
}

void StepperMotor::moveBackward(int steps) {
    move(false, steps);
}

void StepperMotor::moveForwardMillimeters(int millimeters) {
    moveForward(steps_to_move_1_millimeter * millimeters);
}

void StepperMotor::moveBackwardMillimeters(int millimeters) {
    moveBackward(steps_to_move_1_millimeter * millimeters);
}

void StepperMotor::move(bool high, int steps) {
  digitalWrite(direction_gpio_pin, high ? HIGH : LOW);

  for (long i = 0; i < steps; i++) {
    digitalWrite(step_gpio_pin, HIGH);
    delayMicroseconds(pulse_delay_microseconds);

    digitalWrite(step_gpio_pin, LOW);
    delayMicroseconds(pulse_delay_microseconds);
  }
}