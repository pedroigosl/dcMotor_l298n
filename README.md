# dcMotor_l298n

L298N h-bridge module library for dc motors

## +++ WARNING +++

This library is untested. It is part of a greater project still on its beginnings

## Structure

The library models motor objects with speed value, output pins for direction, output pin for speed and a marker to whether it is inverted

## How to use

1 - You first need to instantiate a motor, its direction pins and speed pin using integers with the pins numbers. You can either do it all directly using constructors or use ***set*** functions later

2 - Set speed, an integer in [0, 255]

> If the motors are installed backwards, you can use ***invert()*** to correct it

3 - Use movement functions to move
- ***runForward()***
- ***runBackward()***
- ***stop()***

4 - If needed, you can recover values using ***get*** functions

## Example

```C++
#include <Arduino.h>

void setup() {
  dcMotor motor_A(5,6,7);
}

void loop() {
  motor_A.setSpeed(125);
  motor_A.runForward();
}
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
