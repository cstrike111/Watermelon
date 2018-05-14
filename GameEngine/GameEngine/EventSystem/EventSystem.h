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

	void addEvent(Event* e); //add event
	void removeEvent(); //remove event
	void checkFinish(); //check whether the event is finished
	queue<Event>* getEventQueue(); //get the event queue
	void update(); //update the system
	
private:
	queue<Event>* eventQueue; //event queue pointer
	sf::RenderWindow* window; //window pointer
};