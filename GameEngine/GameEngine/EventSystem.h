#pragma once
#pragma once
#include <vector>
#include "Event.h"
#include "SDL2-2.0.7\include\SDL.h"
using namespace std;

class EventSystem {
public:
	EventSystem();
	~EventSystem();

	void addEvent(Event e);
	void removeEvent();

	vector<Event>* queue;

	void detectUserInput(SDL_Event* e);
private:
	
};