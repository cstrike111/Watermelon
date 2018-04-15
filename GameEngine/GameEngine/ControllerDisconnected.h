#pragma once
#include "Event.h"
class ControllerDisconnected : public Event {
public:
	ControllerDisconnected() {
		eventType = event::CONTROLLER_DISCONNECTED;
		active[UI] = true;
	}


};