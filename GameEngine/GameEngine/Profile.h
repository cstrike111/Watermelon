#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "EventSystem.h"

using namespace std;

class Profile {
public:
	Profile();
	~Profile();
	void handleEvent(int eventType);
	void update();
	void setEventSystem(EventSystem* es);
	void calculateFps();
	float getDtTime();
	int getFps();

private:
	EventSystem * es; //pointer for event system

	//game infomation
	int fps;
	sf::Clock clock;
	sf::Time time;
};