#pragma once


class Event {
public:
	enum {
		RECTENGLE_MOVELEFT,
		KEY_PRESS
	};
	Event(int type);
	~Event();
	int eventType;
};