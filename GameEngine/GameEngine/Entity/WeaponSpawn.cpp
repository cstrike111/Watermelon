#include "WeaponSpawn.h"

WeaponSpawn::WeaponSpawn(AssetManager* am) {
	//box2d configuration (default)
	polygonShape.SetAsBox(20.0f, 5.0f); //set as a box
	bodyDef.position.Set(20.0f, -5.0f);
	cd = new collisionData();
	cd->pointer = this;
	cd->type = entityType;
	bodyDef.userData = cd;

	//set up the weapon
	weapon = new WeaponEntity();
	weapon->setSprite(new sf::Sprite());
	weapon->setPosition(this->getPosition());
	weapon->getSprite()->setOrigin(45 / 2, 45 / 2);
	weapon->setTextureRect(0, 0, 45, 45);
	weapon->setWidth(45);
	weapon->setHeight(45);
	weapon->bodyDef.position.Set(this->body->GetPosition().x, this->body->GetPosition().y);
	weapon->polygonShape.SetAsBox(4.5f, 4.5f); //half length!
	this->am = am;
}

WeaponSpawn::~WeaponSpawn() {
	delete shape;
	shape = nullptr;
	delete weapon;
	weapon = nullptr;
}

void WeaponSpawn::updateRenderInfo() {
	shape->setPosition(position.x, position.y);
	shape->setRotation(rotation);
	shape->setScale(scale.x, scale.y);
}

void WeaponSpawn::getRenderInfo() {
	sf::Vector2f pos = shape->getPosition();
	position.x = pos.x;
	position.y = pos.y;
	rotation = shape->getRotation();
	sf::Vector2f s = shape->getScale();
	scale.x = s.x;
	scale.y = s.y;
}

void WeaponSpawn::setTexture(sf::Texture* texture) {
	shape->setTexture(texture);
}

void WeaponSpawn::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight) {
	shape->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

void WeaponSpawn::setShape(sf::Shape* shape) {
	this->shape = shape;
	position.x = shape->getPosition().x;
	position.y = shape->getPosition().y;
	origin.x = shape->getOrigin().x;
	origin.y = shape->getOrigin().y;
	scale.x = shape->getScale().x;
	scale.y = shape->getScale().y;
	rotation = shape->getRotation();
}

sf::Shape* WeaponSpawn::getShape() {
	return shape;
}

void WeaponSpawn::setPosition(glm::vec2 position) {
	this->position = position;
	shape->setPosition(position.x, position.y);
}

void WeaponSpawn::setOrigin(glm::vec2 origin) {
	this->origin = origin;
	shape->setOrigin(origin.x, origin.y);
}

void WeaponSpawn::setScale(glm::vec2 scale) {
	this->scale = scale;
	shape->setScale(scale.x, scale.y);
}

void WeaponSpawn::setRotation(float rotation) {
	this->rotation = rotation;
	shape->setRotation(rotation);
}

void WeaponSpawn::spawnAweapon()
{
	if(currentTime > spawnTime)
	{
		if(!spawn)
		{
			//create randon weapon
			srand(time(NULL));
			createWeapon(rand() % 5);
			//set next spawn time
			spawnTime = rand() % MAX_SPAWN_TIME + MIN_SPAWN_TIME;
			spawn = true;
		}
	}
	
}

void WeaponSpawn::createWeapon(int type)
{
	switch(type)
	{
	case WeaponEntity::AWP:
		weapon->setTexture((sf::Texture*) am->loadAsset("asset/texture/awp.png", AssetManager::TEXTURE));
		weapon->ammo = 5;
		weapon->fireRate = 3;
		weapon->damage = 200;
		weapon->speed = 1000;
		break;
	case WeaponEntity::SMG:
		weapon->setTexture((sf::Texture*) am->loadAsset("asset/texture/smg.png", AssetManager::TEXTURE));
		weapon->ammo = 30;
		weapon->fireRate = 0.05;
		weapon->damage = 75;
		weapon->speed = 1000;
		break;
	case WeaponEntity::RIFLE:
		weapon->setTexture((sf::Texture*) am->loadAsset("asset/texture/rifle.png", AssetManager::TEXTURE));
		weapon->ammo = 30;
		weapon->fireRate = 0.1;
		weapon->damage = 100;
		weapon->speed = 1000;
		break;
	case WeaponEntity::ROCKET:
		weapon->setTexture((sf::Texture*) am->loadAsset("asset/texture/rocket.png", AssetManager::TEXTURE));
		weapon->ammo = 2;
		weapon->fireRate = 5;
		weapon->damage = 500;
		weapon->speed = 25;
		break;
	case WeaponEntity::HADOUKEN:
		weapon->setTexture((sf::Texture*) am->loadAsset("asset/texture/hadouken.png", AssetManager::TEXTURE));
		weapon->ammo = 10;
		weapon->fireRate = 2;
		weapon->damage = 100;
		weapon->speed = 50;
		break;
	}
}

void WeaponSpawn::cleanTheWeapon()
{
	weapon->pickup = true;
	currentTime = 0;
}

void WeaponSpawn::updateTime(float time)
{
	currentTime += time / 1000;
}

void WeaponSpawn::setCollisionRect(float width, float height) {
	polygonShape.SetAsBox(width / (UNIT_PIXEL * 2), height / (UNIT_PIXEL * 2));
}

void WeaponSpawn::updatePhysics() {
	glm::vec2 pos = getPosition();
	bodyDef.position.Set(pos.x / UNIT_PIXEL, -pos.y / UNIT_PIXEL);
}
