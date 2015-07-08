#include "steeringcontroller.h"
#include <math.h>

SteeringController::SteeringController()
{

}

uint16_t SteeringController::steeringAngleToPWM(uint16_t angle)
{
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -20;
    float maxAngle = 20;

    int pwm = (maxPWM-minPWM)/2;
    float anglePWM = (pwm/ abs(minAngle));

    return 1500 + (anglePWM * angle);
}
