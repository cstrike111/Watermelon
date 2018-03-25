#include "Input.h"

Input::Input() {
	
}

Input::~Input(){

}

void Input::handleEvent(EventSystem* es) {
	if (es->eventQueue->size() != 0) {
		if (es->eventQueue->front().eventType == Event::KEY_PRESS) {
			handleKey(es);
			es->eventQueue->pop();
		}
	}
}

//handle user's input and add events
void Input::handleKey(EventSystem* es) {
	switch (es->getSDLEvent()->key.keysym.sym) {
	//detect which key the user presses
	case SDLK_ESCAPE:
		es->eventQueue->push(Event::QUIT);
		cout << "The program needs to be quited!" << endl;
		break;  
	case SDLK_RIGHT:
		es->eventQueue->push(Event::RECTENGLE_MOVERIGHT);
		break;
	case SDLK_LEFT:
		es->eventQueue->push(Event::RECTENGLE_MOVELEFT);
		break;
	case SDLK_UP:
		es->eventQueue->push(Event::RECTENGLE_MOVEUP);
		break;
	case SDLK_DOWN:
		es->eventQueue->push(Event::RECTENGLE_MOVEDOWN);
		break;
	default:
		break;
	}
}

