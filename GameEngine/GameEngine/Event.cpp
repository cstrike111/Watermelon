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
	case ASSETMANAGER:
		return active[ASSETMANAGER];
		break;
	case PROFILE:
		return active[PROFILE];
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

void Event::popAssetManager() {
	active[ASSETMANAGER] = false;
}

void Event::popProfile() {
	active[PROFILE] = false;
}

bool Event::isActive() {
	bool systemActive = false;
	//i = number of sub-system
	for (int i = 0; i < 6; i++) {
		if (active[i] == true) {
			systemActive = true;
			break;
		}
	}
	return systemActive;
}


