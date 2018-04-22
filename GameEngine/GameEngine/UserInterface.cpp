#include "UserInterface.h"

UserInterface::UserInterface(sf::RenderWindow* window) {
	this->window = window;
}

UserInterface::~UserInterface(){

}

void UserInterface::handleEvent(int eventType) {
	switch (eventType) {
	case Event::QUIT:
		window->close();
		break;
	default:
		break;
	}
	
		
}

//handle user's input and add events
void UserInterface::handleKeyPress(sf::Keyboard::Key key) {
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

//handle user's input and add events
void UserInterface::handleKeyRelease(sf::Keyboard::Key key) {
	if (key == playerUp) {
		//stop the player
		cout << "Up key release" << endl;
	}
	if (key == playerDown) {
		//stop the player
		cout << "Down key release" << endl;
	}
	if (key == playerLeft) {
		//stop the player
		cout << "Left key release" << endl;
	}
	if (key == playerRight) {
		//stop the player
		cout << "Right key release" << endl;
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
	//handle sfml event 
	while (window->pollEvent(sfEvent))
	{
		switch (sfEvent.type) {
			//if the user wants to close the window, close it
		case sf::Event::Closed:
			es->addEvent(new Quit());
			break;
			//if the user press something
		case sf::Event::KeyPressed:
			handleKeyPress(sfEvent.key.code);
			break;
			//if player release the key
		case sf::Event::KeyReleased:
			handleKeyRelease(sfEvent.key.code);
			break;
			//if the controller is connected
		case sf::Event::JoystickConnected:
			cout << "Controller Connected" << endl;
			es->addEvent(new ControllerConnected);
			break;
			//if the controller is connected
		case sf::Event::JoystickDisconnected:
			cout << "Controller Disconnected" << endl;
			es->addEvent(new ControllerDisconnected);
			break;
			//if the controller button is pressed
		case sf::Event::JoystickButtonPressed:
			handleButton(sfEvent.JoystickButtonPressed);
			break;
			//by default, do nothing
		default:
			break;
		}

	}
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