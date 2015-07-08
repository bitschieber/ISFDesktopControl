#ifndef MOTORXTEC1_H
#define MOTORXTEC1_H

#include "imotor.h"
#include <math.h>

class MotorXTEC1 : public IMotor
{
public:
    MotorXTEC1();
    uint16_t calcSpeedFromPWM(uint16_t pwm);
};

#endif // MOTORXTEC1_H
