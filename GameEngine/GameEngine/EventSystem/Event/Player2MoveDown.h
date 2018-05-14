#pragma once
#include "..\Event.h"
class Player2MoveDown : public Event {
public:
	Player2MoveDown() {
		//don't need to inform graphic
		eventType = event::PLAYER2_MOVE_DOWN;
		active[AUDIO] = true;
		active[PHYSICS] = true;
	}


};