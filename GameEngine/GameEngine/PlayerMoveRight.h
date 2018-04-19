#pragma once
#pragma once
#include "Event.h"
class PlayerMoveRight : public Event {
public:
	PlayerMoveRight() {
		eventType = event::PLAYER_MOVE_RIGHT;
		active[GRAPHIC] = true;
		active[AUDIO] = true;
		//active[PHYSICS] = true;
	}


};