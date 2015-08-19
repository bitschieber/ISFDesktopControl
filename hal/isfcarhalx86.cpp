#include "isfcarhalx86.h"

ISFCarHALx86::ISFCarHALx86()
{
    //GPIO initalisieren
    /*
    this->writeGPIO(GPIO_RESET,GPIO_PIN01);
    this->writeGPIO(GPIO_RESET,GPIO_PIN02);
    this->writeGPIO(GPIO_SET,GPIO_PIN03);
    this->writeGPIO(GPIO_RESET,GPIO_PIN04);
    */

    //Initialize Hardware
    _motor = new MotorXTEC1();
    _steering = new SteeringTRF417();

    this->_currentMotorPWM = 0;
    this->_currentSteeringAnglePWM = 0;
    this->_currentUsTime = 0;
    this->_gpioStates = 0;
    this->_gpioInputStates = 0;

    this->_isPWMInValid = false;
    this->_currentPWMInSteering = 0;
    this->_currentPWMInSpeed = 0;
}

void ISFCarHALx86::writeMotorPWM(uint16_t pwm){
    this->_currentMotorPWM = pwm;
    this->setCurrentSpeed(_motor->calcSpeedFromPWM(this->_currentMotorPWM));
}

void ISFCarHALx86::writeSteeringPWM(uint16_t pwm){
    this->_currentSteeringAnglePWM = pwm;
    this->setCurrentSteeringAngle(_steering->calcSteeringAngleFromPWM(this->_currentSteeringAnglePWM));
}

void ISFCarHALx86::writeGPIO(GPIO_STATE state, GPIO_PIN pin)
{
    if(state == GPIO_SET){
        _gpioStates |= (1 << pin);
    }
    else if(state == GPIO_TOGGLE)
    {
        uint8_t cur = ( (_gpioStates) & (1<<(pin)) );
        if(cur>=1)
            _gpioStates &= ~(1 << pin);
        else
            _gpioStates |= (1 << pin);
    }
    else
    {
        _gpioStates &= ~(1 << pin);
    }
}

GPIO_STATE ISFCarHALx86::getGPIOState(GPIO_PIN pin)
{
    if(((_gpioStates >> pin) & 1)==1)
        return GPIO_SET;
    else
        return GPIO_RESET;
}
/*
int16_t ISFCarHALx86::getCurrentSpeed(void){
    return _currentSpeed;
}
*/
int16_t ISFCarHALx86::getAverageSpeed(void){
    return  this->getCurrentSpeed();
}

/*
int16_t ISFCarHALx86::getCurrentSteeringAngle(void)
{
    return this->getCurrentSteeringAngle();
}
*/

uint16_t ISFCarHALx86::getUsTime(void){
    return _currentUsTime;
}

void ISFCarHALx86::addUsTime(uint16_t us){
    _currentUsTime += us;
}

uint16_t ISFCarHALx86::getMotorPWM()
{
    return this->_currentMotorPWM;
}

uint16_t ISFCarHALx86::getSteeringAnglePWM()
{
    return this->_currentSteeringAnglePWM;
}

uint16_t ISFCarHALx86::getGPIOs()
{
    return this->_gpioStates;
}

uint16_t ISFCarHALx86::writeDataToBrainBoard(uint8_t* data, uint16_t len)
{
    QByteArray d;
    d.resize(len);
    memcpy(d.data(),data,len);
    emit sigDataToBrainBoard(d);

    return 0;
}

bool ISFCarHALx86::isPWMInValid(void)
{
    return this->_isPWMInValid;
}

uint16_t ISFCarHALx86::getPWMInValue(PWM_INPUT pwm)
{
    if(pwm == PWM_IN_STEERING)
        return this->_currentPWMInSteering;
    else if(pwm == PWM_IN_SPEED)
        return this->_currentPWMInSpeed;

    return 0;
}

void ISFCarHALx86::manipulatePWMIn(PWM_INPUT pwm, uint16_t val)
{
    if(pwm == PWM_IN_STEERING)
        this->_currentPWMInSteering = val;
    else if(pwm == PWM_IN_SPEED)
        this->_currentPWMInSpeed = val;
}

void ISFCarHALx86::manipulatePWMInValid(bool valid)
{
    this->_isPWMInValid = valid;
}

void ISFCarHALx86::writeDebugLog(const char* data)
{

    QString d(data);
    emit sigDebugLog(d);

}

//Returns the value in mV
uint16_t ISFCarHALx86::readADCValue(ADC_SRC src)
{
    if(src == ADC_SRC::ADC_SRC_1)
    {
        return _adc_src_1_val;
    }
    else if(src == ADC_SRC::ADC_SRC_2)
    {
        return _adc_src_2_val;
    }
    else
    {
        return 0;
    }
}

/*
 *HAL MANIPULATION
*/
void ISFCarHALx86::manipulateGPIOIn(GPIO_INPUT gpio, GPIO_STATE state)
{
    if(state == GPIO_SET){
        _gpioInputStates |= (1 << gpio);
    }
    else if(state == GPIO_TOGGLE)
    {
        uint8_t cur = ( (_gpioInputStates) & (1<<(gpio)) );
        if(cur>=1)
            _gpioInputStates &= ~(1 << gpio);
        else
            _gpioInputStates |= (1 << gpio);
    }
    else
    {
        _gpioInputStates &= ~(1 << gpio);
    }
}

void ISFCarHALx86::manipulateADC(ADC_SRC src, uint16_t val)
{
    if(src == ADC_SRC::ADC_SRC_1)
    {
        _adc_src_1_val = val;
    }
    else if(src == ADC_SRC::ADC_SRC_2)
    {
        _adc_src_2_val = val;
    }
}
