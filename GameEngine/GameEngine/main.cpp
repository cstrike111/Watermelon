#include <iostream>
#include "Graphic.h"
#include "UserInterface.h"
#include "Audio.h"

//configuration of the parameters
//resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//declare of sub-system and window
Graphic* g; //renderer
UserInterface* ui; //user interface sub-system
EventSystem* es; //event system
Audio* a; //audio system
sf::RenderWindow* window;


bool init() {
	//initializing flag
	bool success = true;

	//create window
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "A SUPER FUN GAME!");
	if (window->isOpen()) {
		success = true;
		//pass the window to sub-systems
		g = new Graphic(window);
		ui = new UserInterface(window);
		es = new EventSystem(window);
		a = new Audio();
		//pass the event system to sub-systems
		g->getEventSystem(es);
		ui->getEventSystem(es);
		a->getEventSystem(es);
		//load assets
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

}

//game loop
void gameLoop() {
	es->update();
	g->draw();
	ui->update();
	a->update();
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