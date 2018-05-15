#include "Physics.h"

Physics::Physics(b2Vec2 gravity) {
	world = new b2World(gravity);
	world->SetContactListener(&cl);
}

Physics::~Physics() {
	delete world;
	world = nullptr;
}

bool Physics::collisionDetect(Entity* e1, Entity* e2) {
	return true;
}

void Physics::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::PHYSICS)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popPhysics();
		}
	}

	//update physics
	//update dynamic objects' position
	world->Step(1.0f/60.0f, 6, 2);
	for (int i = 0; i < dynamicEntityList.size(); i++) {
		Entity* e = dynamicEntityList.at(i);
		b2Vec2 position = e->body->GetPosition();
		//covert into pixel
		float posX = position.x * UNIT_PIXEL;
		//float posX = position.x * UNIT_PIXEL - e->getWideth();
		//be careful: sfml doesn't share THE SAME COORDINATE SYSTEM with box2d
		float posY = position.y * -UNIT_PIXEL; 
		//float posY = (position.y * -UNIT_PIXEL) - e->getHeight();
		e->setPosition(glm::vec2(posX, posY));
	}

	//update bullet
	//bulletList1
	for (int i = 0; i < bulletList1.size(); i++) {
		Entity* e = bulletList1.at(i);
		b2Vec2 position = e->body->GetPosition();
		//covert into pixel
		float posX = position.x * UNIT_PIXEL;
		//float posX = position.x * UNIT_PIXEL - e->getWideth();
		//be careful: sfml doesn't share THE SAME COORDINATE SYSTEM with box2d
		float posY = position.y * -UNIT_PIXEL;
		//float posY = (position.y * -UNIT_PIXEL) - e->getHeight();
		e->setPosition(glm::vec2(posX, posY));
	}

	//bulletList2
	for (int i = 0; i < bulletList2.size(); i++) {
		Entity* e = bulletList2.at(i);
		b2Vec2 position = e->body->GetPosition();
		//covert into pixel
		float posX = position.x * UNIT_PIXEL;
		//float posX = position.x * UNIT_PIXEL - e->getWideth();
		//be careful: sfml doesn't share THE SAME COORDINATE SYSTEM with box2d
		float posY = position.y * -UNIT_PIXEL;
		//float posY = (position.y * -UNIT_PIXEL) - e->getHeight();
		e->setPosition(glm::vec2(posX, posY));
	}

	//get the render infomation of player
	pro->setPlayerRenderInfo(player1->getPosition().x, player1->getPosition().y);
	//get the physics information
	b2Vec2 vel = player1->body->GetLinearVelocity();
	b2Vec2 pos = player1->body->GetPosition();
	pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);

}

