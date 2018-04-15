#include "UserInterface.h"

UserInterface::UserInterface(sf::RenderWindow* window) {
	this->window = window;
}

UserInterface::~UserInterface(){

}

void UserInterface::handleEvent(int eventType) {
	switch (eventType) {
	case Event::KEYPRESS:
		handleKey(es->getKeycode());
		break;
	
	case Event::QUIT:
		window->close();
		break;

	case Event::CONTROLLER_CONNECTED:
		std::cout << "joystick connected: " << es->getControllerId() << std::endl;
		break;
	
	case Event::CONTROLLER_DISCONNECTED:
		std::cout << "joystick disconnected: " << es->getControllerId() << std::endl;
		break;
	
	case Event::BUTTON_PRESS:
		handleButton(es->getButton());

	default:
		break;
	}
	
		
}

//handle user's input and add events
void UserInterface::handleKey(int key) {
	//might need to use some features of sfml
	if (key == sf::Keyboard::Escape) {
		//exit the game
		es->addEvent(new Quit());
	}
	if (sf::Keyboard::isKeyPressed(playerUp)) {
		//move the player
		es->addEvent(new PlayerMoveUp());
	}
	if (sf::Keyboard::isKeyPressed(playerDown)) {
		//move the player
		es->addEvent(new PlayerMoveDown());
	}
	if (sf::Keyboard::isKeyPressed(playerLeft)) {
		//move the player
		es->addEvent(new PlayerMoveLeft());
	}
	if (sf::Keyboard::isKeyPressed(playerRight)) {
		//move the player
		es->addEvent(new PlayerMoveRight());
	}
}

void UserInterface::setKey(int action, sf::Keyboard::Key key) {
	switch (action) {
	case action::PLAYER_UP:
		playerUp = key;
		break;
	case action::PLAYER_DOWN:
		playerDown = key;
		break;
	case action::PLAYER_LEFT:
		playerLeft = key;
		break;
	case action::PLAYER_RIGHT:
		playerRight = key;
		break;
	}
}

void UserInterface::handleButton(int button) {

	if (sf::Joystick::isButtonPressed(0, playerUpC)) {
		//move the player
		es->addEvent(new PlayerMoveUp());
	}
	if (sf::Joystick::isButtonPressed(0, playerDownC)) {
		//move the player
		es->addEvent(new PlayerMoveDown());
	}
	if (sf::Joystick::isButtonPressed(0, playerLeftC)) {
		//move the player
		es->addEvent(new PlayerMoveLeft());
	}
	if (sf::Joystick::isButtonPressed(0, playerRightC)) {
		//move the player
		es->addEvent(new PlayerMoveRight());
	}
}

void UserInterface::setButton(int action, int button) {
	switch (action) {
	case action::PLAYER_UP:
		playerUpC = button;
		break;
	case action::PLAYER_DOWN:
		playerDownC = button;
		break;
	case action::PLAYER_LEFT:
		playerLeftC = button;
		break;
	case action::PLAYER_RIGHT:
		playerRightC = button;
		break;
	}
}

void UserInterface::getEventSystem(EventSystem* es) {
	this->es = es;
}

void UserInterface::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::UI)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popUI();
		}
	}
}