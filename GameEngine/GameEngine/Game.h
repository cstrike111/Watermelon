#pragma once
#include "..\Graphic\Graphic.h"
#include "..\Physics\Physics.h"
#include "..\EventSystem\EventSystem.h"
#include "..\FileSystem\FileSystem.h"
#include "..\AssetManager\AssetManager.h"
#include "..\Entity\CharacterEntity.h"
#include "..\EventSystem\EventSystem.h"
#include "..\Entity\BulletEntity.h"
#include "..\Entity\StaticShapeEntity.h"
#include "..\Entity\WeaponSpawn.h"
#include "Profile/Profile.h"
#include "Audio/Audio.h"

class Game
{
public:
	Game(Physics* p, Graphic* g, EventSystem* e, AssetManager* am, FileSystem* f, Profile* pro, Audio* audio);
	//entities deletion handled by game object
	~Game();

	//after loading the level, don't delete it after the level is finished. try to reuse it when it is necessary
	void loadLevel1();
	void update();
	void handleEvent(int eventType);

	//pointer of players and their entities
	CharacterEntity* player1;
	CharacterEntity* player2;
	vector<BulletEntity*> bullet1;
	vector<BulletEntity*> bullet2;
	//Timer for adding bullets (miliseconds)
	float player1BulletTime = 0;
	float player2BulletTime = 0;
	const int MAX_AMMO = 4;
	const float addBulletTime = 2000;
	
	//default spawn point
	float player1spawnX;
	float player1spawnY;
	float player2spawnX;
	float player2spawnY;

	//level information
	//the position is the center of the entity
	bool levelLoad = false;
	bool level1Load = false;
	vector<StaticSpriteEntity*>* platformList; //don't forget to clean your memory!
	vector<boundingBox*>* borderList;
	vector<WeaponSpawn*>* weaponSpawn;

	//win flag
	bool win = false;
	bool won = true; //prevent update twice

private:
	Physics * p;
	Graphic* g;
	EventSystem* e;
	FileSystem* f;
	AssetManager* am;
	Profile* pro;
	Audio* audio;
	
	int currentLevel = 0;
	//level 1
	BulletEntity* createBullet(int player);
};

