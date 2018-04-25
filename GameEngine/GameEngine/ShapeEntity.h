#pragma once
#include "Entity.h"

class ShapeEntity: public Entity {
public:
	ShapeEntity();
	~ShapeEntity();
	void updatePos();
	void setShape(sf::Shape* shape);
	sf::Shape* getShape();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);

protected:
	sf::Shape* shape;
	
};