/*
 * SpeedController.cpp
 *
 *  Created on: 21.05.2015
 *      Author: Alexander
 */

#include "speedcontroller.h"

PIController controller(0.9f, 0.7f);
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
    //currentPWM = currentPWM + ((factor* std::abs(speed))*(speedError*0.9));

    //V2
    currentPWM = currentPWM + uint32_t(pwmRange * (speedError*0.5));


    //this->currentPWM




    return currentPWM;
}

