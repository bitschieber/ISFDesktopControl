#include "isfcaruc.h"
#include "QDebug"

uint32_t _mainLoopTimeStamp = 0;

ISFCarUc::ISFCarUc(I_ISFCarHAL *hal)
{
    this->_isfCarHAL = hal;
}

void ISFCarUc::Start(void){
    while(1){
        if(this->_isfCarHAL->getUsTime()-_mainLoopTimeStamp >= 5){
            qDebug() << "MainLoop";
            _mainLoopTimeStamp = this->_isfCarHAL->getUsTime();
            this->_isfCarHAL->writeMotorPWM(speedToPWM(this->_isfCarHAL->getDesiredSpeed()));
            this->_isfCarHAL->writeSteeringPWM(steeringAngleToPWM(this->_isfCarHAL->getDesiredSteeringAngle()));
        }
    }
}

uint16_t ISFCarUc::speedToPWM(uint16_t speed)
{
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -4000;
    float maxAngle = 4000;

    int pwm = (maxPWM-minPWM)/2;
    float anglePWM = (pwm/ abs(minAngle));

    return 1500 + (anglePWM * speed);
}

uint16_t ISFCarUc::steeringAngleToPWM(uint16_t angle)
{
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -20;
    float maxAngle = 20;

    int pwm = (maxPWM-minPWM)/2;
    float anglePWM = (pwm/ abs(minAngle));

    return 1500 + (anglePWM * angle);
}

