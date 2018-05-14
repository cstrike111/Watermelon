#pragma once
#include "..\Event.h"
class Player1MoveLeft : public Event {
public:
	Player1MoveLeft() {
		eventType = event::PLAYER1_MOVE_LEFT;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}
	
	
};