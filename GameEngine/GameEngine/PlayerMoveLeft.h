#pragma once
#include "Event.h"
class PlayerMoveLeft: public Event {
public:
	PlayerMoveLeft() {
		eventType = event::PLAYER_MOVE_LEFT;
		active[GRAPHIC] = true;
		//active[PHYSICS] = true;
	}
	
	
};