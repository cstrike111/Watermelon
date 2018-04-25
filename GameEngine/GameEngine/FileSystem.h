#pragma once
#include "EventSystem.h"
#include "Entity.h"
#include "ShapeEntity.h"
#include <iostream>
#include <fstream>

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	void handleEvent(int eventType);
	void update();
	void setEventSystem(EventSystem* es);
	bool save(); //currently, it can only save the information of player
	bool load(); //again, it can only load the information of player for now
	void setPlayer(Entity* player); //let the system know which player's information needed to be saved
	void demoCircle(ShapeEntity* circle); //set a circle for demo

private:
	EventSystem * es; //pointer for event system
	Entity* player; //store the pointer of player
	ShapeEntity* circle; //demo circle
};

