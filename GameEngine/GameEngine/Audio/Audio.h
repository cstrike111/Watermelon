#pragma once
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>
#include <queue>
#include "..\EventSystem\EventSystem.h"
#include "..\AssetManager\AssetManager.h"

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

	//game specific function
	void playHadouken1();
	void playHadouken2();
	void playVictory();
	void playHit1();
	void playHit2();


private:
	EventSystem* es; //pointer for event system
	AssetManager* am; //pointer for asset manager
	//store the sounds
	sf::Sound* hadouken1;
	sf::Sound* hadouken2;
	sf::Sound* victory;
	sf::Sound* hit1;
	sf::Sound* hit2;
};