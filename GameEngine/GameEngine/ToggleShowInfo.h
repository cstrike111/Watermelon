#pragma once
#include "Event.h"
class ToggleShowInfo : public Event {
public:
	ToggleShowInfo() {
		eventType = event::TOGGLE_SHOW_INFO;
		active[GRAPHIC] = true;
	}


};