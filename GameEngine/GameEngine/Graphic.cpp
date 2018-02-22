#include "Graphic.h"

Graphic::Graphic(SDL_Window* w) {
	gWindow = w;
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
}

Graphic::~Graphic() {
	SDL_FreeSurface(gImage);
	gImage = nullptr;
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = nullptr;
	gWindow = nullptr;
}

bool Graphic::loadImage(string path) {
	return true;
}

bool Graphic::draw() {
	
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
}
