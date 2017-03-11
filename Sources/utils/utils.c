/*******************************************************************************
 * PROJECT		Tesla Model Z Prototype
 * AUTHOR(S)	David Leger
 * 				Dylan Wood
 * DATE			10 Mar, 2017
 *
 * FILE NAME	utils.c
 * DESCRIPTION	Generic utility functions.
 *
 *******************************************************************************/

#ifndef _UTILSC_
#define _UTILSC_

int isValid (char value, char * validChars) {
  int i = 0;
  while(validChars[i]){
    if (value == validChars[i++]) return value;
  }
  return 0;
}

#endif