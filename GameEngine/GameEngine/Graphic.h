#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include "EventSystem.h"
#include "Entity.h"
#include "Event.h"
#include "ShapeEntity.h"
#include "StaticSpriteEntity.h"
#include "Profile.h"
#include "AssetManager.h"

using namespace std;

class Graphic {
public:
	Graphic(sf::RenderWindow* window, AssetManager* am);
	~Graphic();
	void loadAsset();
	bool update();
	void setEventSystem(EventSystem* es);
	void handleEvent(int eventType);
	void openglInit();
	void openglDraw();
	void addEntity(Entity* e, Entity::rType renderType);
	void draw();
	void showFps();
	void setProfileSystem(Profile* p);


private:
	bool load; // whether the image is loaded
	sf::RenderWindow* window; //a sfml window pointer
	EventSystem* es; //pointer for event system
	Profile* p; //profile system pointer
	AssetManager* am; //asset manager pointer
	vector<ShapeEntity*> shapeList; //a list of shapes
	vector<Entity*> meshList; //a list of mesh
	vector<StaticSpriteEntity*> spriteList; //a list of sprite
	vector<Entity*> playerList; //a list of mesh
	sf::Text playerPosition;

	//fps enable flag
	bool fpsEnable = false;

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

	//asset pointer
	sf::Font* Calibri;
	sf::Text fps;

};