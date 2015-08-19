#ifndef I_ISFCARHAL_H
#define I_ISFCARHAL_H

#include <inttypes.h>
#include "isfdata.h"

enum GPIO_PIN{GPIO_PIN01 = 0,GPIO_PIN02 = 1,GPIO_PIN03 = 2,GPIO_PIN04 = 3,GPIO_PIN05 = 4,GPIO_PIN06 = 5,GPIO_PIN07 = 6,GPIO_PIN08 = 7};

enum GPIO_INPUT{
    GPIO_IN_USERBUTTON_01,
    GPIO_IN_USERBUTTON_02
};

enum GPIO_STATE{GPIO_RESET = 0, GPIO_SET = 1, GPIO_TOGGLE = 2};
enum PWM_INPUT{PWM_IN_STEERING, PWM_IN_SPEED};

enum ADC_SRC{ADC_SRC_1, ADC_SRC_2};


class I_ISFCarHAL
{


public:
    I_ISFCarHAL();
    virtual void writeMotorPWM(uint16_t pwm) = 0;
    virtual void writeSteeringPWM(uint16_t pwm) = 0;
    virtual int16_t getCurrentSpeed(void);
    virtual int16_t getAverageSpeed(void);
    virtual int16_t getCurrentSteeringAngle(void);
    //virtual int16_t getDesiredSpeed(void);
    //virtual int16_t getDesiredSteeringAngle(void);
    virtual uint16_t getUsTime(void);
    virtual uint16_t writeDataToBrainBoard(uint8_t* data, uint16_t len) = 0;
    virtual void writeGPIO(GPIO_STATE state, GPIO_PIN pin) = 0;
    //virtual void toggleGPIO(GPIO_PIN pin);
    virtual GPIO_STATE getGPIOState(GPIO_PIN pin) = 0;
    virtual bool isPWMInValid(void) = 0;
    virtual uint16_t getPWMInValue(PWM_INPUT pwm) = 0;
    virtual void writeDebugLog(const char* data) = 0;
    virtual uint16_t readADCValue(ADC_SRC src) = 0;

    int16_t getDesiredSpeed(void);
    int16_t getDesiredSteeringAngle(void);
    void setDesiredSpeed(int16_t speed);
    void setDesiredSteeringAngle(int16_t angle);
private:
    int16_t _desiredSpeed;
    int16_t _desiredSteeringAngle;
    int16_t _currentSpeed;
    int16_t _currentSteeringAngle;
protected:
    void setCurrentSpeed(int16_t speed);
    void setCurrentSteeringAngle(int16_t angle);
    uint32_t _currentUsTime;
};

#endif // I_ISFCARHAL_H
