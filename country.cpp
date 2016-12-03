#include <kb.h>
#include <keys.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


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
