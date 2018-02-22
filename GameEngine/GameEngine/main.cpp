#include <iostream>
#include "SDL2-2.0.7\include\SDL.h"
#include "Graphic.h"

using namespace std;

SDL_Window* gWindow = NULL;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
Graphic* g;
bool quit = false;

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
	gWindow = NULL;

	// quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[]) {
	// start up SDL and create window
	if (!init()) {
		cout << "Failed to initialize!\n";
	}
	else {
		while (!quit) {
			g->draw();
			}
			
		
	}

	//free resources and close SDL
	close();

	return 0;
}
