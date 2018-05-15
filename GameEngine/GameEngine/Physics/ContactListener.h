#pragma once
#include "Box2D/Box2D.h"
#include "../EventSystem/EventSystem.h"
#include "../Entity/CharacterEntity.h"
#include "../Entity/StaticSpriteEntity.h"
#include "../Entity/BulletEntity.h"
#include "../Entity/Entity.h"

class ContactListener : public b2ContactListener
{
public:
	ContactListener();
	~ContactListener();

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void hitPlayer(CharacterEntity* player, BulletEntity* bullet);
	void hitPlatform(StaticSpriteEntity* platform, BulletEntity* bullet);
};

