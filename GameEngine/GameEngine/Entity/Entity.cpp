#include "Entity.h"
#include <iostream>

Entity::Entity() {
	position = glm::vec2(0, 0);
	velocity = glm::vec2(0, 0);
	scale = glm::vec2(0, 0);
	origin = glm::vec2(0,0);
	cd = new collisionData();
	cd->pointer = this;
	cd->type = entityType;
}

Entity::~Entity() {
	delete cd;
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

void Entity::setOrigin(glm::vec2 origin) {
	this->origin = origin;
}

glm::vec2 Entity::getOrigin() {
	return origin;
}

void Entity::setWidth(float width) {
	this->width = width;
}

float Entity::getWidth() {
	return width;
}

void Entity::setHeight(float height) {
	this->height = height;
}

float Entity::getHeight() {
	return height;
}

void Entity::setScale(glm::vec2 scale) {
	this->scale = scale;
	std::cout << "change scale" << std::endl;
}

glm::vec2 Entity::getScale() {
	return scale;
}

void Entity::setRenderType(int type) {
	this->renderType = type;
}

int Entity::getRenderType() {
	return renderType;
}

void Entity::setRotation(float rotation) {
	this->rotation = rotation;
}

float Entity::getRotation() {
	return rotation;
}

void Entity::updateCollisionRect() {
	polygonShape.SetAsBox(width / (UNIT_PIXEL * 2), height / (UNIT_PIXEL * 2));
}