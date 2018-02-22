#include "Graphic.h"

Graphic::Graphic(SDL_Window* w) {
	gWindow = w;
}

Graphic::~Graphic() {
	SDL_FreeSurface(gImage);
	gImage = nullptr;
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = nullptr;
	gWindow = nullptr;
}

bool Graphic::loadImage(string path) {

	//load image
	gImage = SDL_LoadBMP("hello_world.bmp");
	if (gImage == NULL) {
		cout << "Unable to load image " << "hello_world.bmp" << "SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	return true;
}

bool Graphic::draw() {
	
	SDL_BlitSurface(gImage, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindow);
	return true;
}
