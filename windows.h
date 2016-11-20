#include <kb.h>
#include <keys.h>

#define WINR writeKey(WINDOWS, 1, 0); \
		writeKey(KB_R, 0, WINDOWS)

#define CTRLESC writeKey(CTRL, 1, 0); \
		writeKey(KB_ESCAPE, 0, CTRL)

#define SYSMENU writeKey(ALT, 1, 0); \
		writeKey(KB_SPACE, 0, ALT)

#define DESKTOP writeKey(WINDOWS, 1, 0); \
		writeKey(KB_D, 0, WINDOWS)

#define CRTLS writeKey(CTRL, 1, 0); \
		writeKey(KB_S, 0, CTRL)

#define ALTF4 writeKey(ALT, 1, 0); \
		writeKey(F4, 0, ALT)

#define EXPLORER writeKey(WINDOWS, 1 ,0); \
		writeKey(KB_E, 0, WINDOWS)

#define CTRLF writeKey(CTRL, 1, 0); \
		writeKey(KB_F, 0, CTRL)

#define ALTO writeKey(ALT, 1, 0); \
		writeKey(KB_O, 0, ALT)

#define ALTTAB writeKey(ALT, 1 ,0); \
		writeKey(KB_TAB, 0, ALT)

#define WIND writeKey(WINDOWS, 1, 0); \
		writeKey(KB_D, 0, WINDOWS)

#define ADMIN_ENTER key[6] = KB_ENTER;\
		key[4] = SHIFT; \
		key[2] = CTRL; \
		Serial.write(key, 8); \
		delay(200); \
		releaseKey()
