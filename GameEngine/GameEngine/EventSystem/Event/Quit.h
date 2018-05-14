#pragma once
#include "..\Event.h"
class Quit : public Event {
public:
	Quit() {
		eventType = event::QUIT;
		active[UI] = true;
	}


};