#pragma once
#include "glm\glm.hpp"
#include "Box2D\Box2D.h"
#include <SFML\Graphics.hpp>

class Entity {
public:
	//render type
	enum rType {
		MESH,
		SPRITE,
		SHAPE,
		CHARACTER
	};

	/* Entity should be created in main.cpp and deleted in main.cpp! Later will managed with game player sub-system. */
	Entity();
	~Entity();

	float UNIT_PIXEL = 50;

	//getter and setter for the data
	//set position will only work before add into physics system (need another way to move object)
	void setPosition(glm::vec2 position);
	glm::vec2 getPosition();
	void setVelocity(glm::vec2 velocity);
	glm::vec2 getVelocity();
	void setOrigin(glm::vec2 origin);
	glm::vec2 getOrigin();
	void setWidth(float width);
	float getWideth();
	void setHeight(float height);
	float getHeight();
	void setScale(glm::vec2 scale);
	glm::vec2 getScale();
	void setRenderType(int type);
	int getRenderType();
	void setRotation(float rotation);
	float getRotation();

	//update physics information
	void updateCollisionRect();

	//physics information
	b2BodyDef bodyDef;
	b2Body* body;
	//collision rectangle
	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;
	
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
	//Mesh
	//Texture
	
};