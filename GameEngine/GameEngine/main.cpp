#include <iostream>
#include "SDL2-2.0.7\include\SDL.h"
#include "Graphic.h"
#include "Input.h"

using namespace std;

SDL_Window* gWindow = NULL;
//define resolution
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480;
Graphic* g; //renderer
bool quit = false; //flag for quit
SDL_Event* e = new SDL_Event(); //sdl event
Input* input = new Input(e); //input sub-system

bool init() {
	//Initialization flag
	bool success = true;

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError();
		success = false;
	}
	else {
		// create window
		gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError();
			success = false;
		}
		else
		{
			//create renderer
			g = new Graphic(gWindow);
		}
	}


	return success;
}

void close() {

	// destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	//clean the graphic subsystem
	delete g;
	g = nullptr;

	//clean the input subsystem
	delete input;
	input = nullptr;

	//clean the memory
	delete e;
	e = nullptr;

	// quit SDL subsystems
	SDL_Quit();
}

//game loop
void gameLoop() {
	//create event queue
	//game logic should be able to create event?
	//every sub-system handle the events(graphic, input)
	//last sub-system delete the event
	//handle the event
	while (SDL_PollEvent(e) != 0) {
		//if the user wants to quit
		if (e->type == SDL_QUIT) {
			quit = true;
		}

		//if user press space, quit
		if (e->type == SDL_KEYDOWN) {
			if (input->getKey() == KEY_PRESS_ESCAPE) {
				quit = true;
			}
			cout << input->getKey();

		}
	}
	//draw things
	g->draw();
}

int main(int argc, char* args[]) {
	// start up SDL and create window
	if (!init()) {
		cout << "Failed to initialize!\n";
	}
	else {
		//handle the game loop
		
		while (!quit) {
			gameLoop();
		}	
	}

	//free resources and close SDL
	close();

	return 0;
}


