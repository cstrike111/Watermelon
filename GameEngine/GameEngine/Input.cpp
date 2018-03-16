#include "Input.h"

Input::Input(SDL_Event* e) {
	this->e = e;
}

Input::~Input(){
	e = nullptr;
}

void Input::handleEvent(EventSystem* es) {
	switch (e->key.keysym.sym) {
	//detect which key the user presses
	case SDLK_ESCAPE:
		es->queue->push_back(Event::QUIT);
		cout << "The program needs to be quited!" << endl;
		break;  
	case SDLK_RIGHT:
		es->queue->push_back(Event::RECTENGLE_MOVERIGHT);
	default:
		break;
	}
}