# kb_arduino_lib
##How To:
Arduino keyboard library for arduino uno :) To use this it is pretty straight forward. You first have to download this
repository then, you need to flash on youre arduino the
<a href="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/firmware/Arduino-usbserial-uno.hex">
Arduino-usbserial-uno.hex</a> file its so that you can upload the scripts on youre arduino. To flash it you have to put you're
arduino in DFU mode. to do that its verry simple. Just replicate this image on you're board with the black cable just touching
the board for about 1 second and follow the instruction of dfu-prog script provided, use it to flash the firmware if you are
new or a bit lost.<br />
<img src="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/images/IMG_0099.jpg"><br />
After you fully uploaded the firmware on the arduino (for an intel i5 computer it takes over 1 or 2 second)you can now go into
uploading you're program, we will use a test program that is given inside of the example folder.<br />
<img src="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/images/program.png"><br />
After you uploaded using the official arduino IDE then flash the arduino with the <a href="#">keyboard firmware</a> provided
then you can finaly unplug and replug youre arduino and it will do what you asked him to do as a keyboard.<br />

## Provided functions

void kb_init(); -> initialize the library
void error(); -> if there is an error you shouldnt use this function
void releaseKey();  -> release all of the keys on the keyboard
void writeKey(int lettr, int hold, int attr); -> write a key to the screen you can have a hold or even an attribute like shit
void printKey(char str[BUFSIZ]);  -> print a screen on the string

##all of the provided macros
<a href="https://raw.githubusercontent.com/p4p1/kb_arduino_lib/master/keys.h">view this file</a>
