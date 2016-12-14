

#ifndef WINDOWS_H
#define WINDOWS_H


#define GUI writeKey(WINDOWS, 0, 0)       // A macro that presses the GUI Key
#define ENTER writeKey(KB_ENTER, 0, 0)    // A macro that presses enter

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


#endif
