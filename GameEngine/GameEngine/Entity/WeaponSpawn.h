#pragma once
#include "StaticShapeEntity.h"
#include "WeaponEntity.h"
#include "../AssetManager/AssetManager.h"

class WeaponSpawn : public StaticShapeEntity
{
public:
	WeaponSpawn(AssetManager* am);
	~WeaponSpawn();

	void updateRenderInfo();
	void getRenderInfo();
	//don't forget to update and set collision rectangle before put it into physics system
	//overrider some functions of base class and add some new function
	void setCollisionRect(float width, float height);
	void updatePhysics();
	void setTexture(sf::Texture* texture);
	void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setShape(sf::Shape* shape);
	sf::Shape* getShape();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);
	void setRotation(float rotation);
	void spawnAweapon();
	void createWeapon(int type);
	void cleanTheWeapon();
	void updateTime(float time);

	//entity type
	int entityType = Entity::entityType::ENTITY_STATICSPRITE;
	
	//Assetmanager pointer
	AssetManager* am;

private:
	//be careful, texture is not managed by this class
	sf::Shape* shape;
	//timer
	float spawnTime = MIN_SPAWN_TIME;
	float currentTime;
	int MAX_SPAWN_TIME = 30;
	int MIN_SPAWN_TIME = 5;
	bool spawn = false;
	WeaponEntity* weapon;
};