void Physics::handleEvent(int eventType) {
	b2Vec2 vel1 = player1->body->GetLinearVelocity();
	b2Vec2 pos1 = player1->body->GetPosition();
	float desiredVel1 = 0;
	float velChange1 = 0;
	float impulse1 = 0;
	b2Vec2 vel2 = player2->body->GetLinearVelocity();
	b2Vec2 pos2 = player2->body->GetPosition();
	float desiredVel2 = 0;
	float velChange2 = 0;
	float impulse2 = 0;
	switch (eventType) {
	case Event::PLAYER1_MOVE_UP:
		desiredVel1 = PLAYER_MOVE_SPEED;
		velChange1 = desiredVel1 - vel1.y;
		impulse1 = player1->body->GetMass() * velChange1;
		player1->body->ApplyLinearImpulse(b2Vec2(0, impulse1), player1->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER1_MOVE_DOWN:
		desiredVel1 = -PLAYER_MOVE_SPEED;
		velChange1 = desiredVel1 - vel1.y;
		impulse1 = player1->body->GetMass() * velChange1;
		player1->body->ApplyLinearImpulse(b2Vec2(0, impulse1), player1->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER1_MOVE_LEFT:
		desiredVel1 = -PLAYER_MOVE_SPEED;
		velChange1 = desiredVel1 - vel1.x;
		impulse1 = player1->body->GetMass() * velChange1;
		player1->body->ApplyLinearImpulse(b2Vec2(impulse1, 0), player1->body->GetWorldCenter(), true);
		//set the facing direction of the player
		player1->setScale(glm::vec2(-1, 1));
		break;
	case Event::PLAYER1_MOVE_RIGHT:
		desiredVel1 = PLAYER_MOVE_SPEED;
		velChange1 = desiredVel1 - vel1.x;
		impulse1 = player1->body->GetMass() * velChange1;
		player1->body->ApplyLinearImpulse(b2Vec2(impulse1, 0), player1->body->GetWorldCenter(), true);
		//set the facing direction of the player
		player1->setScale(glm::vec2(1, 1));
		break;
	case Event::PLAYER1_STOP_Y:
		desiredVel1 = 0;
		velChange1 = desiredVel1 - vel1.y;
		impulse1 = player1->body->GetMass() * velChange1;
		player1->body->ApplyLinearImpulse(b2Vec2(0, impulse1), player1->body->GetWorldCenter(), true);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos1.x, pos1.y, vel1.x, vel1.y);
		break;
	case Event::PLAYER1_STOP_X:
		desiredVel1 = 0;
		velChange1 = desiredVel1 - vel1.x;
		impulse1 = player1->body->GetMass() * velChange1;
		player1->body->ApplyLinearImpulse(b2Vec2(impulse1, 0), player1->body->GetWorldCenter(), true);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos1.x, pos1.y, vel1.x, vel1.y);
		break;
	case Event::SAVE:
		player1->setPosition(glm::vec2(pos1.x * UNIT_PIXEL, pos1.y * UNIT_PIXEL));
		player1->setVelocity(glm::vec2(vel1.x, vel1.y));
		break;
	case Event::PLAYER2_MOVE_UP:
		desiredVel2 = PLAYER_MOVE_SPEED;
		velChange2 = desiredVel2 - vel2.y;
		impulse2 = player2->body->GetMass() * velChange2;
		player2->body->ApplyLinearImpulse(b2Vec2(0, impulse2), player2->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER2_MOVE_DOWN:
		desiredVel2 = -PLAYER_MOVE_SPEED;
		velChange2 = desiredVel2 - vel2.y;
		impulse2 = player2->body->GetMass() * velChange2;
		player2->body->ApplyLinearImpulse(b2Vec2(0, impulse2), player2->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER2_MOVE_LEFT:
		desiredVel2 = -PLAYER_MOVE_SPEED;
		velChange2 = desiredVel2 - vel2.x;
		impulse2 = player2->body->GetMass() * velChange2;
		player2->body->ApplyLinearImpulse(b2Vec2(impulse2, 0), player2->body->GetWorldCenter(), true);
		//set the facing direction of the player
		player2->setScale(glm::vec2(-1, 1));
		break;
	case Event::PLAYER2_MOVE_RIGHT:
		desiredVel2 = PLAYER_MOVE_SPEED;
		velChange2 = desiredVel2 - vel2.x;
		impulse2 = player2->body->GetMass() * velChange2;
		player2->body->ApplyLinearImpulse(b2Vec2(impulse2, 0), player2->body->GetWorldCenter(), true);
		//set the facing direction of the player
		player2->setScale(glm::vec2(1, 1));
		break;
	case Event::PLAYER2_STOP_Y:
		desiredVel2 = 0;
		velChange2 = desiredVel2 - vel2.y;
		impulse2 = player2->body->GetMass() * velChange2;
		player2->body->ApplyLinearImpulse(b2Vec2(0, impulse2), player2->body->GetWorldCenter(), true);
		//pass the physics info
		//pro->setPlayerPhysicsInfo(pos1.x, pos1.y, vel1.x, vel1.y);
		break;
	case Event::PLAYER2_STOP_X:
		desiredVel2 = 0;
		velChange2 = desiredVel2 - vel2.x;
		impulse2 = player2->body->GetMass() * velChange2;
		player2->body->ApplyLinearImpulse(b2Vec2(impulse2, 0), player2->body->GetWorldCenter(), true);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos2.x, pos2.y, vel2.x, vel2.y);
		break;
	default:
		break;
	}
	
}

void Physics::addStaticEntity(Entity* e) {
	createBody(e);
	e->body->CreateFixture(&(e->polygonShape), 0.0f);
	cout << e->body->GetPosition().x << " " << e->body->GetPosition().y << endl;
	staticEntityList.push_back(e);
}

void Physics::addDynamicEntity(Entity* e) {
	createBody(e);
	e->body->CreateFixture(&(e->fixtureDef));
	dynamicEntityList.push_back(e);
}

void Physics::addBullet(BulletEntity * e, int player)
{	
	switch(player)
	{
	case 1:
		createBody(e);
		e->body->CreateFixture(&(e->fixtureDef));
		bulletList1.push_back(e);
		break;
	case 2:
		createBody(e);
		e->body->CreateFixture(&(e->fixtureDef));
		bulletList2.push_back(e);
		break;
	default:
		break;
	}
}

void Physics::setEventSystem(EventSystem* es) {
	this->es = es;
}

void Physics::getPlayer(Entity* player1, Entity* player2) {
	this->player1 = player1;
	addDynamicEntity(player1);
	this->player2 = player2;
	addDynamicEntity(player2);
}

void Physics::setGravity(b2Vec2 gravity) {
	this->gravity = gravity;
}

void Physics::createBody(Entity* e) {
	glm::vec2 pos = e->getPosition();
	e->body = world->CreateBody(&(e->bodyDef));
	e->body->SetUserData(e);
}

void Physics::setProfileSystem(Profile* pro) {
	this->pro = pro;
}