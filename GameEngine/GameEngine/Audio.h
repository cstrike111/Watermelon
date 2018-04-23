#pragma once
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>
#include <queue>
#include "EventSystem.h"
#include "AssetManager.h"

using namespace std;

class Audio {
public:
	Audio(AssetManager* am);
	~Audio();
	void loadSounds(); //load the sound, get memory for memory manager
	void handleEvent(int eventType);
	void update();
	void setEventSystem(EventSystem* es);
	void setAssetManager(AssetManager* am);

private:
	EventSystem* es; //pointer for event system
	AssetManager* am; //pointer for asset manager
	//store the sounds
	sf::Sound* playerStep;
};