#pragma once
#include "..\glm\glm.hpp"
#include "Box2D\Box2D.h"
#include <SFML\Graphics.hpp>

class Entity{
public:
	//render type
	enum rType {
		MESH,
		SPRITE,
		SHAPE,
		CHARACTER,
		BULLET,
		STATIC_SHAPE,
		BORDER,
		WEAPON_SPAWN
	};

	//entityCollisionCategory
	enum collisionCategory
	{
		DEFAULT = 0x0001,
		PLAYER1 = 0x0002,
		PLAYER2 = 0x0004,
		BULLET1 = 0x0008,
		BULLET2 = 0x00016,
	};

	//collision data
	struct collisionData
	{
		void* pointer;
		int type;
	};
	
	//entity type
	enum entityType
	{
		ENTITY_DEFAULT,
		ENTITY_STATICSPRITE,
		ENTITY_SHAPE,
		ENTITY_CHARACTER,
		ENTITY_BULLET,
		ENTITY_BORDER,
		ENTITY_WEAPON
	};
	/* Entity should be created in main.cpp and deleted in main.cpp! Later will managed with game player sub-system. */
	Entity();
	virtual ~Entity();

	float UNIT_PIXEL = 10;

	//getter and setter for the data
	//set position will only work before add into physics system (need another way to move object)
	virtual void setPosition(glm::vec2 position);
	virtual glm::vec2 getPosition();
	void setVelocity(glm::vec2 velocity);
	glm::vec2 getVelocity();
	void setOrigin(glm::vec2 origin);
	glm::vec2 getOrigin();
	void setWidth(float width);
	float getWidth();
	void setHeight(float height);
	float getHeight();
	virtual void setScale(glm::vec2 scale);
	glm::vec2 getScale();
	void setRenderType(int type);
	int getRenderType();
	virtual void setRotation(float rotation);
	virtual float getRotation();

	//update physics information
	void updateCollisionRect();

	//physics information
	b2BodyDef bodyDef;
	b2Body* body;
	//collision rectangle
	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;

	//entity type
	int entityType = ENTITY_DEFAULT;
	
protected:
	//general infomation
	glm::vec2 position; //here, the unit to define position is pixel
	glm::vec2 velocity; //the unit to define velocity is meter (in the game world)
	glm::vec2 scale;
	glm::vec2 origin;
	float width; //in pixel
	float height; //in pixel
	float rotation;

	//render infomation
	int renderType;

	//user data
	collisionData* cd;

	
};