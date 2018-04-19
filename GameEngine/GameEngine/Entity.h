#pragma once
#include "glm\glm.hpp"


class Entity {
public:
	//render type
	enum rType {
		MESH,
		SPRITE
	};
	Entity();
	~Entity();

	//getter and setter for the data
	void setPosition(glm::vec2 position);
	glm::vec2 getPosition();
	void setVelocity(glm::vec2 velocity);
	glm::vec2 getVelocity();
	void setOriginX(float originX);
	float getOriginX();
	void setOriginY(float originY);
	float getOriginY();
	void setWidth(float width);
	float getWideth();
	void setHeight(float height);
	float getHeight();
	void setRenderType(int type);
	int getRenderType();
	
private:
	//physics infomation
	glm::vec2 position;
	glm::vec2 velocity;
	float originX;
	float originY;
	float width;
	float height;
	//collision rectangle

	//render infomation
	int renderType;
	//Mesh
	//Texture
};