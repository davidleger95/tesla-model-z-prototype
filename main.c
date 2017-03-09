#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./utils/hw_interfaces.c"
#include "./components/selectMode.c"
#include "./components/config.c"
#include "./components/drive.c"

int convertLightToSpeed () {
  return 1;
}

int main () {
  while (1) {
    switch (selectMode()) {
      case 1: config(); break;
      case 2: drive(); break;
      //default: invalidInput();
    }
  }
}
