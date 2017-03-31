/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	user_instructions.c
 * DESCRIPTION	Holds the hard-coded text for the PuTTY CLI.
 *
 *******************************************************************************/

#ifndef _INSTRUCTIONSC_
#define _INSTRUCTIONSC_

#include "./hw_interfaces.c"

// TODO rewrite when functionality is implemented to match implementation.
void displayMainMenu() {
  cLog("\n\r");
  cLog("----------------------------------------------------------------------\n\r");
  cLog("| WELCOME TO TESLA MODEL Z CLI!                                   |\n\r");
  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("Here you can view the device's current configuration and a virtual \n\r");
  cLog("version of the user manual.\n\n\r");
  cLog("Select one of the following options:\n\r");
  cLog("\t [1] Show current configuration overview.\n\r");
  cLog("\t [2] Set light speed range.\n\r");
  cLog("\t [3] Set direction.\n\r");
  cLog("\t [4] Reset Default.\n\r");
  cLog("\t [5] View User Manual.\n\r");
  cLog("\t [0] Quit the Tesla Model Z Console.\n\r");
}

// NOTE this is out of scope but leave it until functionality is implemented.
void displaySetLightRangeInstructions () {
  cLog("\n\r");
  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("Set a value for the minimum light intensity that the device needs to\n\r");
  cLog("start moving. Choose from one of the following options:\n\r");
  cLog("\t [L] Low light.\n\r");
  cLog("\t [M] Medium light (default).\n\r");
  cLog("\t [H] High light.\n\r");
  cLog("\t [C] Cancel.\n\r");
  cLog("MIN LIGHT THRESHOLD: ");
}

// TODO write new options functions
void displaySetSpeedRangeInstructions () {
  //TODO write instructions
}

void displaySetDirectionInstructions () {
  //TODO write instructions
}

void displayResetInstructions () {
  //TODO write instructions
}

void displayQuitConfigMessage () {
  //TODO write instructions
}

void displayUserManual () {
  //TODO write instructions
}

#endif
