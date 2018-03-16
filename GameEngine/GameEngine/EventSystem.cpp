#include "EventSystem.h"


EventSystem::EventSystem() {
	queue = new vector<Event>;
}

EventSystem::~EventSystem() {
	delete queue;
}

void EventSystem::addEvent(Event e) {
	queue->push_back(e);
}

void EventSystem::removeEvent() {
	queue->pop_back();
}

void EventSystem::detectUserInput(SDL_Event* e) {
	switch (e->type){
	case SDL_KEYDOWN:
		addEvent(Event::KEY_PRESS);
		break;
	case SDL_QUIT:
		addEvent(Event::QUIT);
		break;
	default:
		break;
	}
	
}
