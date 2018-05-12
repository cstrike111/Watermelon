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
	pro->setPlayerRenderInfo(player->getPosition().x, player->getPosition().y);
	//get the physics information
	b2Vec2 vel = player->body->GetLinearVelocity();
	b2Vec2 pos = player->body->GetPosition();
	pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);

}

void Physics::handleEvent(int eventType) {
	b2Vec2 vel = player->body->GetLinearVelocity();
	b2Vec2 pos = player->body->GetPosition();
	switch (eventType) {
	case Event::PLAYER_MOVE_UP:
		//player->body->ApplyLinearImpulse(b2Vec2(0, 5000), player->body->GetWorldCenter(), true);
		vel.y = PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_MOVE_DOWN:
		//player->body->ApplyLinearImpulse(b2Vec2(0, -5000), player->body->GetWorldCenter(), true);
		vel.y = -PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_MOVE_LEFT:
		//player->body->ApplyLinearImpulse(b2Vec2(-5000 , 0), player->body->GetWorldCenter(), true);
		vel.x = -PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_MOVE_RIGHT:
		//player->body->ApplyLinearImpulse(b2Vec2(5000, 0), player->body->GetWorldCenter(), true);
		vel.x = PLAYER_MOVE_SPEED;
		player->body->SetLinearVelocity(vel);
		break;
	case Event::PLAYER_STOP_Y:
		vel.y = 0;
		player->body->SetLinearVelocity(vel);
		//player->body->ApplyLinearImpulse(b2Vec2(0, 0), player->body->GetWorldCenter(), true);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);
		break;
	case Event::PLAYER_STOP_X:
		vel.x = 0;
		//player->body->ApplyLinearImpulse(b2Vec2(0, 0), player->body->GetWorldCenter(), true);
		player->body->SetLinearVelocity(vel);
		//pass the physics info
		pro->setPlayerPhysicsInfo(pos.x, pos.y, vel.x, vel.y);
		break;
	case Event::SAVE:
		player->setPosition(glm::vec2(pos.x * UNIT_PIXEL, pos.y * UNIT_PIXEL));
		player->setVelocity(glm::vec2(vel.x, vel.y));
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
	this->player = player;
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