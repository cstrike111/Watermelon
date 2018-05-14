#include "FileSystem.h"



FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

void FileSystem::handleEvent(int eventType) {
	switch (eventType) {
	case Event::SAVE:
		save();
		break;
	case Event::LOAD:
		load();
		break;
	default:
		break;
	}
}

void FileSystem::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::FILE)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popFile();
		}
	}

	
}

void FileSystem::setEventSystem(EventSystem* es) {
	this->es = es;
}

bool FileSystem::save() {
	ofstream saveFile ("save/save.dat");
	if (saveFile.is_open()) {
		//get the information of the player
		saveFile << "p" << " "; //"p" indicates the information is for the player
		saveFile << player->getPosition().x << " ";
		saveFile << player->getPosition().y << " ";
		saveFile << player->getVelocity().x << " ";
		saveFile << player->getVelocity().y << " ";
		cout << "save!" << endl;
		saveFile.close();
		return true;
	}
	else {
		cout << "Oops! Fail to save!" << endl;
		return false;
	}
	
}

bool FileSystem::load() {
	ifstream saveFile("save/save.dat");
	if (saveFile.is_open()) {
		//load the information of the player
		char type;
		saveFile >> type;
		if (type == 'p') {
			float posX;
			float posY;
			saveFile >> posX;
			saveFile >> posY;
			circle->setPosition(glm::vec2(posX, posY));
			cout << "load!" <<endl;
			saveFile.close();
			return true;
		}
	}
	else {
		cout << "Oops! Fail to load!" << endl;
		return false;
	}
}

bool FileSystem::loadLevel()
{
	return false;
}

void FileSystem::setPlayer(Entity* player) {
	this->player = player;
}

void FileSystem::demoCircle(ShapeEntity* circle) {
	this->circle = circle;
}
