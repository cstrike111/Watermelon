#include "FileSystem.h"



FileSystem::FileSystem(AssetManager* am)
{
	this->am = am;
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

bool FileSystem::loadLevel1(vector<StaticSpriteEntity*>* list)
{
	//load from file
	ifstream map("asset/map/map.dat");
	if (map.is_open()) {
		//data type?
		//load the position
		std::string line;
		while(std::getline(map, line))
		{	
			char type;
			map >> type;
			if (type == 'p') {
				float posX;
				float posY;
				float width;
				float height;
				map >> posX;
				map >> posY;
				map >> width;
				map >> height;
				StaticSpriteEntity* obj = new StaticSpriteEntity();
				obj->setSprite(new sf::Sprite());
				obj->setPosition(glm::vec2(posX * UNIT_PIXEL, posY * UNIT_PIXEL));
				obj->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/wood.jpg", AssetManager::TEXTURE)));
				obj->getSprite()->setOrigin(width * UNIT_PIXEL / 2, height * UNIT_PIXEL / 2);
				obj->setTextureRect(0, 0, width * UNIT_PIXEL, height * UNIT_PIXEL);
				//obj->setWidth(width * UNIT_PIXEL);
				//obj->setHeight(height * UNIT_PIXEL);
				obj->bodyDef.position.Set(posX, -posY);
				obj->polygonShape.SetAsBox(width/2, height/2); 
				list->push_back(obj);
				cout << "load!" << endl;
			}
			else {
				cout << "Oops! Fail to load!" << endl;
				return false;
			}
		}
		//close the file
		map.close();
	}
	
	
	return true;
}

void FileSystem::setPlayer(Entity* player) {
	this->player = player;
}

void FileSystem::demoCircle(ShapeEntity* circle) {
	this->circle = circle;
}
