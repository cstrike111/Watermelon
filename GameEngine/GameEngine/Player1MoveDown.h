#pragma once
#include "Event.h"
class Player1MoveDown : public Event {
public:
	Player1MoveDown() {
		//don't need to inform graphic
		eventType = event::PLAYER1_MOVE_DOWN;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};