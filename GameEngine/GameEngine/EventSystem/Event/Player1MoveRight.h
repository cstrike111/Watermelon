#pragma once
#pragma once
#include "..\Event.h"
class Player1MoveRight : public Event {
public:
	Player1MoveRight() {
		eventType = event::PLAYER1_MOVE_RIGHT;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};