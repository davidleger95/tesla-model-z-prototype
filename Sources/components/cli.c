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

#ifndef _CLIC_
#define _CLIC_

#include "../utils/user_instructions.c"
#include "../utils/hw_interfaces.c"
int loop = 1;

//TODO Refactor
void setSpeedRange () {
  cLog("setSpeedRange\n\r");
}

//TODO Refactor
void setDirection () {
  cLog("setDirection\n\r");
}

//TODO Refactor
void resetDefault () {
  cLog("resetDefault\n\r");
}

//TODO Refactor
void quit () {
  cLog("Quitting...\n\r");
  cLog("OK to disconnect device.\n\r");
  loop = 0;
}

void cli () {
  blueLED(1);
  loop = 1;
  while (loop) {
    displayMainMenu();
    switch (cGetValid("123450")) {
      //case '1': setLightRange(); break;
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
