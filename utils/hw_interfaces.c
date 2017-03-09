#ifndef _HW_INTERFACESH_
#define _HW_INTERFACESH_
#include "./init.c"
#include "./utils.c"

// Logs strings to the console.
void cLog(char * string) {
  printf("%s", string);
}

// gets a single character from the console.
char cGetValid(char * validChars) {
  char c;
  do {
    c = getchar();
  } while (c < 0x20 || (validChars[0] != '\0' && !isValid(c, validChars))); // Wait for char within visible range.

  while(getchar() != '\n');               // Skip to next line after enter.
  return c;
}

char cGet() {
  char * c = "\0";
  return cGetValid(c);
}

#endif
