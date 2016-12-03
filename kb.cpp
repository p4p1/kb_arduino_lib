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


#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "keys.h"													// Include all of the key macro
#include "kb.h"
#define BUFSIZ 1024												// Set the maximum buffer size to 1024

uint8_t key[8] = { 0 };										// Keyboard buffer that will be sent to the target
#ifdef UNO_BOARD
const int resetPin = 7;										// Reset button pin to prevent further execution
#endif
#ifdef LEONARDO_TEENSY_MICRO
const int resetPin = 23;
#endif
int buttonState = 0;											// State of the reset button pin
enum { HOLD = 1, DONT_HOLD = 0 };					// Small enum to make the syntax easier if you want youre program to hold a key
int keyLanguage = 0;								//default is us

/* Initialize the library, and set the reset pin
 * and setup the pause option.
 */
void kb_init(int lang)
{
	#ifdef UNO_BOARD
		Serial.begin(9600);
		pinMode(resetPin, INPUT);
		digitalWrite(resetPin, 1);
		buttonState = digitalRead(resetPin);
		if(buttonState == LOW) {
			delay(10000000);
		}
		keyLanguage = lang;
		delay(200);
	#endif
	#ifdef LEONARDO_TEENSY_MICRO
		pinMode(resetPin, INPUT);
		digitalWrite(resetPin, 1);
		buttonState = digitalRead(resetPin);
		if(buttonState == LOW) {
			delay(10000000);
		}
		keyLanguage = lang;
		delay(200);
	#endif

}

/* Print an error message to the keyboard to catch errors
 * easly.
 */
void error()
{
	printKey("ERROR : This letter is not supported");
}

/* A function to reset all of the keys.
 */
void releaseKey()
{
	for(int i = 0 ; i < ; i++)
		key[i] = 0;
	Serial.write(key, 8);
}

/* a function to press a key on the keyboard
 * and write them up on the screen.
 */
void writeKey(int lettr, int hold, int attr)
{
	key[4] = lettr;
	key[2] = attr;
	Serial.write(key, 8);
	if(!(hold))
		releaseKey();
}

/* Type a string out.
 */
void printKey(char str[BUFSIZ])
{
	int temp;
	int i;
	for( i = 0; str[i] != '\0'; i++) {
		if(keyLanguage == 0){
			kb_us(str[i]);
		} else {
			error();
		}
	}
	delay(200);
}

void resetKey()
{

	Keyboard.set_modifier(0);
	Keyboard.set_key1(0);
	Keyboard.send_now();

}
void pressModifier(long mod)
{

	Keyboard.set_modifier(mod);
	Keyboard.send_now();

}
void pressKey(long key)
{

	Keyboard.set_key1(key);
	Keyboard.send_now();
	Keyboard.set_key1(0);
	Keyboard.send_now();
	
}
