#pragma once
#pragma once
#include "..\Event.h"
class PlayerMoveRight : public Event {
public:
	PlayerMoveRight() {
		eventType = event::PLAYER1_MOVE_RIGHT;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};