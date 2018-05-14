#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "..\EventSystem\EventSystem.h"
#include "..\glm\glm.hpp"

using namespace std;

class Profile {
public:
	//store render infomation of player object
	struct renderInfo {
		float posX; //X position
		float posY; //Y position
	};

	//store physics information oof player object
	struct physicsInfo {
		float posX; //X position
		float posY; //Y position
		float velX; //X velocity
		float velY; //Y velocity
	};

	Profile();
	~Profile();
	void handleEvent(int eventType);
	void update();
	void setEventSystem(EventSystem* es);
	void calculateFps();
	float getDtTime();
	int getFps();
	void setPlayerPhysicsInfo(float posX, float posY, float velX, float velY);
	physicsInfo getPlayerPhysicsInfo();
	void setPlayerRenderInfo(float x, float y);
	renderInfo getPlayerRenderInfo();
private:
	EventSystem * es; //pointer for event system

	//game infomation
	int fps;
	sf::Clock clock;
	sf::Time time;

	//player information
	renderInfo rInfo = { 0,0 };
	physicsInfo pInfo = { 0,0,0,0 };
};