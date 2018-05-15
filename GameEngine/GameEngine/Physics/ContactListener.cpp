#include "ContactListener.h"


ContactListener::ContactListener()
{

}

ContactListener::~ContactListener()
{
}

void ContactListener::BeginContact(b2Contact * contact)
{
	Entity::collisionData bodyUserDataA = *((Entity::collisionData*)contact->GetFixtureA()->GetBody()->GetUserData());
	Entity::collisionData bodyUserDataB = *((Entity::collisionData*)contact->GetFixtureB()->GetBody()->GetUserData());
	switch(bodyUserDataA.type)
	{
	case Entity::entityType::ENTITY_BULLET:
		if (bodyUserDataB.type == Entity::entityType::ENTITY_CHARACTER)
		{
			hitPlayer((CharacterEntity*)bodyUserDataB.pointer, (BulletEntity*)bodyUserDataA.pointer);
		}
		if (bodyUserDataB.type == Entity::entityType::ENTITY_STATICSPRITE)
		{
			hitPlatform((StaticSpriteEntity*)bodyUserDataB.pointer, (BulletEntity*)bodyUserDataA.pointer);
		}
		break;
	case Entity::entityType::ENTITY_CHARACTER:
		if (bodyUserDataB.type == Entity::entityType::ENTITY_BULLET)
		{
			hitPlayer((CharacterEntity*)bodyUserDataA.pointer, (BulletEntity*)bodyUserDataB.pointer);
		}
		break;
	case Entity::entityType::ENTITY_STATICSPRITE:
		if (bodyUserDataB.type == Entity::entityType::ENTITY_BULLET)
		{
			hitPlatform((StaticSpriteEntity*)bodyUserDataA.pointer, (BulletEntity*)bodyUserDataB.pointer);
		}
		break;
	}
	

}

void ContactListener::EndContact(b2Contact * contact)
{
}

void ContactListener::hitPlayer(CharacterEntity * player, BulletEntity * bullet)
{
	float x = bullet->body->GetLinearVelocity().x;
	if (x > 0 && bullet->active == true)
	{
		player->hit.push_back(CharacterEntity::hitDirection::LEFT);
		bullet->active = false;
	}else if (x < 0 && bullet->active == true)
	{
		player->hit.push_back(CharacterEntity::hitDirection::RIGHT);
		bullet->active = false;
	}
	cout << "hit" << endl;
}

void ContactListener::hitPlatform(StaticSpriteEntity * player, BulletEntity * bullet)
{
	if(bullet->active)
	{
		bullet->active = false;
	}
	cout << "hit" << endl;
}
