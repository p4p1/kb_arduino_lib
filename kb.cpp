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
int keyLanguage = 0;								//default is us

/* Initialize the library, and set the reset pin
 * and setup the pause option.
 */
void kb_init(int lang)
{
	Serial.begin(9600);
	pinMode(resetPin, INPUT);
	digitalWrite(resetPin, 1);
	buttonState = digitalRead(resetPin);
	if(buttonState == LOW) {
		delay(10000000);
	}

	keyLanguage = lang;

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

void kb_fr(char ch)
{
	temp = 0;
	if((97 <= ch) && (ch <= 122)) {						//a-z
		temp = ch - 93;
		writeKey(temp, 0, 0);
	} else if((49 <= ch) && (ch<= 57)) {  		//1-9
		temp = ch - 19;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if( (ch == 58) || (ch == 59) ) {		//[;]/[:]
		temp = KB_SEMICOLON;
		if( !(ch == 59) ){
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if( (ch == 47) || (ch == 63)) {		//[/]/[?]
		temp = KB_FORWARD_SLASH;
		if(!(ch == 47)){
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 46) || (ch == 62)) {			//[dot]/[>]
		temp = KB_DOT;
		if(!(ch == 46)) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if(ch == 32) {													//[SPACE]
		temp = KB_SPACE;
		writeKey(temp, 0, 0);
	} else if( (65 <= ch) && (ch <= 90)) {		//A-Z
		temp = ch - 61;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if( (40 == ch) || (ch == 41) || (ch == 38)){	//( & )
		temp = ch - 2;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if((ch == 91) || (ch == 123)) {		// [ / {
		temp = KB_L_BRAC;
		if(ch == 123){
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if ((ch == 93) || (ch == 125)){		// ] / }
		temp = KB_R_BRAC;
		if(ch == 125) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 124) || (ch == 92)){			// [\] / [|]
		temp = KB_BACKSLASH;
		if(ch == 124) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if(((ch >= 35) && (ch <= 37)) || (ch == 33)) {	//[!]/[#]/[$]/[%]
		temp = ch - 3;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if(ch == 64){													//@
		temp = KB_2;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if(ch == 94) {													//^
		temp = KB_6;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if(ch == 42) {													//*
		temp = KB_8;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if((ch == 126) || (ch == 96)) {		//[`]/[~]
		temp = KB_TILDA;
		if(ch == 126) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 47) || (ch == 63)) {			//[/]/[?]
		temp = KB_FORWARD_SLASH;
		if(ch == 63) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if ((ch == 44) || (ch == 60)) {		//[,]/[<]
		temp = KB_COMA;
		if(ch == 60) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 39) || (ch == 34)) {			//[']/["]
		temp = KB_QUOTE;
		if(ch == 34) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 45) || (ch == 95)) {			//[-]/[_]
		temp = KB_DASH;
		if(ch == 95) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 61) || (ch == 43)) {			//[=]/[+]
		temp = KB_EQUAL;
		if(ch == 43) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if(ch == 48) {
		temp = KB_0;
		writeKey(temp, 0, 0);
	} else {
		error();
	}
}

void kb_us(char ch)
{
	temp = 0;
	if((97 <= ch) && (ch <= 122)) {						//a-z
		temp = ch - 93;
		writeKey(temp, 0, 0);
	} else if((49 <= ch) && (ch<= 57)) {  		//1-9
		temp = ch - 19;
		writeKey(temp, 0, 0);
	} else if( (ch == 58) || (ch == 59) ) {		//[;]/[:]
		temp = KB_SEMICOLON;
		if( !(ch == 59) ){
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if( (ch == 47) || (ch == 63)) {		//[/]/[?]
		temp = KB_FORWARD_SLASH;
		if(!(ch == 47)){
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 46) || (ch == 62)) {			//[dot]/[>]
		temp = KB_DOT;
		if(!(ch == 46)) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if(ch == 32) {													//[SPACE]
		temp = KB_SPACE;
		writeKey(temp, 0, 0);
	} else if( (65 <= ch) && (ch <= 90)) {		//A-Z
		temp = ch - 61;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if( (40 == ch) || (ch == 41) || (ch == 38)){	//( & )
		temp = ch - 2;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if((ch == 91) || (ch == 123)) {		// [ / {
		temp = KB_L_BRAC;
		if(ch == 123){
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if ((ch == 93) || (ch == 125)){		// ] / }
		temp = KB_R_BRAC;
		if(ch == 125) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 124) || (ch == 92)){			// [\] / [|]
		temp = KB_BACKSLASH;
		if(ch == 124) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if(((ch >= 35) && (ch <= 37)) || (ch == 33)) {	//[!]/[#]/[$]/[%]
		temp = ch - 3;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if(ch == 64){													//@
		temp = KB_2;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if(ch == 94) {													//^
		temp = KB_6;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if(ch == 42) {													//*
		temp = KB_8;
		writeKey(SHIFT, 1, 0);
		writeKey(temp, 0, SHIFT);
	} else if((ch == 126) || (ch == 96)) {		//[`]/[~]
		temp = KB_TILDA;
		if(ch == 126) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 47) || (ch == 63)) {			//[/]/[?]
		temp = KB_FORWARD_SLASH;
		if(ch == 63) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if ((ch == 44) || (ch == 60)) {		//[,]/[<]
		temp = KB_COMA;
		if(ch == 60) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 39) || (ch == 34)) {			//[']/["]
		temp = KB_QUOTE;
		if(ch == 34) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 45) || (ch == 95)) {			//[-]/[_]
		temp = KB_DASH;
		if(ch == 95) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if((ch == 61) || (ch == 43)) {			//[=]/[+]
		temp = KB_EQUAL;
		if(ch == 43) {
			writeKey(SHIFT, 1, 0);
			writeKey(temp, 0, SHIFT);
		} else {
			writeKey(temp, 0, 0);
		}
	} else if(ch == 48) {
		temp = KB_0;
		writeKey(temp, 0, 0);
	} else {
		error();
	}
}
