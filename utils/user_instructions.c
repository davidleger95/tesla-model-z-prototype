#ifndef _INSTRUCTIONSC_
#define _INSTRUCTIONSC_

void displayMainMenu() {
  cLog("----------------------------------------------------------------------\n\r");
  cLog("| WELCOME TO TESLA MODEL Z CONFIG!                                   |\n\r");
  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("Select one of the following options to configure the device:\n\r");
  cLog("\t [1] Set light range.\n\r");
  cLog("\t [2] Set light speed range.\n\r");
  cLog("\t [3] Set direction.\n\r");
  cLog("\t [4] Reset Default.\n\r");
  cLog("\t [5] View User Manual.\n\r");
  cLog("\t [0] Save Config & Quit.\n\r");
}

void displaySetLightRangeInstructions () {
  cLog("----------------------------------------------------------------------\n\n\r");
  cLog("Set a value for the minimum light intensity that the device needs to\n\r");
  cLog("start moving. Choolse from one of the following options:\n\r");
  cLog("\t [L] Low light.\n\r");
  cLog("\t [M] Medium light (default).\n\r");
  cLog("\t [H] High light.\n\r");
  cLog("\t [C] Cancel.\n\r");
  cLog("MIN LIGHT THRESHOLD: ");
}

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
