#ifndef I_ISFCARHAL_H
#define I_ISFCARHAL_H

#include <inttypes.h>
#include "isfdata.h"

enum GPIO_PIN{GPIO_PIN01 = 0,GPIO_PIN02 = 1,GPIO_PIN03 = 2,GPIO_PIN04 = 3,GPIO_PIN05 = 4,GPIO_PIN06 = 5,GPIO_PIN07 = 6,GPIO_PIN08 = 7};
enum GPIO_STATE{GPIO_RESET = 0, GPIO_SET = 1};
enum PWM_INPUT{PWM_IN_STEERING, PWM_IN_SPEED};


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
    virtual uint16_t writeDataToBrainBoard(uint8_t* data, uint16_t len);
    virtual void writeGPIO(GPIO_STATE state, GPIO_PIN pin);
    virtual GPIO_STATE getGPIOState(GPIO_PIN pin);
    virtual bool isPWMInValid(void);
    virtual uint16_t getPWMInValue(PWM_INPUT pwm);
    virtual void writeDebugLog(const char* data);
};

#endif // I_ISFCARHAL_H
