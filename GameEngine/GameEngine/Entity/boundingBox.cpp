#include "boundingBox.h"

boundingBox::boundingBox() {
	//box2d configuration (default)
	polygonShape.SetAsBox(20.0f, 5.0f); //set as a box
	bodyDef.position.Set(20.0f, -5.0f);
	cd = new collisionData();
	cd->pointer = this;
	cd->type = entityType;
	bodyDef.userData = cd;
}

boundingBox::~boundingBox() {
	delete shape;
	shape = nullptr;
}

void boundingBox::updateRenderInfo() {
	shape->setPosition(position.x, position.y);
	shape->setRotation(rotation);
	shape->setScale(scale.x, scale.y);
}

void boundingBox::getRenderInfo() {
	sf::Vector2f pos = shape->getPosition();
	position.x = pos.x;
	position.y = pos.y;
	rotation = shape->getRotation();
	sf::Vector2f s = shape->getScale();
	scale.x = s.x;
	scale.y = s.y;
}

void boundingBox::setTexture(sf::Texture* texture) {
	shape->setTexture(texture);
}

void boundingBox::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight) {
	shape->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

void boundingBox::setShape(sf::Shape* shape) {
	this->shape = shape;
	position.x = shape->getPosition().x;
	position.y = shape->getPosition().y;
	origin.x = shape->getOrigin().x;
	origin.y = shape->getOrigin().y;
	scale.x = shape->getScale().x;
	scale.y = shape->getScale().y;
	rotation = shape->getRotation();
}

sf::Shape* boundingBox::getShape() {
	return shape;
}

void boundingBox::setPosition(glm::vec2 position) {
	this->position = position;
	shape->setPosition(position.x, position.y);
}

void boundingBox::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	shape->setOrigin(origin.x, origin.y);
}

void boundingBox::setScale(glm::vec2 scale) {
	this->scale = scale;
	shape->setScale(scale.x, scale.y);
}

void boundingBox::setRotation(float rotation) {
	this->rotation = rotation;
	shape->setRotation(rotation);
}

void boundingBox::setCollisionRect(float width, float height) {
	polygonShape.SetAsBox(width / (UNIT_PIXEL * 2), height / (UNIT_PIXEL * 2));
}

void boundingBox::updatePhysics() {
	glm::vec2 pos = getPosition();
	bodyDef.position.Set(pos.x / UNIT_PIXEL, -pos.y / UNIT_PIXEL);
}
