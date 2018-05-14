#pragma once
#include "..\Event.h"
class Player1StopY : public Event {
public:
	Player1StopY() {
		eventType = event::PLAYER1_STOP_Y;
		active[PHYSICS] = true;
	}


};