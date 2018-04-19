#pragma once
#include "Event.h"
class PlayerMoveDown : public Event {
public:
	PlayerMoveDown() {
		//don't need to inform graphic
		eventType = event::PLAYER_MOVE_DOWN;
		active[GRAPHIC] = true;
		active[AUDIO] = true;
		//active[PHYSICS] = true;
	}


};