#pragma once
#include "Entity.h"

class CharacterEntity : public Entity {
public:
	CharacterEntity();
	~CharacterEntity();
	void updateRenderInfo();
	void getRenderInfo();
	void setTexture(sf::Texture* texture);
	void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setSprite(sf::Sprite* sprite);
	sf::Sprite* getSprite();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);
	void setRotation(float rotation);

private:
	sf::Sprite* sprite;
	//Animation
};