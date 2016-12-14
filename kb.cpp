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

int buttonState = 0;											// State of the reset button pin
int keyLanguage = 0;								//default is us


/* Initialize the library, and set the reset pin
 * and setup the pause option.
 */
int kb_init(int b_type)
{
	if(b_type == UNO) {

		kb.board_type = UNO;
		kb.resetPin = 7;
		kb.lang = KB_US;		// default keyboard language.
		pinMode(kb.resetPin, INPUT);
		digitalWrite(kb.resetPin, 1);
		Serial.begin(9600);

	} else if (b_type == TEENSY) {

		kb.board_type = TEENSY;
		kb.resetPin = 23;
		kb.lang = KB_US;		// default keyboard language.
		pinMode(kb.resetPin, INPUT);
		digitalWrite(kb.resetPin, 1);

	} else {

		return -1;

	}

	if(digitalRead(kb.resetPin) == LOW) {
		pauseScript();
	}

	delay(200);
	return 1;
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
int releaseKey()
{
	if(kb.board_type == UNO){
		for(int i = 0 ; i < ; i++)
			kb.key[i] = 0;
		Serial.write(kb.key, 8);
	} else if(kb.board_type == TEENSY) {
		Keyboard.set_modifier(0);
		Keyboard.set_key1(0);
		Keyboard.set_key2(0);
		Keyboard.set_key3(0);
		Keyboard.set_key4(0);
		Keyboard.set_key5(0);
		Keyboard.send_now();
	} else {
		return -1;
	}

	return 0;
}

/* a function to press a key on the keyboard
 * and write them up on the screen.
 */
int writeKey(long lettr, long attr, int hold)
{
	if(kb.board_type == UNO){
		key[4] = lettr;
		key[2] = attr;
		Serial.write(key, 8);
	} else if (kb.board_type == TEENSY) {
		Keyboard.set_modifier(attr);
		Keyboard.set_key1(lettr);
		Keyboard.send_now();
	} else {
		return -1;
	}

	if(!(hold))
		releaseKey();
	return 0;
}

/* Type a string out.
 */
int printKey(char str[BUFSIZ])
{
	int temp;
	int i;

	temp = i = 0;
	if(kb.board_type == UNO){
		for( i = 0; str[i] != '\0'; i++) {
			if(keyLanguage == 0){
				kb_us(str[i]);
			} else {
				error();
			}
		}
	} else if(kb.board_type == TEENSY) {
		Keyboard.print(str);
	} else {
		return -1;
	}

	delay(200);
	return 0;
}

void ledBlinker(int inc)
{
  for(int i = 0; i < inc; i++){
    digitalWrite(LED_BUILTIN, (i % 2)? LOW: HIGH);
    delay(70);
  }
}

void pauseScript()
{
	ledBlinker(1);
        while(1) {

          delay(1);
          if(digitalRead(kb.resetPin) != HIGH){
            break;
          }

        }
        ledBlinker(2);
}
