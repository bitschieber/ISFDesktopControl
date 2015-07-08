#ifndef STEERINGCONTROLLER_H
#define STEERINGCONTROLLER_H

#include "../../hal/i_isfcarhal.h"

class SteeringController
{
public:
    SteeringController();
    uint16_t steeringAngleToPWM(uint16_t angle);
};

#endif // STEERINGCONTROLLER_H
