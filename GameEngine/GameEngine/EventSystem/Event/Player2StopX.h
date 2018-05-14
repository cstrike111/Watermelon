#pragma once
#include "..\Event.h"
class Player2StopX : public Event {
public:
	Player2StopX() {
		eventType = event::PLAYER2_STOP_X;
		active[PHYSICS] = true;
	}
	
	
};