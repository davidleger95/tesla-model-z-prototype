/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	main.c
 * DESCRIPTION	Main program for the Tesla Model Z Prototype's software system.
 *
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./utils/hw_interfaces.c"
#include "./components/selectMode.c"
#include "./components/cli.c"
#include "./components/drive.c"

int main () {
	init();		// initialize hardware

	while (1) {
		redLED(1);
	  int choice = 0;
	  while (!choice){
		  if(SW2_Input()) {
			  choice = 1;
		  } else {
			  //TODO check another switch (SW3?)
			  // set PORT_PCR = ALT | IRQC;
			  // NVIC_EnableIRQ(PORTx_IRQn);
			  // void PORTE_IRQHandler(void) {
			  // 	// do shit on interrupt
		  	  //}
		  }
	  }
	  redLED(0);
	  if(choice == 1) {
		  cli();
	  } else {
		  drive();
	  }

	}

	redLED(0);
}
