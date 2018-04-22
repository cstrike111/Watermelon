#include "ShapeEntity.h"

ShapeEntity::ShapeEntity() {
	
}

ShapeEntity::~ShapeEntity() {
	delete shape;
	shape = nullptr;
}

void ShapeEntity::updatePos() {
	shape->setPosition(position.x, position.y);
}

void ShapeEntity::setShape(sf::Shape* shape) {
	this->shape = shape;
	position.x = shape->getPosition().x;
	position.y = shape->getPosition().y;
	origin.x = shape->getOrigin().x;
	origin.y = shape->getOrigin().y;
	scale.x = shape->getScale().x;
	scale.y = shape->getScale().y;

}

sf::Shape* ShapeEntity::getShape() {
	return shape;
}

void ShapeEntity::setPosition(glm::vec2 position) {
	this->position = position;
	shape->setPosition(position.x, position.y);
}

void ShapeEntity::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	shape->setOrigin(origin.x, origin.y);
}

void ShapeEntity::setScale(glm::vec2 scale) {
	this->scale = scale;
	shape->setScale(scale.x, scale.y);
}