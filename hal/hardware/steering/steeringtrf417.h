#ifndef STEERINGTRF417_H
#define STEERINGTRF417_H

#include "isteering.h"
#include <math.h>

class SteeringTRF417 : public ISteering
{
public:
    SteeringTRF417();
    uint16_t calcSteeringAngleFromPWM(uint16_t pwm);
};

#endif // STEERINGTRF417_H
