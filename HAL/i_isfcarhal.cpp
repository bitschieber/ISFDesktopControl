#include "i_isfcarhal.h"

I_ISFCarHAL::I_ISFCarHAL()
{

}


void I_ISFCarHAL::writeMotorPWM(uint16_t pwm){

}

void I_ISFCarHAL::writeSteeringPWM(uint16_t pwm){

}

int16_t I_ISFCarHAL::getCurrentSpeed(void){
    return 0;
}

int16_t I_ISFCarHAL::getAverageSpeed(void){
    return  0;
}

int16_t I_ISFCarHAL::getCurrentSteeringAngle(void){
    return 0;
}


int16_t I_ISFCarHAL::getDesiredSpeed(void)
{
    return 0;
}

int16_t I_ISFCarHAL::getDesiredSteeringAngle(void)
{
    return 0;
}

uint16_t I_ISFCarHAL::getUsTime(void){
    return 0;
}

void I_ISFCarHAL::writeGPIO(GPIO_STATE state, GPIO_PIN pin)
{
}

GPIO_STATE I_ISFCarHAL::getGPIOState(GPIO_PIN pin)
{
    return GPIO_RESET;
}

uint16_t I_ISFCarHAL::writeDataToBrainBoard(uint8_t* data, uint16_t len)
{
    return 0;
}

bool I_ISFCarHAL::isPWMInValid(void)
{
    return false;
}

uint16_t I_ISFCarHAL::getPWMInValue(PWM_INPUT pwm)
{
    return 0;
}

void I_ISFCarHAL::writeDebugLog(const char* data)
{

}

