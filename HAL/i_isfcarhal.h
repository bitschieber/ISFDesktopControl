#ifndef I_ISFCARHAL_H
#define I_ISFCARHAL_H

#include <inttypes.h>
#include "isfdata.h"

enum GPIO_PIN{GPIO_PIN01 = 1,GPIO_PIN02 = 2,GPIO_PIN03 = 4,GPIO_PIN04 = 8,GPIO_PIN05 = 16,GPIO_PIN06 = 32,GPIO_PIN07 = 64,GPIO_PIN08 = 128};
enum GPIO_STATE{GPIO_RESET = 0, GPIO_SET = 1};

class I_ISFCarHAL
{


public:
    I_ISFCarHAL();
    virtual void writeMotorPWM(uint16_t pwm);
    virtual void writeSteeringPWM(uint16_t pwm);
    virtual int16_t getCurrentSpeed(void);
    virtual int16_t getAverageSpeed(void);
    virtual int16_t getCurrentSteeringAngle(void);
    virtual int16_t getDesiredSpeed(void);
    virtual int16_t getDesiredSteeringAngle(void);
    virtual uint16_t getUsTime(void);
    virtual void writeGPIO(GPIO_STATE state, GPIO_PIN pin);
    virtual GPIO_STATE getGPIOState(GPIO_PIN pin);
};

#endif // I_ISFCARHAL_H
