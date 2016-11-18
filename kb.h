#ifndef kb_h
#define kb_h

#include <keys.h>
#include "windows.h"
#include "mac.h"

#define BUFSIZ 1024                       // Set the maximum buffer size to 1024
#define DELAY delay(500)                  // Create a delay macro that is 500 miliseconds long
#define GUI writeKey(WINDOWS, 0, 0)       // A macro that presses the GUI Key
#define ENTER writeKey(KB_ENTER, 0, 0)    // A macro that presses enter

enum keyboardLanguage { KB_ENG=0, KB_FR=1 } kL;

void kb_init();
void error();
void releaseKey();
void writeKey(int lettr, int hold, int attr);
void printKey(char str[1024]);

#endif
