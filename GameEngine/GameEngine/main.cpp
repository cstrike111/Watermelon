#include <iostream>
#include "Graphic.h"
#include "UserInterface.h"
#include "Audio.h"
#include "Physics.h"
#include "ShapeEntity.h"
#include "AssetManager.h"
#include "Profile.h"
#include "FileSystem.h"
#include "StaticSpriteEntity.h"
#include "CharacterEntity.h"

//configuration of the parameters
//resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//world parameters
b2Vec2 gravity(0.0f, 0.0f);

//declare of sub-system and window
Graphic* g; //renderer
UserInterface* ui; //user interface sub-system
EventSystem* es; //event system
Audio* a; //audio system
Physics* p; //physics system
AssetManager* asset; //Asset Manager
Profile* pro; //Profile system
FileSystem* file; //file system
sf::RenderWindow* window;

//pointer of entity
CharacterEntity* player;
StaticSpriteEntity* platform;
ShapeEntity* circle;

bool init() {
	//initializing flag
	bool success = true;

	//create window
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "A SUPER FUN GAME!");
	if (window->isOpen()) {
		success = true;
		window->setFramerateLimit(60); //limit the fps
		//pass the window to sub-systems and create sub-systems
		//be careful with the order
		es = new EventSystem(window);
		asset = new AssetManager();
		g = new Graphic(window, asset);
		ui = new UserInterface(window);
		p = new Physics(gravity);
		a = new Audio(asset);
		pro = new Profile();
		file = new FileSystem();

		//pass the profile system to sub-systems
		g->setProfileSystem(pro);
		p->setProfileSystem(pro);

		//pass the event system to sub-systems
		g->setEventSystem(es);
		ui->setEventSystem(es);
		a->setEventSystem(es);
		p->setEventSystem(es);
		a->setEventSystem(es);
		asset->setEventSystem(es);
		pro->setEventSystem(es);
		file->setEventSystem(es);

		//set up assets and entity
		//player
		player = new CharacterEntity();
		player->setSprite(new sf::Sprite());
		player->setTexture(static_cast<sf::Texture*> (asset->loadAsset("asset/texture/player.png", AssetManager::TEXTURE)));
		player->setTextureRect(0, 0, 106, 233);
		player->setWidth(106);
		player->setHeight(233);
		player->updatePhysics();
		player->polygonShape.SetAsBox(1.0f, 1.0f);
		player->bodyDef.position.Set(0, 4.0f);
		//configurate box2d

		//platform
		platform = new StaticSpriteEntity();
		platform->setSprite(new sf::Sprite());
		platform->setPosition(glm::vec2(200, 300));
		platform->setTexture(static_cast<sf::Texture*> (asset->loadAsset("asset/texture/wood.jpg", AssetManager::TEXTURE)));
		platform->setTextureRect(0, 0, 200, 50);
		platform->setWidth(200);
		platform->setHeight(100);
		platform->updatePhysics();
		platform->bodyDef.position.Set(0.0f, -5.0f);
		platform->polygonShape.SetAsBox(100.f, 10.0f);

		//demo circle
		circle = new ShapeEntity();
		circle->setShape(new sf::CircleShape(50));
		circle->getShape()->setFillColor(sf::Color::Green);
		file->demoCircle(circle);

		//add entity to graphic system and physics system
		file->setPlayer(player); //tract player's information
		g->addEntity(player, Entity::rType::CHARACTER);
		g->addEntity(circle, Entity::rType::SHAPE);
		g->addEntity(platform, Entity::rType::SPRITE);
		p->getPlayer(player);
		p->addStaticEntity(platform);
	
	}
	else {
		success = false;
	}
	return success;
}

void close() {
	//clean the memory
	//window
	delete window;
	window = nullptr;

	//clean the graphic subsystem
	delete g;
	g = nullptr;

	//clean the input subsystem
	delete ui;
	ui = nullptr;

	//clean the event system
	delete es;
	es = nullptr;

	//clean the physics system
	delete p;
	p = nullptr;

	//clean asset manager system
	delete asset;
	asset = nullptr;

	//clean audio system
	delete a;
	a = nullptr;

	//clean profile system
	delete pro;
	pro = nullptr;

	//clean file system
	delete file;
	file = nullptr;

	delete player;
	player = nullptr;

}

//game loop
void gameLoop() {
	es->update();
	g->update();
	ui->update();
	a->update();
	p->update();
	asset->update();
	pro->update();
	file->update();
}

int main()
{		
	//start
	if (!init()) {
		cout << "Oops! Something wrong happened!\n";
	}
	else {
		//game loop
		while (window->isOpen()) {
			gameLoop();
		}
	}
	//close
	close();

	return 0;
}