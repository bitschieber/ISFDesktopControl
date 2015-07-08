#ifndef ISTEERING_H
#define ISTEERING_H

#include <inttypes.h>

class ISteering
{
public:
    ISteering();
    virtual uint16_t calcSteeringAngleFromPWM(uint16_t pwm) = 0;
};

#endif // ISTEERING_H
