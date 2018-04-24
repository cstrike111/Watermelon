#pragma once

class Event {
public:
	//enum for subsystem
	//question: push the event to the list or push the enum to the list?
	//subsystem can pop itself from here, and the event system will turn off the light in the end
	enum subsystem {
		GRAPHIC,
		PHYSICS,
		UI,
		AUDIO,
		ASSETMANAGER,
		PROFILE,
		FILE
	};
	enum event {
		KEYPRESS,
		CONTROLLER_CONNECTED,
		CONTROLLER_DISCONNECTED,
		BUTTON_PRESS,
		PLAYER_MOVE_LEFT,
		PLAYER_MOVE_RIGHT,
		PLAYER_MOVE_UP,
		PLAYER_MOVE_DOWN,
		PLAYER_STOP_Y,
		PLAYER_STOP_X,
		KEYRELEASE,
		TOGGLE_SHOW_FPS,
		SAVE,
		LOAD,
		QUIT
	};
	Event();
	~Event();
	bool getSubSystem(int subsystem);
	int getEventType();

	//pop the systems
	void popGraphic();
	void popPhysics();
	void popUI();
	void popAudio();
	void popAssetManager();
	void popProfile();
	void popFile();

	//check whether there is system that still has job to do
	bool isActive();

protected:
	int eventType; //type of event
	//a list records which system has job to do
	//the index will indicate which subsystem it is (refer to subsystem enum)
	bool active[7] = { false, false, false, false, false, false, false };
};