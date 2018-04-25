#pragma once
#include "Entity.h"

class ShapeEntity: public Entity {
public:
	ShapeEntity();
	~ShapeEntity();
	void updateRenderInfo();
	void getRenderInfo();
	void setTexture(sf::Texture* texture);
	void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setShape(sf::Shape* shape);
	sf::Shape* getShape();
	void setPosition(glm::vec2 position);
	void setOrigin(glm::vec2 origin);
	void setScale(glm::vec2 scale);
	void setRotation(float rotation);

private:
	sf::Shape* shape;
};