#ifndef kb_h
#define kb_h


#define BUFSIZ 1024                       // Set the maximum buffer size to 1024
#define DELAY delay(500)                  // Create a delay macro that is 500 miliseconds long

#include <keys.h>
#include "windows.h"
#include "mac.h"

enum keyboardLanguage { KB_US=0, KB_FR=1, KB_ENG } klang;
enum board { UNO = 10, TEENSY = 20 } board_type;
enum HOLDER { HOLD = 1, DONT_HOLD = 0 } is_hold;

typedef struct kb
{
	int board_type;
	int lang;
	int hold;
	int resetPin;
	uint8_t key[8] = { 0 };
};

kb kb_strct;

int kb_init(int);
int releaseKey();
void error();
int writeKey(long , long , int );
int printKey(char str[BUFSIZ]);

void kb_us(char ch);
void kb_fr(char ch);


void ledBlinker(int inc);
void pauseScript();

#endif
