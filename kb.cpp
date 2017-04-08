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

uint8_t uno_key[8] = { 0 };

int kb_init()
{
    default_delay = 1000;
    digitalWrite(reset_pin, 1); // define pull up on reset_pin
    digitalWrite(script_2_pin, 1);  // define pull up on script_2_pin
    digitalWrite(status_led, LOW);  // set led off before anything.
    pinMode(reset_pin, INPUT);
    pinMode(script_2_pin, INPUT);
    pinMode(status_led, OUTPUT);
    DELAY;
    if(digitalRead(reset_pin) == LOW){
        delay(99999999);
    }
    
    #if defined(CORE_TEENSY)
        Keyboard.begin();
    #else
        Serial.begin(9600);
    #endif

}

int print(char *msg)
{
  digitalWrite(status_led, HIGH);
  #if defined(CORE_TEENSY)
      Keyboard.print(msg);
      delay(100);
  #else
        for(int i = 0; i < strlen(msg); i++) {
            uno_print(msg[i]);
        }
  #endif
  digitalWrite(status_led, LOW);
  return 0;
}

int key(int a_key)
{
  digitalWrite(status_led, HIGH);
  #if defined(CORE_TEENSY)
      Keyboard.press(a_key);
      delay(100);
      Keyboard.releaseAll();
  #else
      uno_key[2] = a_key;
      Serial.write(uno_key, 8);
      delay(100);
      for(int i = 0; i < 8; i++){
         uno_key[i] = 0;
      }
      Serial.write(uno_key, 8);
  #endif
  digitalWrite(status_led, LOW);
}

int ctrl_key(int a_key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(50);
  Keyboard.press(a_key);
  delay(100);
  Keyboard.releaseAll();
  digitalWrite(status_led, LOW);
  return 0;
}

int gui_key(int a_key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.press(a_key);
  delay(100);
  Keyboard.releaseAll();
  digitalWrite(status_led, LOW);
  return 0;
}

int alt_key(int a_key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(a_key);
  delay(100);
  Keyboard.releaseAll();
  digitalWrite(status_led, LOW);
  return 0;
}

int command_menu(int os)
{
  if(os == 1) {
    gui_key('r');
  } else if(os == 2) {
    key(KEY_LEFT_GUI);
  } else if(os == 3) {
    gui_key(' ');
  } else {
    gui_key('r');
  }
}


void uno_print(char ch)
{
	int temp = 0;
	if((97 <= ch) && (ch <= 122)) {						//a-z
		temp = ch - 93;
		key(temp);
	} else if((49 <= ch) && (ch<= 57)) {  		//1-9
		temp = ch - 19;
		key(temp);
	} else if( (ch == 58) || (ch == 59) ) {		//[;]/[:]
		temp = KB_SEMICOLON;
		if( !(ch == 59) ){
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if( (ch == 47) || (ch == 63)) {		//[/]/[?]
		temp = KB_FORWARD_SLASH;
		if(!(ch == 47)){
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if((ch == 46) || (ch == 62)) {			//[dot]/[>]
		temp = KB_DOT;
		if(!(ch == 46)) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if(ch == 32) {													//[SPACE]
		temp = KB_SPACE;
		key(temp);
	} else if( (65 <= ch) && (ch <= 90)) {		//A-Z
		temp = ch - 61;
		uno_key[2] = KB_SHIFT;
        Serial.write(uno_key,8);
        delay(50);
        uno_key[4] = temp;
        Serial.write(uno_key,8);
        delay(100);
        for(int i = 0; i < 8; i++){
            uno_key[i] = 0;
        }
        Serial.write(uno_key, 8);
	} else if( (40 == ch) || (ch == 41) || (ch == 38)){	//( & )
		temp = ch - 2;
		uno_key[2] = KB_SHIFT;
        Serial.write(uno_key,8);
        delay(50);
        uno_key[4] = temp;
        Serial.write(uno_key,8);
        delay(100);
        for(int i = 0; i < 8; i++){
            uno_key[i] = 0;
        }
        Serial.write(uno_key, 8);
    } else if((ch == 91) || (ch == 123)) {		// [ / {
		temp = KB_L_BRAC;
		if(ch == 123){
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if ((ch == 93) || (ch == 125)){		// ] / }
		temp = KB_R_BRAC;
		if(ch == 125) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if((ch == 124) || (ch == 92)){			// [\] / [|]
		temp = KB_BACKSLASH;
		if(ch == 124) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if(((ch >= 35) && (ch <= 37)) || (ch == 33)) {	//[!]/[#]/[$]/[%]
		temp = ch - 3;
		uno_key[2] = KB_SHIFT;
        Serial.write(uno_key,8);
        delay(50);
        uno_key[4] = temp;
        Serial.write(uno_key,8);
        delay(100);
        for(int i = 0; i < 8; i++){
            uno_key[i] = 0;
        }
        Serial.write(uno_key, 8);
	} else if(ch == 64){													//@
		temp = KB_2;
		uno_key[2] = KB_SHIFT;
        Serial.write(uno_key,8);
        delay(50);
        uno_key[4] = temp;
        Serial.write(uno_key,8);
        delay(100);
        for(int i = 0; i < 8; i++){
            uno_key[i] = 0;
        }
        Serial.write(uno_key, 8);
	} else if(ch == 94) {													//^
		temp = KB_6;
		uno_key[2] = KB_SHIFT;
        Serial.write(uno_key,8);
        delay(50);
        uno_key[4] = temp;
        Serial.write(uno_key,8);
        delay(100);
        for(int i = 0; i < 8; i++){
            uno_key[i] = 0;
        }
        Serial.write(uno_key, 8);
	} else if(ch == 42) {													//*
		temp = KB_8;
		uno_key[2] = KB_SHIFT;
        Serial.write(uno_key,8);
        delay(50);
        uno_key[4] = temp;
        Serial.write(uno_key,8);
        delay(100);
        for(int i = 0; i < 8; i++){
            uno_key[i] = 0;
        }
        Serial.write(uno_key, 8);
	} else if((ch == 126) || (ch == 96)) {		//[`]/[~]
		temp = KB_TILDA;
		if(ch == 126) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if((ch == 47) || (ch == 63)) {			//[/]/[?]
		temp = KB_FORWARD_SLASH;
		if(ch == 63) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if ((ch == 44) || (ch == 60)) {		//[,]/[<]
		temp = KB_COMA;
		if(ch == 60) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if((ch == 39) || (ch == 34)) {			//[']/["]
		temp = KB_QUOTE;
		if(ch == 34) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if((ch == 45) || (ch == 95)) {			//[-]/[_]
		temp = KB_DASH;
		if(ch == 95) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if((ch == 61) || (ch == 43)) {			//[=]/[+]
		temp = KB_EQUAL;
		if(ch == 43) {
			uno_key[2] = KB_SHIFT;
            Serial.write(uno_key,8);
            delay(50);
            uno_key[4] = temp;
            Serial.write(uno_key,8);
            delay(100);
            for(int i = 0; i < 8; i++){
                uno_key[i] = 0;
            }
            Serial.write(uno_key, 8);
		} else {
			key(temp);
		}
	} else if(ch == 48) {
		temp = KB_0;
		key(temp);
	}
}
