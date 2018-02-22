#pragma once
#include "SDL2-2.0.7\include\SDL.h"
#include <string>
#include <iostream>

using namespace std;

class Graphic {
public:
	Graphic(SDL_Window* w);
	~Graphic();
	bool loadImage(string path);
	SDL_Surface* gScreenSurface;
	SDL_Surface* gImage;
	bool draw();

private:
	SDL_Window* gWindow;
	
	bool load; // whether the image is loaded
};