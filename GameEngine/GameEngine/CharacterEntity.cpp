#include "CharacterEntity.h"

CharacterEntity::CharacterEntity() {
	//box2d configuration (default)
	bodyDef.type = b2_dynamicBody; //set the body type
	polygonShape.SetAsBox(1.0f, 1.0f); //set as a box
	bodyDef.position.Set(0.0f, 0.0f);
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
}

CharacterEntity::~CharacterEntity() {
	delete sprite;
	sprite = nullptr;
}

void CharacterEntity::updateRenderInfo() {
	sprite->setPosition(position.x, position.y);
	sprite->setRotation(rotation);
	sprite->setScale(scale.x, scale.y);
}

void CharacterEntity::getRenderInfo() {
	sf::Vector2f pos = sprite->getPosition();
	position.x = pos.x;
	position.y = pos.y;
	rotation = sprite->getRotation();
	sf::Vector2f s = sprite->getScale();
	scale.x = s.x;
	scale.y = s.y;
}

void CharacterEntity::setTexture(sf::Texture* texture) {
	sprite->setTexture(*texture);
}

void CharacterEntity::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight) {
	sprite->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

void CharacterEntity::setSprite(sf::Sprite* sprite) {
	this->sprite = sprite;
	position.x = sprite->getPosition().x;
	position.y = sprite->getPosition().y;
	origin.x = sprite->getOrigin().x;
	origin.y = sprite->getOrigin().y;
	scale.x = sprite->getScale().x;
	scale.y = sprite->getScale().y;
	rotation = sprite->getRotation();
}

sf::Sprite* CharacterEntity::getSprite() {
	return sprite;
}

void CharacterEntity::setPosition(glm::vec2 position) {
	this->position = position;
	sprite->setPosition(position.x, position.y);
}

void CharacterEntity::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	sprite->setOrigin(origin.x, origin.y);
}

void CharacterEntity::setScale(glm::vec2 scale) {
	this->scale = scale;
	sprite->setScale(scale.x, scale.y);
}

void CharacterEntity::setRotation(float rotation) {
	this->rotation = rotation;
	sprite->setRotation(rotation);
}