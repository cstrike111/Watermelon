#include "Graphic.h"

Graphic::Graphic(SDL_Window* w) {
	gWindow = w;
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	a = 160;
	b = 40;
}

Graphic::~Graphic() {
	gWindow = nullptr;
}

bool Graphic::loadImage(string path) {
	return true;
}

bool Graphic::draw() {
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderClear(gRenderer);
	/*SDL_Rect fillRect = { 640 / 4, 480 / 4, 640 / 2, 480 / 2 };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);*/
	SDL_Rect outlineRect = { 640 / 6, 480 / 6, 640 * 2 / 3, 480 * 2 / 3 };
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &outlineRect);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i < 480; i += 4)
	{
		SDL_RenderDrawPoint(gRenderer, 640 / 2, i);
	}
	SDL_Rect mr = { a, b, 40, 40 };
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0xFF);
	SDL_RenderDrawRect(gRenderer, &mr);
	SDL_RenderPresent(gRenderer);
	SDL_UpdateWindowSurface(gWindow);
	return true;
}

void Graphic::handleEvent(EventSystem* e) {
	//replace here with switch
	if (e->eventQueue->size() != 0) {
		if (e->eventQueue->front().eventType == Event::RECTENGLE_MOVERIGHT) {
			//should move this part to physics subsystem
			a += 0.01;
			e->eventQueue->pop();
			return;
		}
		//delete this
		if (e->eventQueue->front().eventType == Event::DRAW) {
			e->eventQueue->pop();
			return;
		}
		if (e->eventQueue->front().eventType == Event::RECTENGLE_MOVELEFT) {
			a -= 0.01;
			e->eventQueue->pop();
			return;
		}
		if (e->eventQueue->front().eventType == Event::RECTENGLE_MOVEUP) {
			b -= 0.01;
			e->eventQueue->pop();
			return;
		}
		if (e->eventQueue->front().eventType == Event::RECTENGLE_MOVEDOWN) {
			b += 0.01;
			e->eventQueue->pop();
			return;
		}
	}	
	//draw at once?
}

