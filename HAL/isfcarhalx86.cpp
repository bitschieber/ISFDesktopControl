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

    this->_desiredSpeed = 0;
    this->_desiredSteeringAngle = 0;
    this->_currentSpeed = 0;
    this->_currentMotorPWM = 0;
    this->_currentSteeringAngle = 0;
    this->_currentSteeringAnglePWM = 0;
    this->_currentUsTime = 0;
    this->_gpioStates = 0;

    this->_isPWMInValid = false;
    this->_currentPWMInSteering = 0;
    this->_currentPWMInSpeed = 0;
}

void ISFCarHALx86::writeMotorPWM(uint16_t pwm){
    this->_currentMotorPWM = pwm;
    this->_currentSpeed =  _motor->calcSpeedFromPWM(this->_currentMotorPWM);
}

void ISFCarHALx86::writeSteeringPWM(uint16_t pwm){
    this->_currentSteeringAnglePWM = pwm;
    this->_currentSteeringAngle = _steering->calcSteeringAngleFromPWM(this->_currentSteeringAnglePWM);
}

void ISFCarHALx86::writeGPIO(GPIO_STATE state, GPIO_PIN pin)
{
    if(state == GPIO_SET){
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

int16_t ISFCarHALx86::getCurrentSpeed(void){
    return _currentSpeed;
}

int16_t ISFCarHALx86::getAverageSpeed(void){
    return  _currentSpeed;
}

int16_t ISFCarHALx86::getCurrentSteeringAngle(void)
{
    return _currentSteeringAngle;
}

int16_t ISFCarHALx86::getDesiredSpeed(void)
{
    return _desiredSpeed;
}

int16_t ISFCarHALx86::getDesiredSteeringAngle(void)
{
    return _desiredSteeringAngle;
}

uint16_t ISFCarHALx86::getUsTime(void){
    return _currentUsTime;
}

void ISFCarHALx86::addUsTime(uint16_t us){
    _currentUsTime += us;
}

void ISFCarHALx86::setDesiredSpeed(int16_t speed)
{
    _desiredSpeed = speed;
}

void ISFCarHALx86::setDesiredSteeringAngle(int16_t angle)
{
   _desiredSteeringAngle = angle;
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

void ISFCarHALx86::setPWMIn(PWM_INPUT pwm, uint16_t val)
{
    if(pwm == PWM_IN_STEERING)
        this->_currentPWMInSteering = val;
    else if(pwm == PWM_IN_SPEED)
        this->_currentPWMInSpeed = val;
}

void ISFCarHALx86::setPWMInValid(bool valid)
{
    this->_isPWMInValid = valid;
}

void ISFCarHALx86::writeDebugLog(const char* data)
{

    QString d(data);
    emit sigDebugLog(d);

}
