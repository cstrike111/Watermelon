#pragma once


class Event {
public:
	enum {
		DRAW,
		RECTENGLE_MOVERIGHT,
		KEY_PRESS,
		QUIT
	};
	Event(int type);
	~Event();
	int eventType;
};