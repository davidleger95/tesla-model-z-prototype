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
