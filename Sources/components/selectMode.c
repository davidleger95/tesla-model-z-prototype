/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	selectMode.c
 * DESCRIPTION	Let's the user select CLI mode or drive mode from idle mode.
 *
 *******************************************************************************/
#ifndef _SELECTMODEC_
#define _SELECTMODEC_

#include "../utils/hw_interfaces.c"
#include "./cli.c"
#include "./drive.c"


void selectMode () {
	if(cli_mode) {
		  redLED(0);
		  cli();
		  redLED(1);
		  cli_mode = 0;
	} else if(drive_mode) {
		  redLED(0);
		  drive();
		  drive_mode = 0;
	}
}

#endif
