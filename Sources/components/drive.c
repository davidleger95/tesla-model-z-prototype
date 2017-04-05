
/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	drive.c
 * DESCRIPTION	Puts the device in drive mode. When this function runs the
 * 				device will sense light and change velocity according to the
 * 				current configuration.
 *
 *******************************************************************************/

#ifndef _DRIVEC_
#define _DRIVEC_

#include "math.h"
#include "../utils/hw_interfaces.c"
#include "./../config.c"

void drive () {
  greenLED(1);
  int light_val = 0;
  int speed = 0;
  int range = MAX_LIGHT_INTENSITY - MIN_LIGHT_INTENSITY;
  //Device stays in drive mode until device is hard reset
  //Continuously read ADC and output to DAC

  //SET THIS WHILE TO 1
  while(1) {

	light_val = getLightVal();

	// Normalize light intensity so that it is within the configured range.
	if (light_val < MIN_LIGHT_INTENSITY) {
	  speed = 0;
	} else if (light_val > MAX_LIGHT_INTENSITY) {
	  speed = 9;
	} else {
	  speed = (light_val - MIN_LIGHT_INTENSITY) * (10 / (floor(range + 1)));
	}

	// Restrict speed to configured range.
	if (speed < MIN_SPEED) {
	  speed = MIN_SPEED;
	} else if (speed > MAX_SPEED) {
	  speed = MAX_SPEED;
	}
	setMotorSpeed(speed);
	DelayFunction();
  }

  while(0){
	  light_val = getLightVal();
	  DelayFunction();
  }
 // setMotorSpeed(2);
  while(1);


  // Will never reach, device will be in drive mode until it is reset
  greenLED(0);
}

#endif
