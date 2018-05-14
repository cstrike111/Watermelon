#pragma once
#include "..\Event.h"
class Player1MoveUp : public Event {
public:
	Player1MoveUp() {
		eventType = event::PLAYER1_MOVE_UP;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};