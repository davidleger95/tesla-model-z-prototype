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

int main () {
	init();		// initialize hardware
	redLED(1);
	while (1) {
		selectMode();
	}
}
