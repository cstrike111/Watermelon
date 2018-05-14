#pragma once
#pragma once
#include "..\Event.h"
class Player2MoveRight : public Event {
public:
	Player2MoveRight() {
		eventType = event::PLAYER2_MOVE_RIGHT;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};