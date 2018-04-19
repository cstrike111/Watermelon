#include "Entity.h"


Entity::Entity() {
	position = glm::vec2(0, 0);
	velocity = glm::vec2(0, 0);
	originX = 0;
	originY = 0;
	width = 0;
	height = 0;
	renderType = SPRITE;
}

Entity::~Entity() {

}

void Entity::setPosition(glm::vec2 position) {
	this->position = position;
}

glm::vec2 Entity::getPosition() {
	return position;
}

void Entity::setVelocity(glm::vec2 velocity) {
	this->velocity = velocity;
}

glm::vec2 Entity::getVelocity() {
	return velocity;
}

void Entity::setOriginX(float originX) {
	this->originX = originX;
}

float Entity::getOriginX() {
	return originX;
}

void Entity::setOriginY(float originY) {
	this->originY = originY;
}

float Entity::getOriginY() {
	return originY;
}

void Entity::setWidth(float width) {
	this->width = width;
}

float Entity::getWideth() {
	return width;
}

void Entity::setHeight(float height) {
	this->height = height;
}

float Entity::getHeight() {
	return height;
}

void Entity::setRenderType(int type) {
	this->renderType = type;
}

int Entity::getRenderType() {
	return renderType;
}