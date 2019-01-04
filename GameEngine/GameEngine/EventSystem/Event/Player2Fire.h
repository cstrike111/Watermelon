#pragma once
#include "..\Event.h"
class Player2Fire : public Event
{
public:
	Player2Fire() {
		//don't need to inform graphic
		eventType = event::PLAYER2_FIRE;
		active[GAME] = true;
	}
};

