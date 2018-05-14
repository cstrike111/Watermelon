#pragma once
#include <string>
#include <map>
#include "Entity.h"
#include "EventSystem.h"
#include "Profile.h"
#include "Box2D\Box2D\Box2D.h"
#include <vector> 

using namespace std;

class Physics {
public:
	/* For the unit conversion: 1 m = 10 pixels. 1 m = 1 unit pixel. */
	Physics(b2Vec2 gravity);
	~Physics();

	//constant
	float UNIT_PIXEL = 10;
	bool collisionDetect(Entity* e1, Entity* e2); //collision detect between 2 entity
	void update(); //update every entity and apply some features (gravity etc.)
	void handleEvent(int eventType); //handle the events
	//add entity to the system
	void addStaticEntity(Entity* e); //add static entity
	void addDynamicEntity(Entity* e); //add dynamic entity
	void setEventSystem(EventSystem* es);
	void getPlayer(Entity* player); //get player pointer
	void setGravity(b2Vec2 gravity); //change the gravity
	void createBody(Entity* e); //create box2d body
	void setProfileSystem(Profile* pro);

private:
	/* Here! This is a list of pointers of entities. Don't forget clean the memory of 
	entities after you use them. */
	vector<Entity*> dynamicEntityList;
	vector<Entity*> staticEntityList;
	Entity* player1; //player1 object
	Entity* player2; //plyaer2 object

	//static entity list?
	EventSystem* es; //get the event system
	Profile* pro; //get the profile system

	//store the information of box2d
	b2Vec2 gravity;
	b2World* world;
	float timeStep = 1.0f / 60.0f;

	//parameter for the player
	float PLAYER_MOVE_SPEED = 50;
};