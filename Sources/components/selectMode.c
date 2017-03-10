#ifndef _SELECTMODEC_
#define _SELECTMODEC_

#include "../utils/hw_interfaces.c"

int selectMode () {
  char c = cGetValid("cdCD");
  if (c == 'c')return 1;
  if (c == 'd')return 2;
  return 0;
}

#endif
