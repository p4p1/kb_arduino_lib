#ifndef kb_h
#define kb_h


#define BUFSIZ 1024                       // Set the maximum buffer size to 1024
#define DELAY delay(500)                  // Create a delay macro that is 500 miliseconds long

#include <keys.h>
#include "windows.h"
#include "mac.h"

enum keyboardLanguage { KB_US=0, KB_FR=1, KB_ENG } klang;
void kb_init(int lang);

void error();
void releaseKey();
void writeKey(int lettr, int hold, int attr);
void printKey(char str[1024]);

void kb_us(char ch);
void kb_fr(char ch);

void resetKey();
void pressModifier(long mod);
void pressKey(long key);

#endif
