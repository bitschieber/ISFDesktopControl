/*
 * PIDController.cpp
 *
 *  Created on: 11.06.2015
 *      Author: Alexander
 */

#include "pidcontroller.h"
/*
PIDController::PIDController(float k_p, float k_i) {
	// TODO Auto-generated constructor stub K_i = k_i;
	  esum = 0.0;
}

PIDController::~PIDController() {
	// TODO Auto-generated destructor stub
}

*/

PController::PController(float k_p) {
  K_p = k_p;
}

float PController::tick(int32_t error) {
  return error * K_p;
}

// PI Controller constructor
PIController::PIController(float k_p, float k_i) : PController(k_p) {
  K_i = k_i;
  //esum = 0.0;
  reset();
}

float PIController::tick(int32_t error) {
  esum += error;
  int32_t out = PController::tick(error) + K_i * esum * (1.0/100.0) /*T_a*/;
  return out;
}

void PIController::reset(void){
	esum = 0;
}

/* Aus dem Arduino Projekt => ACHTUNG, laeuft nicht
// PID Controller constructor
PIDController::PIDController(float k_p, float k_i, float k_d) : PIController(k_p, k_i) {
  K_d = k_d;
  eold = 0.0;
}
float PIDController::tick(int32_t error) {
  int32_t out = PIController::tick(error) + K_d * (error - eold) / (1.0/100.0); // T_a
  eold = error;
  return out;
}
*/

