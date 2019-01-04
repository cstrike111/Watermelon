#include "Audio.h"

Audio::Audio(AssetManager* am) {
	setAssetManager(am);
	loadSounds();
}

Audio::~Audio() {
	//delete the sound
	delete hadouken1;
	hadouken1 = nullptr;
	delete hadouken2;
	hadouken2 = nullptr;
	delete victory;
	victory = nullptr;
	delete hit1;
	hit1 = nullptr;
	delete hit2;
	hit2 = nullptr;
}

void Audio::loadSounds() {
	am->loadAsset("asset/sounds/hadouken.wav", AssetManager::SOUND);
	hadouken1 = new sf::Sound();
	hadouken1->setBuffer(*(static_cast<sf::SoundBuffer*>(am->getAsset("asset/sounds/hadouken.wav", AssetManager::SOUND))));
	hadouken2 = new sf::Sound();
	hadouken2->setBuffer(*(static_cast<sf::SoundBuffer*>(am->getAsset("asset/sounds/hadouken.wav", AssetManager::SOUND))));
	am->loadAsset("asset/sounds/victory.wav", AssetManager::SOUND);
	victory = new sf::Sound();
	victory->setBuffer(*(static_cast<sf::SoundBuffer*>(am->getAsset("asset/sounds/victory.wav", AssetManager::SOUND))));
	am->loadAsset("asset/sounds/hit.ogg", AssetManager::SOUND);
	hit1 = new sf::Sound();
	hit1->setBuffer(*(static_cast<sf::SoundBuffer*>(am->getAsset("asset/sounds/hit.ogg", AssetManager::SOUND))));
	hit2 = new sf::Sound();
	hit2->setBuffer(*(static_cast<sf::SoundBuffer*>(am->getAsset("asset/sounds/hit.ogg", AssetManager::SOUND))));
}

void Audio::handleEvent(int eventType) {
	switch (eventType) {
	case Event::PLAYER1_MOVE_UP:
		break;
	case Event::PLAYER1_MOVE_DOWN:
		break;
	case Event::PLAYER1_MOVE_LEFT:
		break;
	case Event::PLAYER1_MOVE_RIGHT:
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

void Audio::playHadouken1()
{
	hadouken1->play();
}

void Audio::playHadouken2()
{
	hadouken2->play();
}

void Audio::playVictory()
{
	victory->play();
}

void Audio::playHit1()
{
	hit1->play();
}

void Audio::playHit2()
{
	hit2->play();
}
