#include "StaticSpriteEntity.h"

StaticSpriteEntity::StaticSpriteEntity() {
	//box2d configuration (default)
	polygonShape.SetAsBox(20.0f, 5.0f); //set as a box
	bodyDef.position.Set(20.0f, -5.0f);
}

StaticSpriteEntity::~StaticSpriteEntity() {
	delete sprite;
	sprite = nullptr;
}

void StaticSpriteEntity::updateRenderInfo() {
	sprite->setPosition(position.x, position.y);
	sprite->setRotation(rotation);
	sprite->setScale(scale.x, scale.y);
}

void StaticSpriteEntity::getRenderInfo() {
	sf::Vector2f pos = sprite->getPosition();
	position.x = pos.x;
	position.y = pos.y;
	rotation = sprite->getRotation();
	sf::Vector2f s = sprite->getScale();
	scale.x = s.x;
	scale.y = s.y;
}

void StaticSpriteEntity::setTexture(sf::Texture* texture) {
	sprite->setTexture(*texture);
}

void StaticSpriteEntity::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight) {
	sprite->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

void StaticSpriteEntity::setSprite(sf::Sprite* sprite) {
	this->sprite = sprite;
	position.x = sprite->getPosition().x;
	position.y = sprite->getPosition().y;
	origin.x = sprite->getOrigin().x;
	origin.y = sprite->getOrigin().y;
	scale.x = sprite->getScale().x;
	scale.y = sprite->getScale().y;
	rotation = sprite->getRotation();
}

sf::Sprite* StaticSpriteEntity::getSprite() {
	return sprite;
}

void StaticSpriteEntity::setPosition(glm::vec2 position) {
	this->position = position;
	sprite->setPosition(position.x, position.y);
}

void StaticSpriteEntity::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	sprite->setOrigin(origin.x, origin.y);
}

void StaticSpriteEntity::setScale(glm::vec2 scale) {
	this->scale = scale;
	sprite->setScale(scale.x, scale.y);
}

void StaticSpriteEntity::setRotation(float rotation) {
	this->rotation = rotation;
	sprite->setRotation(rotation);
}

void StaticSpriteEntity::setCollisionRect(float width, float height) {
	polygonShape.SetAsBox(width / (UNIT_PIXEL * 2), height / (UNIT_PIXEL * 2));
}

void StaticSpriteEntity::updatePhysics() {
	glm::vec2 pos = getPosition();
	bodyDef.position.Set(pos.x / UNIT_PIXEL, -pos.y / UNIT_PIXEL);
}
