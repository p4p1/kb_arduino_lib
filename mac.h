#ifndef MAC_H
#define MAC_H


#define GUI writeKey(WINDOWS, 0, 0)       // A macro that presses the GUI Key
#define ENTER writeKey(KB_ENTER, 0, 0)    // A macro that presses enter

#define CMDSPACE writeKey(WINDOWS, 1, 0); \
			writeKey(KB_SPACE, 0, WINDOWS);

#endif
