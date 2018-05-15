#include "UserInterface.h"

UserInterface::UserInterface(sf::RenderWindow* window) {
	this->window = window;
	KEY_LEFT_RELEASE_1 = true;
	KEY_RIGHT_RELEASE_1 = true;
	KEY_UP_RELEASE_1 = true;
	KEY_DOWN_RELEASE_1 = true;
	KEY_LEFT_RELEASE_2 = true;
	KEY_RIGHT_RELEASE_2 = true;
	KEY_UP_RELEASE_2 = true;
	KEY_DOWN_RELEASE_2 = true;
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
void UserInterface::handleKeyPress1(sf::Keyboard::Key key) {
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

	//player 1 control key
	if (sf::Keyboard::isKeyPressed(player1Up)) {
		//move the player
		if (KEY_UP_RELEASE_1) {
			es->addEvent(new Player1MoveUp());
			KEY_UP_RELEASE_1 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Down)) {
		//move the player
		if (KEY_DOWN_RELEASE_1) {
			es->addEvent(new Player1MoveDown());
			KEY_DOWN_RELEASE_1 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Up) && sf::Keyboard::isKeyPressed(player1Down)) {
		if (KEY_UP_DOWN_RELEASE_1) {
			KEY_UP_DOWN_RELEASE_1 = false;
			es->addEvent(new Player1StopY());
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Left)) {
		//move the player
		if (KEY_LEFT_RELEASE_1) {
			es->addEvent(new Player1MoveLeft());
			KEY_LEFT_RELEASE_1 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Right)) {
		//move the player
		if (KEY_RIGHT_RELEASE_1) {
			es->addEvent(new Player1MoveRight());
			KEY_RIGHT_RELEASE_1 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player1Left) && sf::Keyboard::isKeyPressed(player1Right)) {
		if (KEY_LEFT_RIGHT_RELEASE_1) {
			KEY_LEFT_RIGHT_RELEASE_1 = false;
			es->addEvent(new Player1StopX());
		}
	}
	//player 1 fire
	if (sf::Keyboard::isKeyPressed(player1Fire)) {
		if (KEY_FIRE_RELEASE_1) {
			KEY_FIRE_RELEASE_1 = false;
			es->addEvent(new Player1Fire());
		}
	}

}

//handle user's input and add events
void UserInterface::handleKeyRelease1(sf::Keyboard::Key key) {
	//player 1
	if (key == player1Up) {
		//stop the player
		KEY_UP_RELEASE_1 = true;
		KEY_UP_DOWN_RELEASE_1 = true;
		es->addEvent(new Player1StopY());
		if (!KEY_DOWN_RELEASE_1) {
			es->addEvent(new Player1MoveDown());
		}
	}
	if (key == player1Down) {
		//stop the player
		KEY_DOWN_RELEASE_1 = true;
		KEY_UP_DOWN_RELEASE_1 = true;
		es->addEvent(new Player1StopY());
		if (!KEY_UP_RELEASE_1) {
			es->addEvent(new Player1MoveUp());
		}
		
	}
	if (key == player1Left) {
		KEY_LEFT_RELEASE_1 = true;
		KEY_LEFT_RIGHT_RELEASE_1 = true;
		//stop the player
		es->addEvent(new Player1StopX());
		if (!KEY_RIGHT_RELEASE_1) {
			es->addEvent(new Player1MoveRight());
		}
		
	}
	if (key == player1Right) {
		KEY_RIGHT_RELEASE_1 = true;
		KEY_LEFT_RIGHT_RELEASE_1 = true;
		//stop the player
		es->addEvent(new Player1StopX());
		if (!KEY_LEFT_RELEASE_1) {
			es->addEvent(new Player1MoveLeft());

		}
		
	}
	if (key == player1Fire) {
		//reset the flag
		KEY_FIRE_RELEASE_1 = true;
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
	case action::PLAYER2_UP:
		player2Up = key;
		break;
	case action::PLAYER2_DOWN:
		player2Down = key;
		break;
	case action::PLAYER2_LEFT:
		player2Left = key;
		break;
	case action::PLAYER2_RIGHT:
		player2Right = key;
		break;
	}

}

void UserInterface::handleButtonPressed1() {

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

void UserInterface::handleButtonReleased1(int button) {

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

void UserInterface::handleKeyPress2(sf::Keyboard::Key key)
{
	//player 2 control key
	if (sf::Keyboard::isKeyPressed(player2Up)) {
		//move the player
		if (KEY_UP_RELEASE_2) {
			es->addEvent(new Player2MoveUp());
			KEY_UP_RELEASE_2 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player2Down)) {
		//move the player
		if (KEY_DOWN_RELEASE_2) {
			es->addEvent(new Player2MoveDown());
			KEY_DOWN_RELEASE_2 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player2Up) && sf::Keyboard::isKeyPressed(player2Down)) {
		if (KEY_UP_DOWN_RELEASE_2) {
			KEY_UP_DOWN_RELEASE_2 = false;
			es->addEvent(new Player2StopY());
		}
	}
	if (sf::Keyboard::isKeyPressed(player2Left)) {
		//move the player
		if (KEY_LEFT_RELEASE_2) {
			es->addEvent(new Player2MoveLeft());
			KEY_LEFT_RELEASE_2 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player2Right)) {
		//move the player
		if (KEY_RIGHT_RELEASE_2) {
			es->addEvent(new Player2MoveRight());
			KEY_RIGHT_RELEASE_2 = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(player2Left) && sf::Keyboard::isKeyPressed(player2Right)) {
		if (KEY_LEFT_RIGHT_RELEASE_2) {
			KEY_LEFT_RIGHT_RELEASE_2 = false;
			es->addEvent(new Player2StopX());
		}
	}
	//player 2 fire
	if (sf::Keyboard::isKeyPressed(player2Fire)) {
		if (KEY_FIRE_RELEASE_2) {
			KEY_FIRE_RELEASE_2 = false;
			es->addEvent(new Player2Fire());
		}
	}
}

void UserInterface::handleKeyRelease2(sf::Keyboard::Key key)
{
	//player 2 control key
	if (key == player2Up) {
		//stop the player
		KEY_UP_RELEASE_2 = true;
		KEY_UP_DOWN_RELEASE_2 = true;
		es->addEvent(new Player2StopY());
		if (!KEY_DOWN_RELEASE_2) {
			es->addEvent(new Player2MoveDown());
		}
	}
	if (key == player2Down) {
		//stop the player
		KEY_DOWN_RELEASE_2 = true;
		KEY_UP_DOWN_RELEASE_2 = true;
		es->addEvent(new Player2StopY());
		if (!KEY_UP_RELEASE_2) {
			es->addEvent(new Player2MoveUp());
		}

	}
	if (key == player2Left) {
		KEY_LEFT_RELEASE_2 = true;
		KEY_LEFT_RIGHT_RELEASE_2 = true;
		//stop the player
		es->addEvent(new Player2StopX());
		if (!KEY_RIGHT_RELEASE_2) {
			es->addEvent(new Player2MoveRight());
		}

	}
	if (key == player2Right) {
		KEY_RIGHT_RELEASE_2 = true;
		KEY_LEFT_RIGHT_RELEASE_2 = true;
		//stop the player
		es->addEvent(new Player2StopX());
		if (!KEY_LEFT_RELEASE_2) {
			es->addEvent(new Player2MoveLeft());

		}

	}

	if (key == player2Fire) {
		//reset the flag
		KEY_FIRE_RELEASE_2 = true;
	}
}

void UserInterface::handleButtonPressed2()
{
}

void UserInterface::handleButtonReleased2(int button)
{
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
	case action::PLAYER2_UP:
		buttonR = button;
		break;
	case action::PLAYER2_DOWN:
		buttonX = button;
		break;
	case action::PLAYER2_LEFT:
		buttonZ = button;
		break;
	case action::PLAYER2_RIGHT:
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
			handleKeyPress1(sfEvent.key.code);
			handleKeyPress2(sfEvent.key.code);
			break;
			//if player release the key
		case sf::Event::KeyReleased:
			handleKeyRelease1(sfEvent.key.code);
			handleKeyRelease2(sfEvent.key.code);
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
			handleButtonPressed1();
			break;
		case sf::Event::JoystickButtonReleased:
			handleButtonReleased1(sfEvent.joystickButton.button);
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