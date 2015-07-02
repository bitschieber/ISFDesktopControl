#include "isfcarhalx86.h"

ISFCarHALx86::ISFCarHALx86()
{
    //GPIO initalisieren
    this->writeGPIO(GPIO_RESET,GPIO_PIN01);
    this->writeGPIO(GPIO_RESET,GPIO_PIN02);
    this->writeGPIO(GPIO_SET,GPIO_PIN03);
    this->writeGPIO(GPIO_RESET,GPIO_PIN04);

    _desiredSpeed = 0;
    _desiredSteeringAngle = 0;
    _currentSpeed = 0;
    _currentSteeringAngle = 0;
    _currentUsTime = 0;
}

void ISFCarHALx86::writeMotorPWM(uint16_t pwm){

    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -4000;
    float maxAngle = 4000;

    int pwm2 = (maxPWM-minPWM)/2;
    float anglePWM = (pwm2/ abs(minAngle));

    this->_currentSpeed = (pwm - 1500) / anglePWM;
}

void ISFCarHALx86::writeSteeringPWM(uint16_t pwm){
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -20;
    float maxAngle = 20;

    int pwm2 = (maxPWM-minPWM)/2;
    float anglePWM = (pwm2/ abs(minAngle));

    this->_currentSteeringAngle = (pwm - 1500) / anglePWM;
}

void ISFCarHALx86::writeGPIO(GPIO_STATE state, GPIO_PIN pin)
{

}

GPIO_STATE ISFCarHALx86::getGPIOState(GPIO_PIN pin)
{
    return GPIO_RESET;
}

int16_t ISFCarHALx86::getCurrentSpeed(void){
    return _currentSpeed;
}

int16_t ISFCarHALx86::getAverageSpeed(void){
    return  _currentSteeringAngle;
}

int16_t ISFCarHALx86::getCurrentSteeringAngle(void)
{
    return _currentSteeringAngle;
}

int16_t ISFCarHALx86::getDesiredSpeed(void)
{
    return _desiredSpeed;
}

int16_t ISFCarHALx86::getDesiredSteeringAngle(void)
{
    return _desiredSteeringAngle;
}

uint16_t ISFCarHALx86::getUsTime(void){
    return _currentUsTime;
}

void ISFCarHALx86::addUsTime(uint16_t us){
    _currentUsTime += us;
}

void ISFCarHALx86::setDesiredSpeed(int16_t speed)
{
    _desiredSpeed = speed;
}

void ISFCarHALx86::setDesiredSteeringAngle(int16_t angle)
{
   _desiredSteeringAngle = angle;
}
