/*******************************************************************************
 * PROJECT		 Tesla Model Z Prototype
 * AUTHOR(S)	 David Leger
 * 				     Dylan Wood
 * DATE			   10 Mar, 2017
 *
 * FILE NAME	  user_instructions.c
 * DESCRIPTION	Holds the hard-coded text for the PuTTY CLI.
 *
 *******************************************************************************/

#ifndef _INSTRUCTIONSC_
#define _INSTRUCTIONSC_

#include "string.h";
#include "./hw_interfaces.c"
#include "../config.c"

// TODO rewrite when functionality is implemented to match implementation.
void displayMainMenu() {
  cLog("\n\r");
  cLog("----------------------------------------------------------------------\n\r");
  cLog("| WELCOME TO TESLA MODEL Z CLI!                                      |\n\r");
  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("Here you can view the device's current configuration and a virtual \n\r");
  cLog("version of the user manual.\n\n\r");
  cLog("Select one of the following options:\n\r");
  cLog("\t [1] Show current configuration overview.\n\r");
  cLog("\t [2] Show User Manual.\n\r");
  cLog("\t [3] Show Tesla Logo.\n\r");
  cLog("\t [0] Quit the Tesla Model Z Console.\n\r");
}

void displayCurrentConfig () {
  char light[80];
  char lightBar[80];
  char speed[80];
  char speedBar[80];
  sprintf(light, "\tMIN: %d\t\tMAX: %d\n\r\n\r", MIN_LIGHT_INTENSITY, MAX_LIGHT_INTENSITY);
  sprintf(speed, "\tMIN: %d\t\tMAX: %d\n\r\n\r", MIN_SPEED, MAX_SPEED);

  // Chart for speed and light intensity.
  for(int i = 0; i < 10; i++) {
    if (i >= MIN_LIGHT_INTENSITY && i <= MAX_LIGHT_INTENSITY) {
      lightBar[i] = '|';
    } else {
      lightBar[i] = '-';
    }

    if (i >= MIN_SPEED && i <= MAX_SPEED) {
      speedBar[i] = '|';
    } else {
      speedBar[i] = '-';
    }
  }

  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("CURRENT CONFIGUATION \n\n\r");
  cLog("Light Intensity Range: \n\r");
  cLog(light);
  cLog("0123456789\n\r");
  cLog(lightBar);
  cLog("\n\n\rLight intensity is measured on a scale of 0 to 9 where 0 is no\n\r");
  cLog("detectable light and 9 is the maximum detectable light.\n\n\n\r");
  cLog("Speed Range: \n\r");
  cLog(speed);
  cLog("0123456789\n\r");
  cLog(speedBar);
  cLog("\n\n\rSpeed range is measured on a scale of 0 to 9 where 0 is stopped\n\r");
  cLog("and 9 is the maximum speed.\n\n\r");
  cLog("----------------------------------------------------------------------\n\n\r");
}

void displayUserManual () {
  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("USER MANUAL\n\n\r");
  // NOTE removed for printing. Displays abridges User Manual.
  cLog("----------------------------------------------------------------------\n\n\r");
}

void displayAsciiLogo () {
  cLog("----------------------------------------------------------------------\n\n\r");
  // NOTE removed for printing. Displays ASCII art of the Tesla logo.
  cLog("----------------------------------------------------------------------\n\n\r");
}

#endif
