#pragma once
#include "..\Event.h"
class Player2MoveLeft : public Event {
public:
	Player2MoveLeft() {
		eventType = event::PLAYER2_MOVE_LEFT;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}
	
	
};