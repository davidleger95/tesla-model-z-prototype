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
  cLog("setSpeedRange\n");
}

void setDirection () {
  cLog("setDirection\n");
}

void resetDefault () {
  cLog("resetDefault\n");
}

void quit () {
  cLog("Saving configuration...\n");
  // TODO save config data
  cLog("Save complete! OK to disconnect device.\n");
  configure = 0;
}

void config () {
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
}

#endif
