#pragma once
#include "glm\glm.hpp"
#include <SFML\Graphics.hpp>

class Entity {
public:
	//render type
	enum rType {
		MESH,
		SPRITE,
		SHAPE
	};
	/* Entity should be created in main.cpp and deleted in main.cpp! */
	Entity();
	~Entity();

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
	
protected:
	//physics infomation
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 scale;
	glm::vec2 origin;
	float width;
	float height;
	//collision rectangle

	//render infomation
	int renderType;
	//Mesh
	//Texture
};