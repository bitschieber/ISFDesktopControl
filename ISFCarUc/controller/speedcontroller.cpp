/*
 * SpeedController.cpp
 *
 *  Created on: 21.05.2015
 *      Author: Alexander
 */

#include "SpeedController.h"

PIController controller(0.9, 0.7);
//HallSensor hall = 0;

SpeedController::SpeedController(I_ISFCarHAL *hal) {
    this->_hal = hal;

	reset();
}

SpeedController::~SpeedController() {
	// TODO Auto-generated destructor stub
}

void SpeedController::reset(void) {
	controller.reset();
    this->currentPWM = PWM_NEUTRAL;
	this->_currentAdaptiveDelta = 0;
}

uint32_t SpeedController::updateSpeedPWM(uint32_t desiredPWM) {

    //this->_hallSensor->check();

	//if(desiredPWM>1600)
		//desiredPWM = 1500;

	uint32_t newPWM = 1500;

    /*
	if (desiredPWM < 1350)
		desiredPWM = 1350;
	else if (desiredPWM > PWM_MAX)
		desiredPWM = PWM_MAX;
        */

	/*
	 if (currentPWM > desiredPWM) {
	 _currentAdaptiveDelta = (currentPWM - desiredPWM) / 2;
	 newPWM = currentPWM - (_currentAdaptiveDelta * 1);
	 } else if (currentPWM < desiredPWM) {
	 _currentAdaptiveDelta = (desiredPWM - currentPWM) / 8;
	 newPWM = currentPWM + _currentAdaptiveDelta;
	 } else

	 */
	//currentPWM = newPWM;
	newPWM = desiredPWM;

    //this->_pwmController->setPWMValue(this->_speedPWMChID, newPWM);

	return newPWM;

}


int32_t SpeedController::getCurrentSpeed() {
    return this->_hal->getCurrentSpeed();
}

int32_t SpeedController::getAverageSpeed() {
    return this->_hal->getAverageSpeed();
}


int16_t SpeedController::speedToPWM(int32_t speed) {



    float speedError = (float(speed) - float(_hal->getAverageSpeed())) / float(SPEED_MAX - SPEED_MIN);


    float pwmRange = PWM_MAX - PWM_MIN;

    //V1
    //float speedRange =  SPEED_MAX - SPEED_MIN;
    //float factor = pwmRange / speedRange;
    //currentPWM = currentPWM + ((factor* abs(speed))*(speedError*0.9));

    //V2
    currentPWM = currentPWM + (pwmRange * (speedError*0.5));


    //this->currentPWM




    return currentPWM;
}

int16_t SpeedController::speedToPWM2(int32_t speed) {

    int16_t newPWM = 1500;
    /*
    float speedError = (float(speed) - float(_hal->getAverageSpeed())) / float(SPEED_MAX - SPEED_MIN);
    //float speedError = (float(speed) - float(hall.getCurrentSpeed())) / float(SPEED_MAX - SPEED_MIN);

    // Old Version
    // float pwmStep = speedError * (SERVO_MAX - SERVO_MIN) * 0.05;
    // currentPwm += pwmStep;

    // Controller Version
    float targetPwm = currentPWM + speedError * (SERVO_MAX - SERVO_MIN);
    currentPWM = SERVO_MIN + controller.tick((targetPwm - currentPWM));
    newPWM = currentPWM;

    */
    return newPWM;
}

