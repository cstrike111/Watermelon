#include "Physics.h"

Physics::Physics(b2Vec2 gravity) {
	world = new b2World(gravity);
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
	//get the render infomation of player
	pro->setPlayerRenderInfo(player1->getPosition().x, player1->getPosition().y);
	//get the physics information
	b2Vec2 vel = player1->body->GetLinearVelocity();
	b2Vec2 pos = player1->body->GetPosition();
	pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);

}

void Physics::handleEvent(int eventType) {
	b2Vec2 vel = player1->body->GetLinearVelocity();
	b2Vec2 pos = player1->body->GetPosition();
	float desiredVel = 0;
	float velChange = 0;
	float impulse = 0;
	switch (eventType) {
	case Event::PLAYER1_MOVE_UP:
		desiredVel = PLAYER_MOVE_SPEED;
		velChange = desiredVel - vel.y;
		impulse = player1->body->GetMass() * velChange;
		player1->body->ApplyLinearImpulse(b2Vec2(0, impulse), player1->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER1_MOVE_DOWN:
		desiredVel = -PLAYER_MOVE_SPEED;
		velChange = desiredVel - vel.y;
		impulse = player1->body->GetMass() * velChange;
		player1->body->ApplyLinearImpulse(b2Vec2(0, impulse), player1->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER1_MOVE_LEFT:
		desiredVel = -PLAYER_MOVE_SPEED;
		velChange = desiredVel - vel.x;
		impulse = player1->body->GetMass() * velChange;
		player1->body->ApplyLinearImpulse(b2Vec2(impulse, 0), player1->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER1_MOVE_RIGHT:
		desiredVel = PLAYER_MOVE_SPEED;
		velChange = desiredVel - vel.x;
		impulse = player1->body->GetMass() * velChange;
		player1->body->ApplyLinearImpulse(b2Vec2(impulse, 0), player1->body->GetWorldCenter(), true);
		break;
	case Event::PLAYER1_STOP_Y:
		desiredVel = 0;
		velChange = desiredVel - vel.y;
		impulse = player1->body->GetMass() * velChange;
		player1->body->ApplyLinearImpulse(b2Vec2(0, impulse), player1->body->GetWorldCenter(), true);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);
		break;
	case Event::PLAYER1_STOP_X:
		desiredVel = 0;
		velChange = desiredVel - vel.x;
		impulse = player1->body->GetMass() * velChange;
		player1->body->ApplyLinearImpulse(b2Vec2(impulse, 0), player1->body->GetWorldCenter(), true);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);
		break;
	case Event::SAVE:
		player1->setPosition(glm::vec2(pos.x * UNIT_PIXEL, pos.y * UNIT_PIXEL));
		player1->setVelocity(glm::vec2(vel.x, vel.y));
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

void Physics::setEventSystem(EventSystem* es) {
	this->es = es;
}

void Physics::getPlayer(Entity* player) {
	this->player1 = player;
	addDynamicEntity(player);
}

void Physics::setGravity(b2Vec2 gravity) {
	this->gravity = gravity;
}

void Physics::createBody(Entity* e) {
	glm::vec2 pos = e->getPosition();
	e->body = world->CreateBody(&(e->bodyDef));
}

void Physics::setProfileSystem(Profile* pro) {
	this->pro = pro;
}