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
	world->Step(pro->getDtTime(), 6, 2);
	for (int i = 0; i < dynamicEntityList.size(); i++) {
		Entity* e = dynamicEntityList.at(i);
		b2Vec2 position = e->body->GetPosition();
		//covert into pixel
		float posX = position.x * UNIT_PIXEL;
		//be careful: sfml doesn't share THE SAME COORDINATE SYSTEM with box2d
		float posY = position.y * -UNIT_PIXEL; 
		e->setPosition(glm::vec2(posX, posY));
	}
	//detect collision
	//gravity
	//if player is not landing on the ground, apply gravity 

}

void Physics::handleEvent(int eventType) {
	b2Vec2 vel = player->body->GetLinearVelocity();
	switch (eventType) {
	case Event::PLAYER_MOVE_UP:
		//if the entity is on the floor
		//add y speed
		//jumpReady = false
		//when the entity land on floor, rest jumpReady
		vel.y = PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_MOVE_DOWN:
		vel.y = -PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_MOVE_LEFT:
		vel.x = -PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_MOVE_RIGHT:
		vel.x = PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_STOP_Y:
		vel.y = 0;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_STOP_X:
		vel.x = 0;
		player->body->SetLinearVelocity(vel);
		break;
	default:
		break;
	}
}

void Physics::addStaticEntity(Entity* e) {
	createBody(e);
	e->body->CreateFixture(&(e->polygonShape), 0.0f);
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
	this->player = player;
	addDynamicEntity(player);
}

void Physics::setGravity(b2Vec2 gravity) {
	this->gravity = gravity;
}

void Physics::createBody(Entity* e) {
	e->body = world->CreateBody(&(e->bodyDef));
}

void Physics::setProfileSystem(Profile* pro) {
	this->pro = pro;
}