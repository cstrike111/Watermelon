#include <iostream>
#include "Graphic/Graphic.h"
#include "UserInterface/UserInterface.h"
#include "Audio/Audio.h"
#include "Physics/Physics.h"
#include "Entity/ShapeEntity.h"
#include "AssetManager/AssetManager.h"
#include "Profile/Profile.h"
#include "FileSystem/FileSystem.h"
#include "Entity/StaticSpriteEntity.h"
#include "Entity/CharacterEntity.h"
#include "Graphic/Animation.h"
#include "Game.h"

//configuration of the parameters
//resolution
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

//world parameters
b2Vec2 gravity(0.0f, -100.0f);

//declare of sub-system and window
Graphic* g; //renderer
UserInterface* ui; //user interface sub-system
EventSystem* es; //event system
Audio* a; //audio system
Physics* p; //physics system
AssetManager* asset; //Asset Manager
Profile* pro; //Profile system
FileSystem* file; //file system
Game* game; //game object
sf::RenderWindow* window; //render window

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
		file = new FileSystem(asset);

		//pass the profile system to sub-systems
		g->setProfileSystem(pro);
		p->setProfileSystem(pro);

		//pass the event system to sub-systems
		g->setEventSystem(es);
		ui->setEventSystem(es);
		a->setEventSystem(es);
		p->setEventSystem(es);
		asset->setEventSystem(es);
		pro->setEventSystem(es);
		file->setEventSystem(es);

		//initialize the game
		game = new Game(p, g, es, asset, file);
		game->loadLevel1();
	
	}
	else {
		success = false;
	}
	return success;
}

void close() {
	//clean the memory
	//window
	window->close();
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

	//clean game object
	delete game;
	game = nullptr;
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
	game->update();
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