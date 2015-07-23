#include "steeringcontroller.h"
#include <cmath>

SteeringController::SteeringController()
{

}

uint16_t SteeringController::steeringAngleToPWM(uint16_t angle)
{
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -20;
    //float maxAngle = 20;

    int pwm = (maxPWM-minPWM)/2;
    float anglePWM = (pwm/ std::abs(minAngle));

    return uint16_t(1500 + (anglePWM * angle));
}

