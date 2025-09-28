#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor {
    public:
        StepperMotor(int step_gpio_pin, int direction_gpio_pin, int enable_gpio_pin, int pulse_delay_microseconds, int steps_to_move_1_millimeter) : 
            step_gpio_pin(step_gpio_pin),
            direction_gpio_pin(direction_gpio_pin),
            enable_gpio_pin(enable_gpio_pin),
            pulse_delay_microseconds(pulse_delay_microseconds),
            steps_to_move_1_millimeter(steps_to_move_1_millimeter) {}

        void setup();
        void moveForward(int steps);
        void moveBackward(int steps);
        void moveForwardMillimeters(int millimeters);
        void moveBackwardMillimeters(int millimeters);
    private:
        int step_gpio_pin;
        int direction_gpio_pin;
        int enable_gpio_pin;
        int pulse_delay_microseconds;
        int steps_to_move_1_millimeter;

        void move(bool high, int steps);
};

#endif // STEPPER_MOTOR_H