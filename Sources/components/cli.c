/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	cli.c
 * DESCRIPTION	Launches the Tesla Model Z Prototype CLI via the UART0 port.
 *
 *******************************************************************************/

#ifndef _CONFIGC_
#define _CONFIGC_

#include "../utils/user_instructions.c"
#include "../utils/hw_interfaces.c"
#include "./setLightRange.c"
int configure = 1;
int lightMax = 255;

int speedMin = 0;
int speedMax = 0;

void setSpeedRange () {
  cLog("setSpeedRange\n\r");
}

void setDirection () {
  cLog("setDirection\n\r");
}

void resetDefault () {
  cLog("resetDefault\n\r");
}

void quit () {
  cLog("Quitting...\n\r");
  // TODO save config data
  cLog("OK to disconnect device.\n\r");
  configure = 0;
}

void cli () {
  blueLED(1);
  configure = 1;
  while (configure) {
    displayMainMenu();
    switch (cGetValid("123450")) {
      case '1': setLightRange(); break;
      case '2': setSpeedRange(); break;
      case '3': setDirection(); break;
      case '4': resetDefault(); break;
      case '5': displayUserManual(); break;
      case '0': quit(); break;
    }
  }
  blueLED(0);
}

#endif
