#pragma once
#include "Entity.h"
#include "Animation.h"

class CharacterEntity : public Entity {
public:
	CharacterEntity();
	~CharacterEntity();
	void updateRenderInfo();
	void getRenderInfo();
	//don't forget to update and set collision rectangle before put it into physics system
	//overrider some functions of base class and add some new function
	void setCollisionRect(float width, float height);
	void updatePhysics();
	void setTexture(sf::Texture* texture);
	void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setSprite(sf::Sprite* sprite);
	sf::Sprite* getSprite();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);
	void setRotation(float rotation);
	void setAnimation(Animation a);
	
	//play animation
	void playAnimation();
	//play current frame of animation
	void playCurrentFrame(int index);

	Animation a;
	//get animation?
	bool isAnimated = false;
private:
	sf::Sprite* sprite;

	
};