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

void Input::handleKey(EventSystem* es) {
	switch (es->getSDLEvent()->key.keysym.sym) {
	//detect which key the user presses
	case SDLK_ESCAPE:
		es->eventQueue->push(Event::QUIT);
		cout << "The program needs to be quited!" << endl;
		break;  
	case SDLK_RIGHT:
		es->eventQueue->push(Event::RECTENGLE_MOVERIGHT);
	default:
		break;
	}
}

