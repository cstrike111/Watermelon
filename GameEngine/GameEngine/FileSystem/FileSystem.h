#pragma once
#include "..\EventSystem\EventSystem.h"
#include "..\Entity\Entity.h"
#include "..\Entity\ShapeEntity.h"
#include <iostream>
#include <fstream>
#include "..\Entity\StaticSpriteEntity.h"
#include "..\AssetManager\AssetManager.h"
#include "GameData.h"

class FileSystem
{
public:
	enum type
	{
		PLAYER1_SPAWN,
		PLAYER2_SPAWN,
		PLATFORM
	};

	FileSystem(AssetManager* am);
	~FileSystem();

	float UNIT_PIXEL = 10;
	void handleEvent(int eventType); //handle event
	void update(); //update the system
	void setEventSystem(EventSystem* es); //set event system
	bool save(); //currently, it can only save the information of player
	bool load(); //again, it can only load the information of player for now
	bool loadLevel1(GameData* d);
	void setPlayer(Entity* player); //let the system know which player's information needed to be saved
	void demoCircle(ShapeEntity* circle); //set a circle for demo

private:
	EventSystem * es; //pointer for event system
	AssetManager* am; //pointer to asset manager
	Entity* player; //store the pointer of player
	ShapeEntity* circle; //demo circle
};

