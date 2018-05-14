#include "Audio.h"

Audio::Audio(AssetManager* am) {
	setAssetManager(am);
	loadSounds();
}

Audio::~Audio() {
	//delete the sound
	delete playerStep;
	playerStep = nullptr;
}

void Audio::loadSounds() {
	am->loadAsset("asset/sounds/ss.wav", AssetManager::SOUND);
	playerStep = new sf::Sound();
	playerStep->setBuffer(*(static_cast<sf::SoundBuffer*>(am->getAsset("asset/sounds/ss.wav", AssetManager::SOUND))));
}

void Audio::handleEvent(int eventType) {
	switch (eventType) {
	case Event::PLAYER1_MOVE_UP:
		playerStep->play();
		break;
	case Event::PLAYER1_MOVE_DOWN:
		playerStep->play();
		break;
	case Event::PLAYER1_MOVE_LEFT:
		playerStep->play();
		break;
	case Event::PLAYER1_MOVE_RIGHT:
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

void Audio::setEventSystem(EventSystem* es) {
	this->es = es;
}

void Audio::setAssetManager(AssetManager* am) {
	this->am = am;
}
