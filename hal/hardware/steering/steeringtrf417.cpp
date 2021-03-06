#include "steeringtrf417.h"

SteeringTRF417::SteeringTRF417()
{

}

uint16_t SteeringTRF417::calcSteeringAngleFromPWM(uint16_t pwm){
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -20;
    //float maxAngle = 20;

    int pwm2 = (maxPWM-minPWM)/2;
    float anglePWM = (pwm2/ std::abs(minAngle));

    return uint16_t((pwm - 1500) / anglePWM);
}

