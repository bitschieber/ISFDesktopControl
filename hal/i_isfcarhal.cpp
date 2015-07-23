#include "i_isfcarhal.h"

I_ISFCarHAL::I_ISFCarHAL()
{
    this->_desiredSpeed = 0;
    this->_desiredSteeringAngle = 0;
    this->_currentSpeed = 0;
    this->_currentSteeringAngle = 0;
}

int16_t I_ISFCarHAL::getCurrentSpeed(void){
    return 0;
}
void I_ISFCarHAL::setCurrentSpeed(int16_t speed)
{
    this->_currentSpeed = speed;
}

int16_t I_ISFCarHAL::getAverageSpeed(void){
    return  0;
}

int16_t I_ISFCarHAL::getCurrentSteeringAngle(void){
    return 0;
}
void I_ISFCarHAL::setCurrentSteeringAngle(int16_t angle)
{
    this->_currentSteeringAngle = angle;
}


int16_t I_ISFCarHAL::getDesiredSpeed(void)
{
    return this->_desiredSpeed;
}

int16_t I_ISFCarHAL::getDesiredSteeringAngle(void)
{
    return this->_desiredSteeringAngle;
}

void I_ISFCarHAL::setDesiredSpeed(int16_t speed)
{
    _desiredSpeed = speed;
}

void I_ISFCarHAL::setDesiredSteeringAngle(int16_t angle)
{
   _desiredSteeringAngle = angle;
}

uint16_t I_ISFCarHAL::getUsTime(void){
    return 0;
}
