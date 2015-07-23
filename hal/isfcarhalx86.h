#ifndef ISFCARHALX86_H
#define ISFCARHALX86_H


#include <QObject>
#include "i_isfcarhal.h"
#include <cmath>
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
    int16_t getAverageSpeed(void);
    uint16_t getUsTime(void);
    uint16_t writeDataToBrainBoard(uint8_t* data, uint16_t len);
    GPIO_STATE getGPIOState(GPIO_PIN pin);
    bool isPWMInValid(void);
    uint16_t getPWMInValue(PWM_INPUT pwm);
    void writeDebugLog(const char* data);

    //HardwareModels
    IMotor *_motor;
    ISteering *_steering;

    //HAL Manipulation Functions
    void addUsTime(uint16_t us);
    uint16_t getMotorPWM();
    uint16_t getSteeringAnglePWM();
    uint16_t getGPIOs();
    void manipulatePWMInValid(bool valid);
    void manipulatePWMIn(PWM_INPUT pwm, uint16_t val);
    void manipulateGPIOIn(GPIO_INPUT gpio, GPIO_STATE state);
private:
    uint16_t _gpioStates;
    uint16_t _currentMotorPWM;
    uint16_t _currentSteeringAnglePWM;
    uint16_t _currentPWMInSteering;
    uint16_t _currentPWMInSpeed;
    bool     _isPWMInValid;
    uint16_t _gpioInputStates;
signals:
    void sigDataToBrainBoard(QByteArray data);
    void sigDebugLog(QString str);
};

#endif // ISFCARHALX86_H
