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
  // TODO LOAD config data

  // TODO get light sensor value

  // TODO calculate settings based on configuration

  // TODO set motor value
  greenLED(0);
}

#endif
