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
	//handle sfml event 
	while (window->pollEvent(sfEvent))
	{	
		switch (sfEvent.type) {
		//if the user wants to close the window, close it
		case sf::Event::Closed:
			addEvent(new Quit());
			break;
		
		//if the user press something
		case sf::Event::KeyPressed:
			addEvent(new KeyPress());
			keycode = sfEvent.key.code; // get the keycode
			break;

		//if the controller is connected
		case sf::Event::JoystickConnected:
			addEvent(new ControllerConnected());
			controllerId = sfEvent.joystickConnect.joystickId;
			break;

		//if the controller is connected
		case sf::Event::JoystickDisconnected:
			addEvent(new ControllerDisconnected());
			controllerId = sfEvent.joystickConnect.joystickId;
			break;
		//if the controller button is pressed
		case sf::Event::JoystickButtonPressed:
			addEvent(new ButtonPress());
			button = sfEvent.joystickButton.button;
			break;
		//by default, do nothing
		default:
			break;
		}
			
	}

	//check whether the events are finished and clean the list
	if (eventQueue->size() != 0) {
		checkFinish();
	}
}

sf::Event EventSystem::getsfEvent() {
	return sfEvent;
}

int EventSystem::getKeycode() {
	return keycode;
}

int EventSystem::getControllerId() {
	return controllerId;
}

int EventSystem::getButton() {
	return button;
}
