#pragma once
#include "Event.h"
class PlayerStopY : public Event {
public:
	PlayerStopY() {
		eventType = event::PLAYER_STOP_Y;
		active[PHYSICS] = true;
	}


};