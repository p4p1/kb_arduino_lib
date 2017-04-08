#include "kb.h"

void setup() {
	// All of the setup code that will be executed once
    kb_init();
}

void loop() {
	// Loop code will be executed until the program ends
    print("HelloWorld");
    delay(1000);
}
