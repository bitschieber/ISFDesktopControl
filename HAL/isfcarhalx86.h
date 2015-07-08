#ifndef ISFCARHALX86_H
#define ISFCARHALX86_H


#include <QObject>
#include "i_isfcarhal.h"
#include <math.h>
#include "hardware/motor/motorxtec1.h"
#include "hardware/steering/steeringtrf417.h"

class ISFCarHALx86: public QObject,public I_ISFCarHAL
{
    Q_OBJECT
public:
    ISFCarHALx86();

    /*
     * HAL Interfaces
     */
    void writeMotorPWM(uint16_t pwm);
    void writeSteeringPWM(uint16_t pwm);
    void writeGPIO(GPIO_STATE state, GPIO_PIN pin);
    int16_t getCurrentSpeed(void);
    int16_t getAverageSpeed(void);
    int16_t getCurrentSteeringAngle(void);
    int16_t getDesiredSpeed(void);
    int16_t getDesiredSteeringAngle(void);
    uint16_t getUsTime(void);
    uint16_t writeDataToBrainBoard(uint8_t* data, uint16_t len);
    GPIO_STATE getGPIOState(GPIO_PIN pin);
    bool isPWMInValid(void);
    uint16_t getPWMInValue(PWM_INPUT pwm);
    void writeDebugLog(const char* data);

    //HardwarModels
    IMotor *_motor;
    ISteering *_steering;

    //HAL Manipulation Functions
    void addUsTime(uint16_t us);
    void setDesiredSpeed(int16_t speed);
    void setDesiredSteeringAngle(int16_t angle);
    uint16_t getMotorPWM();
    uint16_t getSteeringAnglePWM();
    uint16_t getGPIOs();
    void setPWMInValid(bool valid);
    void setPWMIn(PWM_INPUT pwm, uint16_t val);

    //HAL Manipulation Variables
    int16_t _desiredSpeed;
    int16_t _desiredSteeringAngle;
    int16_t _currentSpeed;
    int16_t _currentSteeringAngle;
private:
    uint16_t _gpioStates;
    uint32_t _currentUsTime;
    uint16_t _currentMotorPWM;
    uint16_t _currentSteeringAnglePWM;
    uint16_t _currentPWMInSteering;
    uint16_t _currentPWMInSpeed;
    bool     _isPWMInValid;
signals:
    void sigDataToBrainBoard(QByteArray data);
    void sigDebugLog(QString str);
};

#endif // ISFCARHALX86_H
