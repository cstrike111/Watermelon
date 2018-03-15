#pragma once
#pragma once
#include <vector>
#include "Event.h"
using namespace std;

class EventSystem {
public:
	EventSystem();
	~EventSystem();

	void addEvent(Event e);
	void removeEvent();

	vector<Event>* queue;
private:
	
};