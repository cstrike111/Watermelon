#pragma once
#include "..\Event.h"
class Player2StopY : public Event {
public:
	Player2StopY() {
		eventType = event::PLAYER2_STOP_Y;
		active[PHYSICS] = true;
	}


};