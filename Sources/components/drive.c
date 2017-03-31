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

#include "../utils/hw_interfaces.c"

void drive () {
  greenLED(1);
  int light_val = 0;

  //Device stays in drive mode until device is hard reset
  //Continuously read ADC and output to DAC
  while(1) {
	  light_val = getLightVal();
	  DelayFunction();
	  setMotorSpeed(light_val);
  }

  // Will never reach, device will be in drive mode until it is reset
  greenLED(0);
}

#endif
