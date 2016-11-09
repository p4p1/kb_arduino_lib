#ifndef kb_h
#define kb_h

#include <keys.h>

#define BUFSIZ 1024                       // Set the maximum buffer size to 1024
#define DELAY delay(500)                  // Create a delay macro that is 500 miliseconds long
#define GUI writeKey(WINDOWS, 0, 0)       // A macro that presses the GUI Key
#define WIN_R writeKey(KB_R, 0, WINDOWS); // A windows keys + r combo to open the RUN prompt in windows


void kb_init();
void error();
void releaseKey();
void writeKey(int lettr, int hold, int attr);
void printKey(char str[1024]);

#endif
