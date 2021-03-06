#ifndef DCMOTOR_L298N_H
#define DCMOTOR_L298N_H

#include "Arduino.h"

class dcMotor
{
public:
    dcMotor();
    // Sets a dcMotor and pins for direction
    dcMotor(uint8_t pin_a, uint8_t pin_b);
    // Sets a dcMotor, pins for direction and pin for speed
    dcMotor(uint8_t pin_a, uint8_t pin_b, uint8_t pin_spd);
    // If inverted true, inverts motor output
    dcMotor(uint8_t pin_a, uint8_t pin_b, bool inv);
    // If inverted true, inverts motor output
    dcMotor(uint8_t pin_a, uint8_t pin_b, uint8_t pin_spd, bool invert);
    // destructor
    ~dcMotor();
    // sets direction pins for motor
    void setPins(uint8_t pin_a, uint8_t pin_b);
    // sets direction and speed pins for motor
    void setPins(uint8_t pin_a, uint8_t pin_b, uint8_t pin_spd);
    // sets motor speed;
    void setSpeed(uint8_t spd);
    // toggle inverting the motor direction
    void invert();
    // return direction pin a
    uint8_t getDirPinA();
    // return direction pin b
    uint8_t getDirPinB();
    // return direction pin numbers
    uint8_t *getDirPins();
    // return speed pin number
    uint8_t getSpdPin();
    // return speed value
    uint8_t getSpeed();
    // return whether is inverted
    bool isInverted();
    // sets INa = 1 and INb = 0
    void runForward();
    // sets INa = 0 and INb = 1
    void runBackward();
    // sets all IN pins to 0
    void stop();
    // mode FORWARD and BACKWARD
    void run(uint8_t mode);
    // mode FORWARD and BACKWARD with speed
    void run(uint8_t spd, uint8_t mode);

private:
    uint8_t *pin_a = NULL, *pin_b = NULL; // direction pins
    uint8_t *pin_spd = NULL;              // speed pin
    uint8_t speed = 0;                    // speed value
    uint8_t pinout_a = 0, pinout_b = 0;   // direction pins outputs
    uint8_t pinout_s = 0;                 // speed pin output
    bool inverted = false;                // whether to change motor direction
};

#endif
