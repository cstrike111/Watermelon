#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <queue>
#include "Eventlist.h"

using namespace std;

class EventSystem {
public:
	EventSystem(sf::RenderWindow* window);
	~EventSystem();

	void addEvent(Event* e);
	void removeEvent();
	void checkFinish();
	queue<Event>* getEventQueue();
	void update();
	sf::Event getsfEvent();
	
private:
	queue<Event>* eventQueue;
	sf::RenderWindow* window;
	sf::Event sfEvent;
};