#pragma once
#include "Event.h"
class ButtonPress : public Event {
public:
	ButtonPress() {
		eventType = event::BUTTON_PRESS;
		active[UI] = true;
	}


};