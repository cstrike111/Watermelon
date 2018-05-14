#pragma once
#include "..\Graphic\Graphic.h"
#include "..\Physics\Physics.h"
#include "..\EventSystem\EventSystem.h"
#include "..\FileSystem\FileSystem.h"
#include "..\AssetManager\AssetManager.h"
#include "..\Entity\CharacterEntity.h"

class Game
{
public:
	Game(Physics* p, Graphic* g, EventSystem* e, AssetManager* am, FileSystem* f);
	~Game();

	//after loading the level, don't delete it after the level is finished. try to reuse it when it is necessary
	void loadLevel1();
	void update();

private:
	Physics * p;
	Graphic* g;
	EventSystem* e;
	FileSystem* f;
	AssetManager* am;

	//level information
	//level 1 (doodle world)
	bool level1Load = false;
	vector<StaticSpriteEntity*>* platformList; //don't forget to clean your memory!
	//pointer of entity
	CharacterEntity* player1;
	CharacterEntity* player2;
	StaticSpriteEntity* platform;
	StaticSpriteEntity* platform2;
	ShapeEntity* circle;
	CharacterEntity* animationTest;
};

