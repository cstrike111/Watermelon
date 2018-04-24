#pragma once
#include "Event.h"
class Load : public Event {
public:
	Load() {
		eventType = event::LOAD;
		active[FILE] = true;
	}


};
