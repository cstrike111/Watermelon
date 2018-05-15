#include "ContactListener.h"


ContactListener::ContactListener()
{

}

ContactListener::~ContactListener()
{
}

void ContactListener::BeginContact(b2Contact * contact)
{
	Entity::collisionData* bodyUserDataA = (Entity::collisionData*)contact->GetFixtureA()->GetBody()->GetUserData();
	Entity::collisionData* bodyUserDataB = (Entity::collisionData*)contact->GetFixtureB()->GetBody()->GetUserData();
	switch(bodyUserDataA->type)
	{
	case Entity::entityType::ENTITY_BULLET:
		if (bodyUserDataB->type == Entity::entityType::ENTITY_CHARACTER)
		{
			hitPlayer((CharacterEntity*)bodyUserDataB->pointer, (BulletEntity*)bodyUserDataA->pointer);
		}
		if (bodyUserDataB->type == Entity::entityType::ENTITY_STATICSPRITE)
		{
			hitStaticObj((BulletEntity*)bodyUserDataA->pointer);
		}
		if (bodyUserDataB->type == Entity::entityType::ENTITY_BORDER)
		{
			hitStaticObj((BulletEntity*)bodyUserDataA->pointer);
		}
		break;
	case Entity::entityType::ENTITY_CHARACTER:
		if (bodyUserDataB->type == Entity::entityType::ENTITY_BULLET)
		{
			hitPlayer((CharacterEntity*)bodyUserDataA->pointer, (BulletEntity*)bodyUserDataB->pointer);
		}
		if (bodyUserDataB->type == Entity::entityType::ENTITY_BORDER)
		{
			CharacterEntity * player = (CharacterEntity*)bodyUserDataA->pointer;
			if(!win)
			{
				switch (player->playerNumber)
				{
				case 1:
					e->addEvent(new Player2Win());
					break;
				case 2:
					e->addEvent(new Player1Win());
					break;
				}
			}
		}
		if (bodyUserDataB->type == Entity::entityType::ENTITY_STATICSPRITE)
		{
			CharacterEntity * player = (CharacterEntity*)bodyUserDataA->pointer;
			player->jump = true;
			player->doubleJump = true;
		}
		break;
	case Entity::entityType::ENTITY_STATICSPRITE:
		if (bodyUserDataB->type == Entity::entityType::ENTITY_BULLET)
		{
			hitStaticObj((BulletEntity*)bodyUserDataB->pointer);
		}
		if (bodyUserDataB->type == Entity::entityType::ENTITY_CHARACTER)
		{
			CharacterEntity * player = (CharacterEntity*)bodyUserDataA->pointer;
			player->jump = true;
			player->doubleJump = true;
		}
		break;
	case Entity::entityType::ENTITY_BORDER:
		if (bodyUserDataB->type == Entity::entityType::ENTITY_BULLET)
		{
			hitStaticObj((BulletEntity*)bodyUserDataB->pointer);
		}
		if (bodyUserDataB->type == Entity::entityType::ENTITY_CHARACTER)
		{
			CharacterEntity * player = (CharacterEntity*)bodyUserDataA->pointer;
			if (!win)
			{
				switch (player->playerNumber)
				{
				case 1:
					e->addEvent(new Player2Win());
					break;
				case 2:
					e->addEvent(new Player1Win());
					break;
				}
			}
		}
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
		player->hit.push_back({ CharacterEntity::hitDirection::LEFT, bullet->damage });
		bullet->active = false;
	}else if (x < 0 && bullet->active == true)
	{
		player->hit.push_back({ CharacterEntity::hitDirection::RIGHT, bullet->damage });
		bullet->active = false;
	}
}

void ContactListener::hitStaticObj(BulletEntity * bullet)
{
	if(bullet->active)
	{
		bullet->active = false;
	}
}

void ContactListener::player1Win()
{
	e->addEvent(new Player1Win());
}

void ContactListener::player2Win()
{
	e->addEvent(new Player2Win());
}

