#include "EventSystem.h"


EventSystem::EventSystem() {
	eventQueue = new queue<Event>;
}

EventSystem::~EventSystem() {
	delete eventQueue;
	delete e;
}

void EventSystem::addEvent(Event e) {
	eventQueue->push(e);
}

void EventSystem::removeEvent() {
	eventQueue->pop();
}

void EventSystem::detectUserInput() {
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

SDL_Event* EventSystem::getSDLEvent() {
	return e;
}

void EventSystem::setSDLEvent(SDL_Event* e) {
	this->e = e;
}
