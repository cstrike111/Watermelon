#pragma once
#include "..\Event.h"
class Player2Win : public Event
{
public:
	Player2Win() {
		eventType = event::PLAYER2_WIN;
		active[GAME] = true;
	}
};

