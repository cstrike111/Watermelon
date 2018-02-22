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
	bool draw();
	int a;

private:
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	bool load; // whether the image is loaded
};