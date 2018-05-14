#pragma once
#include "..\Event.h"
class Player1Fire : public Event
{
public:
	Player1Fire() {
		//don't need to inform graphic
		eventType = event::PLAYER1_FIRE;
		//active[AUDIO] = true;
		//active[PHYSICS] = true;
		active[GAME] = true;
	}
};

