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

int kb_init()
{
    default_delay = 1000;
    Keyboard.begin();
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

}

int print(char *msg)
{
  digitalWrite(status_led, HIGH);
  Keyboard.print(msg);
  delay(100);
  digitalWrite(status_led, LOW);
  return 0;
}

int key(int key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(key);
  delay(100);
  digitalWrite(status_led, LOW);
  Keyboard.releaseAll();
}

int ctrl_key(int key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(50);
  Keyboard.press(key);
  delay(100);
  Keyboard.releaseAll();
  digitalWrite(status_led, LOW);
  return 0;
}

int gui_key(int key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.press(key);
  delay(100);
  Keyboard.releaseAll();
  digitalWrite(status_led, LOW);
  return 0;
}

int alt_key(int key)
{
  digitalWrite(status_led, HIGH);
  Keyboard.press(KEY_LEFT_ALT);
  delay(50);
  Keyboard.press(key);
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
