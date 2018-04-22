#pragma once
#include "Event.h"
class PlayerStopX: public Event {
public:
	PlayerStopX() {
		eventType = event::PLAYER_STOP_X;
		active[PHYSICS] = true;
	}
	
	
};