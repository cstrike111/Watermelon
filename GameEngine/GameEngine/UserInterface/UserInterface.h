#pragma once
#include "..\EventSystem\EventSystem.h"
#include <iostream>
#include <queue>

class UserInterface {
public:
	//action for configuration of keys
	enum action{PLAYER1_UP,
	            PLAYER1_DOWN,
	            PLAYER1_LEFT,
	            PLAYER1_RIGHT,
				PLAYER2_UP,
				PLAYER2_DOWN,
				PLAYER2_LEFT,
				PLAYER2_RIGHT
							};
	
	//constructor and destructor
	UserInterface(sf::RenderWindow* window);
	~UserInterface();

	void handleEvent(int eventType); //event handler
	void handleKeyPress1(sf::Keyboard::Key key); //react according to the key that user presses
	void handleKeyRelease1(sf::Keyboard::Key key); //react according to the key that user presses
	//handle button
	void handleButtonPressed1(); //react according to the button that user presses on the controller
	void handleButtonReleased1(int button); //react according to the button that user releases on the controller
	void handleKeyPress2(sf::Keyboard::Key key); //react according to the key that user presses
	void handleKeyRelease2(sf::Keyboard::Key key); //react according to the key that user presses
												   //handle button
	void handleButtonPressed2(); //react according to the button that user presses on the controller
	void handleButtonReleased2(int button); //react according to the button that user releases on the controller
	void handleAxisMove(int axis, float position); //react according to the axis that user moves on the controller
	void setButton(int action, int button); //configure the button
	void setKey(int action, sf::Keyboard::Key key); //change the configuration of the key
	void setEventSystem(EventSystem* es); //get the event sub-system
	void update(); //update the user interface

private:
	//key press surfaces constants
	EventSystem * es; //event system pointer
	sf::RenderWindow* window; //a sfml window pointer
	sf::Event e; //sfml event pointer

	//configuration of the keys(player_move_up, etc.)
	//keyboard
	sf::Keyboard::Key player1Up = sf::Keyboard::W;
	sf::Keyboard::Key player1Down = sf::Keyboard::S;
	sf::Keyboard::Key player1Left = sf::Keyboard::A;
	sf::Keyboard::Key player1Right = sf::Keyboard::D;
	sf::Keyboard::Key player1Fire = sf::Keyboard::J;
	sf::Keyboard::Key player2Up = sf::Keyboard::Up;
	sf::Keyboard::Key player2Down = sf::Keyboard::Down;
	sf::Keyboard::Key player2Left = sf::Keyboard::Left;
	sf::Keyboard::Key player2Right = sf::Keyboard::Right;
	sf::Keyboard::Key player2Fire = sf::Keyboard::Space;
	
	//controller
	int buttonR = sf::Joystick::R;
	int buttonX = sf::Joystick::X;
	int buttonZ = sf::Joystick::Z;
	int buttonY = sf::Joystick::Y;
	//xbox controller

	//sfml event
	sf::Event sfEvent;

	//key flag
	bool KEY_UP_RELEASE_1 = true;
	bool KEY_DOWN_RELEASE_1 = true;
	bool KEY_LEFT_RELEASE_1 = true;
	bool KEY_RIGHT_RELEASE_1 = true;
	bool KEY_LEFT_RIGHT_RELEASE_1 = true;
	bool KEY_UP_DOWN_RELEASE_1 = true;
	bool KEY_FIRE_RELEASE_1 = true;
	bool KEY_UP_RELEASE_2 = true;
	bool KEY_DOWN_RELEASE_2 = true;
	bool KEY_LEFT_RELEASE_2 = true;
	bool KEY_RIGHT_RELEASE_2 = true;
	bool KEY_LEFT_RIGHT_RELEASE_2 = true;
	bool KEY_UP_DOWN_RELEASE_2 = true;
	bool KEY_FIRE_RELEASE_2 = true;

};



