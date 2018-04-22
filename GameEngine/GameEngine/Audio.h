#pragma once
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>
#include <queue>
#include "EventSystem.h"

using namespace std;

class Audio {
public:
	Audio();
	~Audio();
	void loadSounds(); //load the sound, get memory for memory manager
	void handleEvent(int eventType);
	void update();
	void setEventSystem(EventSystem* es);

private:
	EventSystem* es; //pointer for event system
	//store the sounds
	sf::Sound* playerStep;
	sf::SoundBuffer* playerStepBuffer;
};