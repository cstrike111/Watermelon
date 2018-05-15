#pragma once
#include "..\Event.h"
class Player1Win : public Event
{
public:
	Player1Win() {
		eventType = event::PLAYER1_WIN;
		active[GAME] = true;
	}
};

