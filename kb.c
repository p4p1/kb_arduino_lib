/*
 * /$$                           /$$                                           /$$              
 *| $$                          | $$                                          | $$              
 *| $$   /$$  /$$$$$$  /$$   /$$| $$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$      /$$$$$$$
 *| $$  /$$/ /$$__  $$| $$  | $$| $$__  $$ /$$__  $$ |____  $$ /$$__  $$ /$$__  $$     /$$_____/
 *| $$$$$$/ | $$$$$$$$| $$  | $$| $$  \ $$| $$  \ $$  /$$$$$$$| $$  \__/| $$  | $$    | $$      
 *| $$_  $$ | $$_____/| $$  | $$| $$  | $$| $$  | $$ /$$__  $$| $$      | $$  | $$    | $$      
 *| $$ \  $$|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$/|  $$$$$$$| $$      |  $$$$$$$ /$$|  $$$$$$$
 *|__/  \__/ \_______/ \____  $$|_______/  \______/  \_______/|__/       \_______/|__/ \_______/
 *                     /$$  | $$                                                               
 *                    |  $$$$$$/                                                               
 *                     \______/                                          
 * Keyboard programs for arduino :P
 */

#include "keys.h"
#define BUFSIZ 1024

void kb_init();
void error();
void releaseKey();
void writeKey(int lettr, int hold, int attr);
void printKey(char str[BUFSIZ]);

uint8_t key[8] = {
	0 };

enum { HOLD = 1, DONT_HOLD = 0 };

void kb_init()
{
	Serial.begin(9600);
	delay(200);
}

void error()
{
 printKey("ERROR : This letter is not supported");
}

void releaseKey()
{
	key[0] = 0;
	key[2] = 0;
	key[4] = 0;
	Serial.write(key, 8);
}

void writeKey(int lettr, int hold, int attr)
{
	key[4] = lettr;
	key[2] = attr;
	Serial.write(key, 8);
	if(!(hold))
		releaseKey();
}

void printKey(char str[BUFSIZ])
{
	int temp;
	for( int i = 0; str[i] != '\0'; i++) {
		temp = 0;
    if((97 <= str[i]) && (str[i] <= 122)) {
      temp = str[i] - 93;     //93
      writeKey(temp, 0, 0);
    } else if((49 <= str[i]) && (str[i]<= 57)) {  // 1 - 9
      temp = str[i] - 19;
      writeKey(temp, 0, 0);
    } else if( (str[i] == 58) || (str[i] == 59) ) {
			temp = KB_SEMICOLON;
      if( !(str[i] == 59) ){ // if :
      	writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
    } else if( (str[i] == 47) || (str[i] == 63)) {
      temp = KB_FORWARD_SLASH;
			if(!(str[i] == 47)){
      	writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
    } else if((str[i] == 46) || (str[i] == 62)) {
			temp = KB_DOT;
      if(!(str[i] == 46)) {
        writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
    } else if(str[i] == 32) {
			temp = KB_SPACE;
			writeKey(temp, 0, 0);
		} else if( (65 <= str[i]) && (str[i] <= 90)) {
			temp = str[i] - 61;
			writeKey(temp, 0, SHIFT);
		} else {
			error();
		}
	}
}
