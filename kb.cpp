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
const int resetPin = 7;										// Reset button pin to prevent further execution
int buttonState = 0;											// State of the reset button pin
enum { HOLD = 1, DONT_HOLD = 0 };					// Small enum to make the syntax easier if you want youre program to hold a key

/* Initialize the library, and set the reset pin
 * and setup the pause option.
 */
void kb_init()
{
	Serial.begin(9600);
	pinMode(resetPin, INPUT);
	digitalWrite(resetPin, 1);
	buttonState = digitalRead(resetPin);
	if(buttonState == LOW) {
		delay(1000000000000000000);
	}
	delay(200);
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
	key[0] = 0;
	key[2] = 0;
	key[4] = 0;
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
		temp = 0;
		if((97 <= str[i]) && (str[i] <= 122)) {						//a-z
			temp = str[i] - 93;
			writeKey(temp, 0, 0);
		} else if((49 <= str[i]) && (str[i]<= 57)) {  		//1-9
			temp = str[i] - 19;
			writeKey(temp, 0, 0);
		} else if( (str[i] == 58) || (str[i] == 59) ) {		//[;]/[:]
			temp = KB_SEMICOLON;
			if( !(str[i] == 59) ){ 
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if( (str[i] == 47) || (str[i] == 63)) {		//[/]/[?]
			temp = KB_FORWARD_SLASH;
			if(!(str[i] == 47)){
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if((str[i] == 46) || (str[i] == 62)) {			//[dot]/[>]
			temp = KB_DOT;
			if(!(str[i] == 46)) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if(str[i] == 32) {													//[SPACE]
			temp = KB_SPACE;
			writeKey(temp, 0, 0);
		} else if( (65 <= str[i]) && (str[i] <= 90)) {		//A-Z
			temp = str[i] - 61;
			writeKey(temp, 0, SHIFT);
		} else if( (40 == str[i]) || (str[i] == 41) || (str[i] == 38)){	//( & )
			temp = str[i] - 2;
			writeKey(temp, 0, SHIFT);
		} else if((str[i] == 91) || (str[i] == 123)) {		// [ / {
			temp = KB_L_BRAC;
			if(str[i] == 123){
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if ((str[i] == 93) || (str[i] == 125)){		// ] / }
			temp = KB_R_BRAC;
			if(str[i] == 125) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if((str[i] == 124) || (str[i] == 92)){			// [\] / [|]
			temp = KB_BACKSLASH;
			if(str[i] == 124) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if(((str[i] >= 35) && (str[i] <= 37)) || (str[i] == 33)) {	//[!]/[#]/[$]/[%]
			temp = str[i] - 3;
			writeKey(temp, 0, SHIFT);
		} else if(str[i] == 64){													//@
			temp = KB_2;
			writeKey(temp, 0, SHIFT);
		} else if(str[i] == 94) {													//^
			temp = KB_6;
			writeKey(temp, 0, SHIFT);
		} else if(str[i] == 42) {													//*
			temp = KB_8;
			writeKey(temp, 0, SHIFT);
		} else if((str[i] == 126) || (str[i] == 96)) {		//[`]/[~]
			temp = KB_TILDA;
			if(str[i] == 126) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if((str[i] == 47) || (str[i] == 63)) {			//[/]/[?]
			temp = KB_FORWARD_SLASH;
			if(str[i] == 63) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if ((str[i] == 44) || (str[i] == 60)) {		//[,]/[<]
			temp = KB_COMA;
			if(str[i] == 60) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if((str[i] == 39) || (str[i] == 34)) {			//[']/["]
			temp = KB_QUOTE;
			if(str[i] == 34) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if((str[i] == 45) || (str[i] == 95)) {			//[-]/[_]
			temp = KB_DASH;
			if(str[i] == 95) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else if((str[i] == 61) || (str[i] == 43)) {			//[=]/[+]
			temp = KB_EQUAL;
			if(str[i] == 43) {
				writeKey(temp, 0, SHIFT);
			} else {
				writeKey(temp, 0, 0);
			}
		} else {
			error();
		}
	}
	delay(200);
}
