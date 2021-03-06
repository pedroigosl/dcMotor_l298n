#include "dcmotor_l298n.h"

dcMotor::dcMotor()
{
}

dcMotor::dcMotor(uint8_t pin_a, uint8_t pin_b)
{
    this->pin_a = pin_a;
    this->pin_b = pin_b;

    pinMode(pin_a, OUTPUT);
    pinMode(pin_b, OUTPUT);
}

dcMotor::dcMotor(uint8_t pin_a, uint8_t pin_b, uint8_t pin_spd)
{
    this->pin_a = pin_a;
    this->pin_b = pin_b;
    this->pin_spd = pin_spd;

    pinMode(pin_a, OUTPUT);
    pinMode(pin_b, OUTPUT);
    pinMode(pin_spd, OUTPUT);
}

dcMotor::dcMotor(uint8_t pin_a, uint8_t pin_b, bool inverted)
{
    this->pin_a = pin_a;
    this->pin_b = pin_b;
    this->inverted = inverted;

    pinMode(pin_a, OUTPUT);
    pinMode(pin_b, OUTPUT);
}

dcMotor::dcMotor(uint8_t pin_a, uint8_t pin_b, uint8_t pin_spd, bool inverted)
{
    this->pin_a = pin_a;
    this->pin_b = pin_b;
    this->pin_spd = pin_spd;
    this->inverted = inverted;

    pinMode(pin_a, OUTPUT);
    pinMode(pin_b, OUTPUT);
    pinMode(pin_spd, OUTPUT);
}

dcMotor::~dcMotor()
{
}

void dcMotor::setPins(uint8_t pin_a, uint8_t pin_b)
{
    this->pin_a = pin_a;
    this->pin_b = pin_b;

    pinMode(pin_a, OUTPUT);
    pinMode(pin_b, OUTPUT);
}

void dcMotor::setPins(uint8_t pin_a, uint8_t pin_b, uint8_t pin_spd)
{
    this->pin_a = pin_a;
    this->pin_b = pin_b;
    this->pin_spd = pin_spd;

    pinMode(pin_a, OUTPUT);
    pinMode(pin_b, OUTPUT);
    pinMode(pin_spd, OUTPUT);
}
// speed in [0,255]
void dcMotor::setSpeed(uint8_t spd)
{
    speed = spd;
}

void dcMotor::invert()
{
    if (inverted == false)
    {
        inverted = true;
        return;
    }
    inverted = false;
}

uint8_t dcMotor::getDirPinA()
{
    try
    {
        if (pin_a == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        return 0;
    }
    return pin_a;
}

uint8_t dcMotor::getDirPinB()
{
    try
    {
        if (pin_b == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        return 0;
    }
    return pin_b;
}

uint8_t *dcMotor::getDirPins()
{
    try
    {
        if (pin_a == NULL || pin_b == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        uint8_t pins[2];
        pins[0] = 0;
        pins[1] = 0;
        return pins;
    }
    uint8_t pins[2];
    pins[0] = pin_a;
    pins[1] = pin_b;
    return pins;
}

uint8_t dcMotor::getSpdPin()
{
    try
    {
        if (pin_spd == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        return 0;
    }
    return pin_spd;
}

uint8_t dcMotor::getSpeed()
{
    return speed;
}

bool dcMotor::isInverted()
{
    return inverted;
}

void dcMotor::runForward()
{
    try
    {
        if (pin_a == NULL || pin_b == NULL || pin_spd == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        return;
    }

    if (inverted == true)
    {
        pinout_a = 0;
        pinout_b = 1;
    }
    else
    {
        pinout_a = 1;
        pinout_b = 0;
    }
    pinout_s = speed;

    digitalWrite(pin_a, pinout_a);
    digitalWrite(pin_b, pinout_b);
    analogWrite(pin_spd, pinout_s);
}

void dcMotor::runBackward()
{
    try
    {
        if (pin_a == NULL || pin_b == NULL || pin_spd == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        return;
    }

    if (inverted == true)
    {
        pinout_a = 1;
        pinout_b = 0;
    }
    else
    {
        pinout_a = 0;
        pinout_b = 1;
    }
    pinout_s = speed;

    digitalWrite(pin_a, pinout_a);
    digitalWrite(pin_b, pinout_b);
    analogWrite(pin_spd, pinout_s);
}

void dcMotor::stop()
{
    try
    {
        if (pin_a == NULL || pin_b == NULL)
        {
            throw;
        }
    }
    catch (...)
    {
        return;
    }

    pinout_a = 0;
    pinout_b = 0;

    digitalWrite(pin_a, pinout_a);
    digitalWrite(pin_b, pinout_b);
}

void dcMotor::run(uint8_t mode = FORWARD)
{
    switch (mode)
    {
    case FORWARD:
        runForward();
        break;
    case BACKWARD:
        runBackward();
        break;
    }
}

void dcMotor::run(uint8_t spd, uint8_t mode = FORWARD)
{
    switch (mode)
    {
    case FORWARD:
        setSpeed(spd);
        runForward();
        break;
    case BACKWARD:
        setSpeed(spd);
        runBackward();
        break;
    }
}