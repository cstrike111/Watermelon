#pragma once
#include "Event.h"
class KeyPress : public Event {
public:
	KeyPress() {
		eventType = event::KEYPRESS;
		active[UI] = true;
	}


};