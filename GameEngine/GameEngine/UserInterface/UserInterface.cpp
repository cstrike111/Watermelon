#include "UserInterface.h"

UserInterface::UserInterface(sf::RenderWindow* window) {
	this->window = window;
	KEY_LEFT_RELEASE = true;
	KEY_RIGHT_RELEASE = true;
	KEY_UP_RELEASE = true;
	KEY_DOWN_RELEASE = true;
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
	//system key
	if (key == sf::Keyboard::Escape) {
		//exit the game
		es->addEvent(new Quit());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		es->addEvent(new ToggleShowFps());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
		es->addEvent(new ToggleShowInfo());
	}
	if (key == sf::Keyboard::F5) {
		//save
		es->addEvent(new Save());
	}
	if (key == sf::Keyboard::F6) {
		//load
		es->addEvent(new Load());
	}

	//player 2 control key
	if (sf::Keyboard::isKeyPressed(player1Up)) {
		//move the player
		if (KEY_UP_RELEASE) {
			es->addEvent(new Player1MoveUp());
			KEY_UP_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Down)) {
		//move the player
		if (KEY_DOWN_RELEASE) {
			es->addEvent(new Player1MoveDown());
			KEY_DOWN_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Up) && sf::Keyboard::isKeyPressed(player1Down)) {
		if (KEY_UP_DOWN_RELEASE) {
			KEY_UP_DOWN_RELEASE = false;
			es->addEvent(new Player1StopY());
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Left)) {
		//move the player
		if (KEY_LEFT_RELEASE) {
			es->addEvent(new Player1MoveLeft());
			KEY_LEFT_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Right)) {
		//move the player
		if (KEY_RIGHT_RELEASE) {
			es->addEvent(new PlayerMoveRight());
			KEY_RIGHT_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Left) && sf::Keyboard::isKeyPressed(player1Right)) {
		if (KEY_LEFT_RIGHT_RELEASE) {
			KEY_LEFT_RIGHT_RELEASE = false;
			es->addEvent(new Player1StopX());
		}
	}

	//player 1 control key
	if (sf::Keyboard::isKeyPressed(player1Up)) {
		//move the player
		if (KEY_UP_RELEASE) {
			es->addEvent(new Player1MoveUp());
			KEY_UP_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Down)) {
		//move the player
		if (KEY_DOWN_RELEASE) {
			es->addEvent(new Player1MoveDown());
			KEY_DOWN_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Up) && sf::Keyboard::isKeyPressed(player1Down)) {
		if (KEY_UP_DOWN_RELEASE) {
			KEY_UP_DOWN_RELEASE = false;
			es->addEvent(new Player1StopY());
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Left)) {
		//move the player
		if (KEY_LEFT_RELEASE) {
			es->addEvent(new Player1MoveLeft());
			KEY_LEFT_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Right)) {
		//move the player
		if (KEY_RIGHT_RELEASE) {
			es->addEvent(new PlayerMoveRight());
			KEY_RIGHT_RELEASE = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Left) && sf::Keyboard::isKeyPressed(player1Right)) {
		if (KEY_LEFT_RIGHT_RELEASE) {
			KEY_LEFT_RIGHT_RELEASE = false;
			es->addEvent(new Player1StopX());
		}
	}
	


}

//handle user's input and add events
void UserInterface::handleKeyRelease(sf::Keyboard::Key key) {
	if (key == player1Up) {
		//stop the player
		KEY_UP_RELEASE = true;
		KEY_UP_DOWN_RELEASE = true;
		es->addEvent(new Player1StopY());
		if (!KEY_DOWN_RELEASE) {
			es->addEvent(new Player1MoveDown());
		}
	}
	if (key == player1Down) {
		//stop the player
		KEY_DOWN_RELEASE = true;
		KEY_UP_DOWN_RELEASE = true;
		es->addEvent(new Player1StopY());
		if (!KEY_UP_RELEASE) {
			es->addEvent(new Player1MoveUp());
		}
		
	}
	if (key == player1Left) {
		KEY_LEFT_RELEASE = true;
		KEY_LEFT_RIGHT_RELEASE = true;
		//stop the player
		es->addEvent(new Player1StopX());
		if (!KEY_RIGHT_RELEASE) {
			es->addEvent(new PlayerMoveRight());
		}
		
	}
	if (key == player1Right) {
		KEY_RIGHT_RELEASE = true;
		KEY_LEFT_RIGHT_RELEASE = true;
		//stop the player
		es->addEvent(new Player1StopX());
		if (!KEY_LEFT_RELEASE) {
			es->addEvent(new Player1MoveLeft());

		}
		
	}
	
}

void UserInterface::setKey(int action, sf::Keyboard::Key key) {
	switch (action) {
	case action::PLAYER1_UP:
		player1Up = key;
		break;
	case action::PLAYER1_DOWN:
		player1Down = key;
		break;
	case action::PLAYER1_LEFT:
		player1Left = key;
		break;
	case action::PLAYER1_RIGHT:
		player1Right = key;
		break;
	}
}

void UserInterface::handleButtonPressed() {

	if (sf::Joystick::isButtonPressed(0, buttonR)) {
		cout << "Button R pressed!" << endl;
	}
	if (sf::Joystick::isButtonPressed(0, buttonX)) {
		cout << "Button X pressed!" << endl;
	}
	if (sf::Joystick::isButtonPressed(0, buttonZ)) {
		cout << "Button Z pressed!" << endl;
	}
	if (sf::Joystick::isButtonPressed(0, buttonY)) {
		cout << "Button Y pressed!" << endl;
	}
}

void UserInterface::handleButtonReleased(int button) {

	if (button == buttonR) {
		cout << "R released!" << endl;
	}
	if (button == buttonX) {
		cout << "X released!" << endl;
	}
	if (button == buttonZ) {
		cout << "Z released!" << endl;
	}
	if (button == buttonY) {
		cout << "Y released!" << endl;
	}
}

void UserInterface::setButton(int action, int button) {
	switch (action) {
	case action::PLAYER1_UP:
		buttonR = button;
		break;
	case action::PLAYER1_DOWN:
		buttonX = button;
		break;
	case action::PLAYER1_LEFT:
		buttonZ = button;
		break;
	case action::PLAYER1_RIGHT:
		buttonY = button;
		break;
	}
}

void UserInterface::handleAxisMove(int axis, float position) {
	cout << "The moving axis is: " << axis << " Position: " << position << endl;
}

void UserInterface::setEventSystem(EventSystem* es) {
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
			handleButtonPressed();
			break;
		case sf::Event::JoystickButtonReleased:
			handleButtonReleased(sfEvent.joystickButton.button);
			break;
		case sf::Event::JoystickMoved:
			handleAxisMove(sfEvent.joystickMove.axis, sfEvent.joystickMove.position);
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