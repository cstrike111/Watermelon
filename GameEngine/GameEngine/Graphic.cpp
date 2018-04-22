#include "Graphic.h"

Graphic::Graphic(sf::RenderWindow* window) {
	this->window = window;
	openglInit();
}

Graphic::~Graphic() {
	window = nullptr;
}

bool Graphic::loadImage(string path) {
	return true;
}

bool Graphic::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::GRAPHIC)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popGraphic();
		}
	}
	

	window->clear();
	openglDraw();
	window->pushGLStates();
	draw();
	window->popGLStates();
	window->display();
	return true;
}

void Graphic::draw() {
	
	//draw shape
	for (int i = 0; i < shapeList.size(); i++) {
		ShapeEntity* se = shapeList.at(i);
		window->draw(*(se->getShape()));
	}
}

void Graphic::getEventSystem(EventSystem* es){
	this->es = es;
}

void Graphic::handleEvent(int eventType) {
	switch (eventType) {
	default:
		break;
	}
}

void Graphic::openglDraw() {
	int i;

	for (i = 0; i < 6; i++) {
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
}

void Graphic::openglInit() {
	/* Setup cube vertex data. */
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

	/* Enable a single OpenGL light. */
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	/* Use depth buffering for hidden surface elimination. */
	glEnable(GL_DEPTH_TEST);

	/* Setup the view of the cube. */
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0, 0.0, -2.5);
	glRotatef(60, 1.0, 0.0, 0.0);
	glRotatef(-20, 0.0, 0.0, 1.0);
}

void Graphic::addEntity(Entity* e, Entity::rType renderType) {
	switch (renderType) {
	case Entity::rType::MESH:
		meshList.push_back(e);
		break;
	case Entity::rType::SHAPE:
		shapeList.push_back(static_cast<ShapeEntity*> (e));
		break;
	case Entity::rType::SPRITE:
		spriteList.push_back(e);
		break;
	default:
		break;
	}
	
}

