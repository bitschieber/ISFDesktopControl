#include "isfcaruc.h"

ISFCarUc::ISFCarUc(I_ISFCarHAL *hal)
{
    this->_isfCarHAL = hal;
    _speedController = new SpeedController(this->_isfCarHAL);
    _steeringController = new SteeringController();

    _timerMainLoop = new ISFTimer(this->_isfCarHAL,5);
    _timerLights = new ISFTimer(this->_isfCarHAL,100);
    _mainLoopTimeStamp = 0;

    this->_isfCarHAL->writeDebugLog("ISFCarUc initialized");
}

void ISFCarUc::stop(void){
    _running = false;
}

void ISFCarUc::start(void){
    _running = true;
    this->_isfCarHAL->writeDebugLog("ISFCarUc Start");
    while(_running){
        //if(this->_isfCarHAL->getUsTime()-_mainLoopTimeStamp >= 5){
            //_mainLoopTimeStamp = this->_isfCarHAL->getUsTime();
        if(_timerMainLoop->isElapsed())
        {
            this->_isfCarHAL->writeDebugLog("ISFCarUc run MainLoop");
            uint16_t newMotorPWM = 0;
            uint16_t newSteeringPWM = 0;

            if(this->_isfCarHAL->isPWMInValid()==true)
            {
                newMotorPWM = 0;
                newSteeringPWM = 0;

                /*
                this->_isfCarHAL->writeMotorPWM(newMotorPWM);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN01);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN02);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN03);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN04);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN05);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN06);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN07);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN08);
                */
            }
            else
            {
                newMotorPWM = _speedController->speedToPWM(this->_isfCarHAL->getDesiredSpeed());
                newSteeringPWM = _steeringController->steeringAngleToPWM(this->_isfCarHAL->getDesiredSteeringAngle());

                /*
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN01);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN02);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN03);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN04);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN05);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN06);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN07);
                this->_isfCarHAL->writeGPIO(GPIO_SET,GPIO_PIN08);
                */
            }

            if(_timerLights->isElapsed())
            {
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN01);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN02);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN03);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN04);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN05);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN06);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN07);
                this->_isfCarHAL->writeGPIO(GPIO_TOGGLE,GPIO_PIN08);
            }

            this->_isfCarHAL->writeMotorPWM(newMotorPWM);
            this->_isfCarHAL->writeSteeringPWM(newSteeringPWM);

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

