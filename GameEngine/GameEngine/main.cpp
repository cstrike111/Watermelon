#include <iostream>
#include "Graphic.h"
#include "UserInterface.h"
#include "Audio.h"
#include "Physics.h"
#include "ShapeEntity.h"

//configuration of the parameters
//resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//declare of sub-system and window
Graphic* g; //renderer
UserInterface* ui; //user interface sub-system
EventSystem* es; //event system
Audio* a; //audio system
Physics* p; //physics system
sf::RenderWindow* window;

//pointer of asset
ShapeEntity* player;

bool init() {
	//initializing flag
	bool success = true;

	//create window
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "A SUPER FUN GAME!");
	if (window->isOpen()) {
		success = true;
		window->setFramerateLimit(60); //limit the fps
		//pass the window to sub-systems
		a = new Audio();
		g = new Graphic(window);
		ui = new UserInterface(window);
		es = new EventSystem(window);
		p = new Physics();
		//pass the event system to sub-systems
		g->setEventSystem(es);
		ui->setEventSystem(es);
		a->setEventSystem(es);
		p->setEventSystem(es);
		//set up assets
		player = new ShapeEntity();
		player->setShape(new sf::CircleShape(50));
		player->getShape()->setFillColor(sf::Color::Green);
		g->addEntity(player, Entity::rType::SHAPE);
		p->getPlayer(player);
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