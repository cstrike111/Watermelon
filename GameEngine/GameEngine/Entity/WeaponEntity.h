#pragma once
#include "StaticSpriteEntity.h"

class WeaponEntity : public StaticSpriteEntity
{
public:
	enum WeaponType
	{
		AWP,
		SMG,
		RIFLE,
		ROCKET,
		HADOUKEN
	};
	WeaponEntity();
	~WeaponEntity();

	void updateRenderInfo();
	void getRenderInfo();
	//don't forget to update and set collision rectangle before put it into physics system
	//overrider some functions of base class and add some new function
	void setCollisionRect(float width, float height);
	void updatePhysics();
	void setTexture(sf::Texture* texture);
	void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setSprite(sf::Sprite* shape);
	sf::Sprite* getSprite();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);
	void setRotation(float rotation);

	//entity type
	int entityType = Entity::entityType::ENTITY_WEAPON;

	//weapon info
	float speed;
	float ammo;
	float damage;
	float fireRate;
	bool pickup;

private:
	//be careful, texture is not managed by this class
	sf::Sprite* sprite;
};

