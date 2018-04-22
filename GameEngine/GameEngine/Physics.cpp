#include "Physics.h"

Physics::Physics() {

}

Physics::~Physics() {

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
	//position change?
	for (int i = 0; i < entityList.size(); i++) {
		Entity* e = entityList.at(i);
		glm::vec2 newPos = e->getPosition();
		newPos.x += e->getVelocity().x;
		newPos.y += e->getVelocity().y;
		e->setPosition(newPos);
	}
	//detect collision
	//gravity
	//if player is not landing on the ground, apply gravity 

}

void Physics::handleEvent(int eventType) {
	switch (eventType) {
	case Event::PLAYER_MOVE_UP:
		//if the entity is on the floor
		//add y speed
		//jumpReady = false
		//when the entity land on floor, rest jumpReady
		player->setVelocity(glm::vec2(player->getVelocity().x, -5));
		break;
	case Event::PLAYER_MOVE_DOWN:
		player->setVelocity(glm::vec2(player->getVelocity().x, 5));
		break;
	case Event::PLAYER_MOVE_LEFT:
		player->setVelocity(glm::vec2(-5, player->getVelocity().y));
		break;
	case Event::PLAYER_MOVE_RIGHT:
		player->setVelocity(glm::vec2(5, player->getVelocity().y));
		break;
	case Event::PLAYER_STOP_Y:
		player->setVelocity(glm::vec2(player->getVelocity().x, 0));
		break;
	case Event::PLAYER_STOP_X:
		player->setVelocity(glm::vec2(0, player->getVelocity().y));
		break;
	default:
		break;
	}
}

void Physics::addEntity(Entity* e) {
	entityList.push_back(e);
}

void Physics::setEventSystem(EventSystem* es) {
	this->es = es;
}

void Physics::getPlayer(Entity* player) {
	this->player = player;
	addEntity(player);
}


