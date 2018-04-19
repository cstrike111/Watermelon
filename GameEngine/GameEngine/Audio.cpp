#include "Audio.h"

Audio::Audio() {
	loadSounds();
}

Audio::~Audio() {
	//delete the sound
	delete playerStep;
	playerStep = nullptr;
	delete playerStepBuffer;
	playerStepBuffer = nullptr;
}

void Audio::loadSounds() {
	playerStepBuffer->loadFromFile("asset/sounds/ss.wav");
	playerStep->setBuffer(*playerStepBuffer);
}

void Audio::handleEvent(int eventType) {
	switch (eventType) {
	case Event::PLAYER_MOVE_UP:
		playerStep->play();
		break;
	case Event::PLAYER_MOVE_DOWN:
		playerStep->play();
		break;
	case Event::PLAYER_MOVE_LEFT:
		playerStep->play();
		break;
	case Event::PLAYER_MOVE_RIGHT:
		playerStep->play();
		break;
	default:
		break;
	}
}

void Audio::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::AUDIO)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popAudio();
		}
	}
}

void Audio::getEventSystem(EventSystem* es) {
	this->es = es;
}
