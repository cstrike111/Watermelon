#pragma once
#include "Event.h"
class Save : public Event {
public:
	Save() {
		eventType = event::SAVE;
		active[FILE] = true;
		active[PHYSICS] = true;
	}


};