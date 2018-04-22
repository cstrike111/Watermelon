#pragma once
#include "Event.h"
class KeyRelease : public Event {
public:
	KeyRelease() {
		eventType = event::KEYRELEASE;
		active[UI] = true;
	}


};