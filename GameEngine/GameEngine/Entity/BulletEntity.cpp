#include "BulletEntity.h"

BulletEntity::BulletEntity() {
	//box2d configuration (default)
	bodyDef.type = b2_dynamicBody; //set the body type
	bodyDef.fixedRotation = true;
	polygonShape.SetAsBox(1.0f, 1.0f); //set as a box
	bodyDef.position.Set(0.0f, 0.0f);
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
}

BulletEntity::~BulletEntity() {
	delete shape;
	shape = nullptr;
}

void BulletEntity::updateRenderInfo() {
	shape->setPosition(position.x, position.y);
	shape->setRotation(rotation);
	shape->setScale(scale.x, scale.y);
}

void BulletEntity::getRenderInfo() {
	sf::Vector2f pos = shape->getPosition();
	position.x = pos.x;
	position.y = pos.y;
	rotation = shape->getRotation();
	sf::Vector2f s = shape->getScale();
	scale.x = s.x;
	scale.y = s.y;
}

void BulletEntity::setCollisionRect(float width, float height) {
	polygonShape.SetAsBox(width / (UNIT_PIXEL * 2), height / (UNIT_PIXEL * 2));
}

void BulletEntity::updatePhysics() {
	glm::vec2 pos = getPosition();
	bodyDef.position.Set(pos.x / UNIT_PIXEL, -pos.y / UNIT_PIXEL);
}

void BulletEntity::setTexture(sf::Texture* texture) {
	shape->setTexture(texture);
}

void BulletEntity::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight) {
	shape->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

void BulletEntity::setShape(sf::Shape* shape) {
	this->shape = shape;
	position.x = shape->getPosition().x;
	position.y = shape->getPosition().y;
	origin.x = shape->getOrigin().x;
	origin.y = shape->getOrigin().y;
	scale.x = shape->getScale().x;
	scale.y = shape->getScale().y;
	rotation = shape->getRotation();
}

sf::Shape* BulletEntity::getShape() {
	return shape;
}

void BulletEntity::setPosition(glm::vec2 position) {
	this->position = position;
	shape->setPosition(position.x, position.y);
}

void BulletEntity::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	shape->setOrigin(origin.x, origin.y);
}

void BulletEntity::setScale(glm::vec2 scale) {
	this->scale = scale;
	shape->setScale(scale.x, scale.y);
}

void BulletEntity::setRotation(float rotation) {
	this->rotation = rotation;
	shape->setRotation(rotation);
}