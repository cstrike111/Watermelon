#pragma once
#include "Entity.h"

class CharacterEntity {
public:
	//render type
	enum rType {
		MESH,
		SPRITE,
		SHAPE
	};
	CharacterEntity();
	~CharacterEntity();

	//getter and setter for the data
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

	//physics information
	b2BodyDef bodyDef;
	b2Body* body;
	//collision rectangle
	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;

protected:
	//general infomation
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 scale;
	glm::vec2 origin;
	float width;
	float height;


	//render infomation
	int renderType;
	//Mesh
	//Texture
};