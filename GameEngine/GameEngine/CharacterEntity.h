#pragma once
#include "Entity.h"

class CharacterEntity {
public:

	CharacterEntity();
	~CharacterEntity();

	void updatePos();
	void setTexture();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);

};