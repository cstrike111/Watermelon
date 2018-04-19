#pragma once
#include "Event.h"
class PlayerMoveUp : public Event {
public:
	PlayerMoveUp() {
		eventType = event::PLAYER_MOVE_UP;
		active[GRAPHIC] = true;
		active[AUDIO] = true;
		//active[PHYSICS] = true;
	}


};