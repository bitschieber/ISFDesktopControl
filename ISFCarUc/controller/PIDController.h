/*
 * PIDController.h
 *
 *  Created on: 11.06.2015
 *      Author: Alexander
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

#include <inttypes.h>
/*
class PIDController {
public:
	PIDController(float k_p, float k_i);
	virtual ~PIDController();
	float tick_p(int32_t error);
	float tick_pi(int32_t error);
private:
	float K_p;
	float K_i;
	int32_t esum;
	float K_d;
	int32_t eold;
};
*/

class PController {
  float K_p;

  public:
    PController(float);
    float tick(int32_t);
};

class PIController:public PController {
  float K_i;
  int32_t esum;

  public:
    PIController(float, float);
    float tick(int32_t);
	void reset(void);
};

class PIDController:public PIController {
  float K_d;
  int32_t eold;

  public:
    PIDController(float, float, float);
    float tick(int32_t);
};

#endif /* PIDCONTROLLER_H_ */
