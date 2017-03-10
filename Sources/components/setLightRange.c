#ifndef _SETLIGHTRANGE_
#define _SETLIGHTRANGE_

#include <ctype.h>
#include "../utils/hw_interfaces.c"
#include "../utils/user_instructions.c"

int lightMin = 0;

int getLightValue(unsigned char level) {
  switch (tolower(level)) {
    case 'l': cLog("low\n"); break;
    case 'm': cLog("med\n"); break;
    case 'h': cLog("high\n"); break;
    case 'c': cLog("cancel\n"); break;
  }
  return 1;
}

void setLightRange () {
  displaySetLightRangeInstructions();
  lightMin = getLightValue(cGetValid("lmhcLMHC"));
}

#endif
