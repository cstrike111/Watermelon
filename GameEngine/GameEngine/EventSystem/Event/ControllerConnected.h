#pragma once
#include "..\Event.h"
class ControllerConnected : public Event {
public:
	ControllerConnected() {
		eventType = event::CONTROLLER_CONNECTED;
		active[UI] = true;
	}


};