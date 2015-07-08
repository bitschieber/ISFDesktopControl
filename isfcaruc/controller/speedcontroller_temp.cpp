#include "speedcontroller.h"

SpeedController::SpeedController()
{
    _currentPWM = 1500;
}

uint16_t SpeedController::update(int16_t desiredSpeed, int16_t currentSpeed)
{
    uint16_t pwmMin = 1200;
    uint16_t pwmMax = 1800;
    uint16_t pwmNeutral = 1500;

    /*
     *0 -> 2000
     *
     */
    int16_t minSpeed = -4000;
    int16_t maxSpeed = 4000;


    float pwmRange = pwmMax - pwmMin; //600
    float speedRange = maxSpeed - minSpeed; //8000

    float norm = pwmRange/speedRange;
    float pwmOff = norm*desiredSpeed;

    int16_t desiredPWM = pwmNeutral + pwmOff;
    int16_t err = desiredPWM - _currentPWM;

    _currentPWM = _currentPWM + (err/2);

    /*
    float err = 1;
    if(curPos>0)
    {
        err = range/curPos;
    }
    */


    /*
    float dif = desiredSpeed - currentSpeed;
    float error = abs(desiredSpeed) / abs(currentSpeed);
    */

    //_currentPWM = _currentPWM*error;
    return _currentPWM;
}

