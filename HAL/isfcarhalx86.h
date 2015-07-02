#ifndef ISFCARHALX86_H
#define ISFCARHALX86_H


#include "i_isfcarhal.h"
#include <math.h>

class ISFCarHALx86: public I_ISFCarHAL
{

public:
    ISFCarHALx86();
    void writeMotorPWM(uint16_t pwm);
    void writeSteeringPWM(uint16_t pwm);
    void writeGPIO(GPIO_STATE state, GPIO_PIN pin);
    int16_t getCurrentSpeed(void);
    int16_t getAverageSpeed(void);
    int16_t getCurrentSteeringAngle(void);
    int16_t getDesiredSpeed(void);
    int16_t getDesiredSteeringAngle(void);
    uint16_t getUsTime(void);
    GPIO_STATE getGPIOState(GPIO_PIN pin);


    //HAL Manipulation Functions
    void addUsTime(uint16_t us);
    void setDesiredSpeed(int16_t speed);
    void setDesiredSteeringAngle(int16_t angle);

    //HAL Manipulation Variables
    int16_t _desiredSpeed;
    int16_t _desiredSteeringAngle;
    int16_t _currentSpeed;
    int16_t _currentSteeringAngle;
private:
    uint16_t _gpioStates;
    uint32_t _currentUsTime;
};

#endif // ISFCARHALX86_H
