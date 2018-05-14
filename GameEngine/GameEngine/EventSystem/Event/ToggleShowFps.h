#pragma once
#include "..\Event.h"
class ToggleShowFps : public Event {
public:
	ToggleShowFps() {
		eventType = event::TOGGLE_SHOW_FPS;
		active[GRAPHIC] = true;
	}


};