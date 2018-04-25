#include "EventSystem.h"

/*Event System not only handles the events made by me, 
but also handles the SDL events*/

EventSystem::EventSystem(sf::RenderWindow* window) {
	eventQueue = new queue<Event>;
	this->window = window;
}

EventSystem::~EventSystem() {
	delete eventQueue;

}

void EventSystem::addEvent(Event* e) {
	eventQueue->push(*e);
}

void EventSystem::removeEvent() {
	eventQueue->pop();
}


queue<Event>* EventSystem::getEventQueue() {
	return eventQueue;
}


void EventSystem::checkFinish() {
	//set a flag indicates whether there are other events to check
	bool finish = false;
	while (!finish) {
		//if there is something in the queue
		if (eventQueue->size() != 0) {
			if (!eventQueue->front().isActive()) {
				//if subsystems finish their jobs in this event, take the event out of the list
				removeEvent();
			}
			else {
				//if not, stop checking
				finish = true;
				break;
			}
		}
		else {
			finish = true;
			break;
		}
		
	}
}

void EventSystem::update() {

	//check whether the events are finished and clean the list
	if (eventQueue->size() != 0) {
		checkFinish();
	}
}


