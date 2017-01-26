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
													// Include all of the key macro
#include "kb.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

int buttonState = 0;											// State of the reset button pin
int keyLanguage = 0;								//default is us

uint8_t key[8] = { 0 };

/* Initialize the library, and set the reset pin
 * and setup the pause option.
 */
int kb_init()
{
	#if defined(ARDUINO)

		kb.resetPin = 7;
		kb.lang = KB_US;		// default keyboard language.
		kb.default_light = 13;
		pinMode(kb.default_light, OUTPUT);
		pinMode(kb.resetPin, INPUT);
		digitalWrite(kb.resetPin, 1);
		Serial.begin(9600);

	#endif
	#if defined(CORE_TEENSY)

		kb.resetPin = 23;
		kb.default_light = 13;
		kb.lang = KB_US;		// default keyboard language.
		pinMode(kb.resetPin, INPUT);
		pinMode(kb.default_light, OUTPUT);
		digitalWrite(kb.resetPin, 1);

	#else

		return -1;

	#endif

	if(digitalRead(kb.resetPin) == LOW) {
		pauseScript();
	}

	delay(500);
	return 1;
}


/* A function to reset all of the keys.
 */
int releaseKey()
{
	#if defined(ARDUINO)
		for(int i = 0 ; i < 8; i++)
			key[i] = 0;
		Serial.write(key, 8);
	#endif
	#if defined(CORE_TEENSY)
		Keyboard.set_modifier(0);
		Keyboard.set_key1(0);
		Keyboard.send_now();
	#else
		return -1;
	#endif

	return 0;
}

/* a function to press a key on the keyboard
 * and write them up on the screen.
 */
int writeKey(long lettr, long attr, int hold)
{
	#if defined(ARDUINO)
		key[4] = lettr;
		key[2] = attr;
		Serial.write(key, 8);
	#endif
	#if defined(CORE_TEENSY)
		Keyboard.set_modifier(attr);
		Keyboard.send_now();
		Keyboard.set_key1(lettr);
		Keyboard.send_now();
	#else
		return -1;
	#endif

	if(!(hold))
		releaseKey();
	return 0;
}

/* Type a string out.
 */
int printKey(char str[BUFSIZ])
{
	int i;

	i = 0;
	#if defined(ARDUINO)
		for( i = 0; str[i] != '\0'; i++) {
			if(keyLanguage == 0){
				kb_us(str[i]);
			}
		}
	#endif
	#if defined(CORE_TEENSY)
		Keyboard.print(str);
	#else
		return -1;
	#endif

	delay(200);
	return 0;
}

void ledBlinker(int inc)
{
  for(int i = 0; i < inc; i++){
    digitalWrite(kb.default_light, (i % 2)? LOW: HIGH);
    delay(70);
  }
}

void pauseScript()
{
	ledBlinker(1);
	delay(1000);
	while(1) {
		delay(1);
		if(digitalRead(kb.resetPin) != HIGH){
			break;
		}
	}
	ledBlinker(2);
}
