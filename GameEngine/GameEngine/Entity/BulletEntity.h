#pragma once
#include "Entity.h"

class BulletEntity : public Entity {
public:
	BulletEntity();
	~BulletEntity();
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

	//parameter of bullet
	float bulletSpeed = 1;

	//entity type
	int entityType = Entity::entityType::ENTITY_BULLET;

	//is the bullet active?
	bool active = true;
private:
	sf::Shape* shape;
};