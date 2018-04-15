#include "Event.h"
Event::Event() {
	eventType = 0;
}

Event::~Event() {

}

bool Event::getSubSystem(int subsystem) {
	switch (subsystem) {
	case GRAPHIC:
		return active[GRAPHIC];
		break;
	case PHYSICS:
		return active[PHYSICS];
		break;
	case UI:
		return active[UI];
		break;
	case AUDIO:
		return active[AUDIO];
		break;
	default:
		return false;
		break;
	}
	
}

int Event::getEventType() {
	return eventType;
}

void Event::popGraphic() {
	active[GRAPHIC] = false;
}

void Event::popPhysics() {
	active[PHYSICS] = false;
}

void Event::popUI() {
	active[UI] = false;
}

void Event::popAudio() {
	active[AUDIO] = false;
}

bool Event::isActive() {
	bool systemActive = false;
	for (int i = 0; i < 4; i++) {
		if (active[i] == true) {
			systemActive = true;
			break;
		}
	}
	return systemActive;
}


