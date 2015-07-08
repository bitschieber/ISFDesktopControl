#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include <inttypes.h>
#include <math.h>

class SpeedController
{
public:
    SpeedController();
    uint16_t update(int16_t desiredSpeed, int16_t currentSpeed);

private:
    uint16_t _currentPWM;
};

#endif // SPEEDCONTROLLER_H
