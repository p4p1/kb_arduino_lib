#ifndef _KB_H
#define _KB_H

#include "keys.h"

#define BUFSIZ 1024
#define DELAY do { Delay(500); } while(0)
#define GUI do { writeKey(KEY_LEFT_GUI, 0, 0); } while(0)

enum kb_kang { KB_US=0, KB_FR=1, KB_ENG=2 };
enum HOLDER { HOLD = 1, DONT_HOLD = 0 };

static struct kb {
	int lang;
	int hold;
	int resetPin;
	int default_light;
} kb;



int kb_init();
int releaseKey();

int writeKey(long , long , int );
int printKey(char str[BUFSIZ]);

void kb_us(char ch);

void ledBlinker(int inc);
void pauseScript();

#endif
