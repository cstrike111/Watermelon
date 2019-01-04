#pragma once
#include <vector>
#include "..\Entity\StaticSpriteEntity.h"
#include "..\Entity\StaticShapeEntity.h"

class GameData
{
public:
	GameData()
	{
		
	}

	float player1SpawnX = 0;
	float player1SpawnY = 0;
	float player2SpawnX = 0;
	float player2SpawnY = 0;
	std::vector<StaticSpriteEntity*>* platformList;
	std::vector<boundingBox*>* border;
	std::vector<WeaponSpawn*>* weaponSpawn;

};

