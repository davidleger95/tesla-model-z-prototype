/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	selectMode.c
 * DESCRIPTION	Let's the user select CLI mode or drive mode from idle mode.
 *
 *******************************************************************************/
#ifndef _SELECTMODEC_
#define _SELECTMODEC_

#include "../utils/hw_interfaces.c"

// TODO pull the logic from main.c into here.
int selectMode () {
  char c = cGetValid("cdCD");
  if (c == 'c')return 1;
  if (c == 'd')return 2;
  return 0;
}

#endif
