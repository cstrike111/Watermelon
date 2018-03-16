#pragma once
#include "SDL2-2.0.7\include\SDL.h"
#include "EventSystem.h"
#include <iostream>
#include <queue>
enum KeyPress {
	KEY_PRESS_DEFAULT,
	KEY_PRESS_ESCAPE,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_TOTAL
};

class Input {
public:
	

	Input();
	~Input();

	//return the key user pressed
	void handleEvent(EventSystem* es);
	void handleKey(EventSystem* es);

	//a function that can detect the pressed key and create event
private:
	//key press surfaces constants
	
};



