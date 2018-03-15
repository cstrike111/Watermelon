#include "Input.h"

Input::Input(SDL_Event* e) {
	this->e = e;
}

Input::~Input(){
	e = nullptr;
}

int Input::getKey() {
	switch (e->key.keysym.sym) {
	//detect which key the user presses
	case SDLK_ESCAPE:
		return KEY_PRESS_ESCAPE;
		break;  
	default:
		return KEY_PRESS_DEFAULT;
		break;
	}
}