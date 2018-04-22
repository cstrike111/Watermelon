#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include "EventSystem.h"
#include "Entity.h"
#include "ShapeEntity.h"

using namespace std;

class Graphic {
public:
	Graphic(sf::RenderWindow* window);
	~Graphic();
	bool loadImage(string path);
	bool update();
	void getEventSystem(EventSystem* es);
	void handleEvent(int eventType);
	void openglInit();
	void openglDraw();
	void addEntity(Entity* e, Entity::rType renderType);
	void draw();


private:
	bool load; // whether the image is loaded
	sf::RenderWindow* window; //a sfml window pointer
	EventSystem* es; //pointer for event system
	vector<ShapeEntity*> shapeList; //a list of shapes
	vector<Entity*> meshList; //a list of mesh
	vector<Entity*> spriteList; //a list of mesh


	//opengl parameters
	GLfloat light_diffuse[4] = { 1.0, 0.0, 0.0, 1.0 };  /* Red diffuse light. */
	GLfloat light_position[4] = { 1.0, 1.0, 1.0, 0.0 };  /* Infinite light location. */
	GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
		{ -1.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0 },{ 1.0, 0.0, 0.0 },
	{ 0.0, -1.0, 0.0 },{ 0.0, 0.0, 1.0 },{ 0.0, 0.0, -1.0 } };
	GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
		{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },
	{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };
	GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */
};