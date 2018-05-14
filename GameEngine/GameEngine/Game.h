#pragma once
#include "..\Graphic\Graphic.h"
#include "..\Physics\Physics.h"
#include "..\EventSystem\EventSystem.h"
#include "..\FileSystem\FileSystem.h"
#include "..\AssetManager\AssetManager.h"
#include "..\Entity\CharacterEntity.h"
#include "..\EventSystem\EventSystem.h"

class Game
{
public:
	Game(Physics* p, Graphic* g, EventSystem* e, AssetManager* am, FileSystem* f);
	~Game();

	//after loading the level, don't delete it after the level is finished. try to reuse it when it is necessary
	void loadLevel1();
	void update();
	void handleEvent(int eventType);

	//pointer of players and their entities
	CharacterEntity* player1;
	CharacterEntity* player2;
	vector<ShapeEntity*> bullet1;
	vector<ShapeEntity*> bullet2;
	
	//default spawn point
	float player1spawnX;
	float player1spawnY;
	float player2spawnX;
	float player2spawnY;

	//level information
	//the position is the center of the entity
	//level 1 (doodle world)
	bool level1Load = false;
	vector<StaticSpriteEntity*>* platformList; //don't forget to clean your memory!
	//pointer of entity
	StaticSpriteEntity* platform;
	StaticSpriteEntity* platform2;
	ShapeEntity* circle;
	CharacterEntity* animationTest;

private:
	Physics * p;
	Graphic* g;
	EventSystem* e;
	FileSystem* f;
	AssetManager* am;
	
	int currentLevel = 0;
	//level 1
	ShapeEntity* createBullet(int player);
};

