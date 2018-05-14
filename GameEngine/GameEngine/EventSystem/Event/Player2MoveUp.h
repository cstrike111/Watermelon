#pragma once
#include "..\Event.h"
class Player2MoveUp : public Event {
public:
	Player2MoveUp() {
		eventType = event::PLAYER2_MOVE_UP;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};