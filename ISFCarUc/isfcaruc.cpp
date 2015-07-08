#include "isfcaruc.h"
#include "QDebug"

uint32_t _mainLoopTimeStamp = 0;

ISFCarUc::ISFCarUc(I_ISFCarHAL *hal)
{
    this->_isfCarHAL = hal;
    _speedController = new SpeedController(this->_isfCarHAL);
}

void ISFCarUc::Start(void){
    while(1){
        if(this->_isfCarHAL->getUsTime()-_mainLoopTimeStamp >= 5){
            qDebug() << "MainLoop";
            _mainLoopTimeStamp = this->_isfCarHAL->getUsTime();
            //uint16_t newMotorPWM = _speedController->update(this->_isfCarHAL->getDesiredSpeed(),this->_isfCarHAL->getCurrentSpeed());
            uint16_t newMotorPWM = _speedController->speedToPWM(this->_isfCarHAL->getDesiredSpeed());
            this->_isfCarHAL->writeMotorPWM(newMotorPWM);
            uint16_t newSteeringPWM = steeringAngleToPWM(this->_isfCarHAL->getDesiredSteeringAngle());
            this->_isfCarHAL->writeSteeringPWM(newSteeringPWM);

            this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN01);
            this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN02);
            this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN04);
            this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN06);
            this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN07);

            _dataToBrainBoardHost.speed_mms = this->_isfCarHAL->getCurrentSpeed();
            _dataToBrainBoardHost.speed_pwm = newMotorPWM;
            _dataToBrainBoardHost.steering_angle_pwm = newSteeringPWM;
            _dataToBrainBoardHost.steering_angle = this->_isfCarHAL->getCurrentSteeringAngle();

            uint8_t data[sizeof(DATA_SET_UC_BRAIN_BOARD_t)];
            memcpy(data,&_dataToBrainBoardHost,sizeof(DATA_SET_UC_BRAIN_BOARD_t));
            this->_isfCarHAL->writeDataToBrainBoard(data,sizeof(DATA_SET_UC_BRAIN_BOARD_t));
        }
    }
}

/*
uint16_t ISFCarUc::speedToPWM(uint16_t speed)
{
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -4000;
    float maxAngle = 4000;

    int pwm = (maxPWM-minPWM)/2;
    float anglePWM = (pwm/ abs(minAngle));

    return 1500 + (anglePWM * speed);
}
*/

uint16_t ISFCarUc::steeringAngleToPWM(uint16_t angle)
{
    int minPWM = 1100;
    int maxPWM = 1900;
    float minAngle = -20;
    float maxAngle = 20;

    int pwm = (maxPWM-minPWM)/2;
    float anglePWM = (pwm/ abs(minAngle));

    return 1500 + (anglePWM * angle);
}

