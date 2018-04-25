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
	void handleEvent(int eventType); //handle events
	void update(); //sub-system update
	void setEventSystem(EventSystem* es); //set event system
	void setAssetManager(AssetManager* am); //set asset manager system

private:
	EventSystem* es; //pointer for event system
	AssetManager* am; //pointer for asset manager
	//store the sounds
	sf::Sound* playerStep;
};