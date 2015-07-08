/*
 * SpeedController.h
 *
 *  Created on: 21.05.2015
 *      Author: Alexander
 */

#ifndef SPEEDCONTROLLER_H_
#define SPEEDCONTROLLER_H_

#include "pidcontroller.h"
#include "../../hal/i_isfcarhal.h"
#include <math.h>

#define SPEED_DELTA_PWM_STEP_UP		10
#define SPEED_DELTA_PWM_STEP_DOWN	10

class SpeedController {

//#define PWM_MAX 1750
#define PWM_NEUTRAL              1500     // PWM
//#define TARGET_SPEED             1500      // mm/s
#define SPEED_MIN                -4000
#define SPEED_MAX                4000
#define PWM_MIN                1000
#define PWM_MAX                2000

public:
    SpeedController(I_ISFCarHAL *hal);
	virtual ~SpeedController();
	uint32_t updateSpeedPWM(uint32_t desiredPWM);
	int16_t speedToPWM(int32_t speed);
    int16_t speedToPWM2(int32_t speed);
	int32_t getCurrentSpeed();
	int32_t getAverageSpeed();
	void reset(void);

private:
    //PWMController* _pwmController;
    //PWMController::PWM_OUTPUT_CHANNEL _speedPWMChID;
	uint32_t currentPWM;
	uint8_t _currentAdaptiveDelta;
    //HallSensor* _hallSensor;
    I_ISFCarHAL *_hal;
};
#endif /* SPEEDCONTROLLER_H_ */
