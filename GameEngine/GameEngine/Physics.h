#pragma once
#include <string>
#include <map>
#include "Entity.h"
#include "EventSystem.h"
#include "Box2D\Box2D.h"
#include <vector>

using namespace std;

class Physics {
public:
	/* For the unit conversion: 1 cm = 0.4 pixels. 1 m = 40 pixels */
	Physics();
	~Physics();

	bool collisionDetect(Entity* e1, Entity* e2); //collision detect between 2 entity
	void update(); //update every entity and apply some features (gravity etc.)
	void handleEvent(int eventType); //handle the events
	void addEntity(Entity* e); //add entity to the system
	void setEventSystem(EventSystem* es);
	void getPlayer(Entity* player);

private:
	/* Here! This is a list of pointers of entities. Don't forget clean the memory of 
	entities after you use them. */
	vector<Entity*> entityList;
	//static entity list?
	EventSystem* es; //get the event system
	Entity* player;
};