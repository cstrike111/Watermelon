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
