#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor {
    public:
        StepperMotor(int step_gpio_pin, int direction_gpio_pin, int enable_gpio_pin, int pulse_delay_microseconds) : 
            step_gpio_pin(step_gpio_pin),
            direction_gpio_pin(direction_gpio_pin),
            enable_gpio_pin(enable_gpio_pin),
            pulse_delay_microseconds(pulse_delay_microseconds) {}

        void setup();
        void moveForward(int steps);
        void moveBackwards(int steps);
    private:
        int step_gpio_pin;
        int direction_gpio_pin;
        int enable_gpio_pin;
        int pulse_delay_microseconds;

        void move(bool high, int steps);
};

#endif // STEPPER_MOTOR_H