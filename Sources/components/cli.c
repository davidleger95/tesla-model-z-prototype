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
#include "../utils/texts.c"
int loop = 1;

void checkCurrentConfig () {
  displayCurrentConfig();
  cLog("[0] Back to Main Menu.\n\r");
  cGetValid("0");
}

void userManual () {
  displayUserManual();
  cLog("[0] Back to Main Menu.\n\r");
  cGetValid("0");
}

void asciiLogo () {
  displayAsciiLogo();
  cLog("[0] Back to Main Menu.\n\r");
  cGetValid("0");
}

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
    switch (cGetValid("1230")) {
      case '1': checkCurrentConfig(); break;
      case '2': userManual(); break;
      case '3': asciiLogo(); break;
      case '0': quit(); break;
    }
  }
  blueLED(0);
}
#endif