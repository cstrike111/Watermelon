#pragma once
#include "Event.h"
class Player1StopX : public Event {
public:
	Player1StopX() {
		eventType = event::PLAYER1_STOP_X;
		active[PHYSICS] = true;
	}
	
	
};