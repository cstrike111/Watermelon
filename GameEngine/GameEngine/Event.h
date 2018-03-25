#pragma once


class Event {
public:
	//enum for event's name(will replace here with classes)
	enum {
		DRAW,
		RECTENGLE_MOVERIGHT,
		RECTENGLE_MOVELEFT,
		RECTENGLE_MOVEUP,
		RECTENGLE_MOVEDOWN,
		KEY_PRESS,
		QUIT
	};
	Event(int type);
	~Event();
	int eventType;
};