#include "Profile.h"



Profile::Profile()
{
}

Profile::~Profile()
{
}

void Profile::handleEvent(int eventType) {
	switch (eventType) {
	default:
		
		break;
	}
}

void Profile::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::PROFILE)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popProfile();
		}
	}

	//calculate fps
	calculateFps();
}

void Profile::setEventSystem(EventSystem* es) {
	this->es = es;
}

void Profile::calculateFps() {
	fps = 1.0f / getDtTime();
}

float Profile::getDtTime() {
	time = clock.getElapsedTime();
	clock.restart().asSeconds();
	return time.asSeconds();
}

int Profile::getFps() {
	return fps;
}
