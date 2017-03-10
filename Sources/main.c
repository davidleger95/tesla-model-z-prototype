#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./utils/hw_interfaces.c"
#include "./components/selectMode.c"
#include "./components/config.c"
#include "./components/drive.c"

int main () {
	init();

	while (1) {
		redLED(1);
	  int choice = 0;
	  while (!choice){
		  if(SW2_Input()) {
			  choice = 1;
		  } else {
			  //TODO check another switch (SW3?)
		  }
	  }
	  redLED(0);
	  if(choice == 1) {
		  config();
	  } else {
		  drive();
	  }

	}

	redLED(0);
}
