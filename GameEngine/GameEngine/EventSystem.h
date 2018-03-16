#pragma once
#pragma once
#include <queue>
#include "Event.h"
#include "SDL2-2.0.7\include\SDL.h"
using namespace std;

class EventSystem {
public:
	EventSystem();
	~EventSystem();

	void addEvent(Event e);
	void removeEvent();
	SDL_Event* getSDLEvent();
	void setSDLEvent(SDL_Event* e);

	queue<Event>* eventQueue;

	void detectUserInput();
private:
	SDL_Event* e;
};