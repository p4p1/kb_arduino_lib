#ifndef _KB_H
#define _KB_H

#include "keys.h"

#define BUFSIZ 1024
#define DELAY delay(default_delay)

enum {WINDOWS=1, LINUX=2, MAC=3};

const int reset_pin = 23;
const int script_2_pin = 1;
const int status_led = 13;
static int default_delay = 500;

void uno_print(char ch);

int kb_init();
int print(char *);
int key(int);
int ctrl_key(int);
int gui_key(int);
int command_menu(int);

#endif
