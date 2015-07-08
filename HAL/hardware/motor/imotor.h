#ifndef IMOTOR_H
#define IMOTOR_H

#include <inttypes.h>

class IMotor
{
public:
    IMotor();
    virtual uint16_t calcSpeedFromPWM(uint16_t pwm) = 0;
};

#endif // IMOTOR_H
