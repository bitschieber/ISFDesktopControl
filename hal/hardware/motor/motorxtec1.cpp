#include "motorxtec1.h"

MotorXTEC1::MotorXTEC1()
{

}

uint16_t MotorXTEC1::calcSpeedFromPWM(uint16_t pwm){
    int minPWM = 1000;
    int maxPWM = 2000;
    float minSpeed = -4000;
    float maxSpeed = 4000;

    int pwm2 = (maxPWM-minPWM)/2;
    float anglePWM = (pwm2/ std::abs(minSpeed));

    return (pwm - 1500) / anglePWM;
}

