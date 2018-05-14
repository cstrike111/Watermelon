#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include "..\EventSystem\EventSystem.h"
#include "..\Entity\Entity.h"
#include "..\EventSystem\Event.h"
#include "..\Entity\ShapeEntity.h"
#include "..\Entity\StaticSpriteEntity.h"
#include "..\Entity\CharacterEntity.h"
#include "..\Profile\Profile.h"
#include "..\AssetManager\AssetManager.h"

using namespace std;

class Graphic {
public:
	Graphic(sf::RenderWindow* window, AssetManager* am);
	~Graphic();
	void loadAsset(); //load the asset
	bool update(); //update the system
	void setEventSystem(EventSystem* es);
	void handleEvent(int eventType);
	void openglInit(); //initialize for opengl
	void openglDraw(); //draw opengl things
	void addEntity(Entity* e, Entity::rType renderType); //add entity
	void draw(); //draw
	void showFps(); //show fps
	void showPlayerRenderInfo(); //show information of player
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
	vector<CharacterEntity*> chaList; //a list of mesh

	//profile information enable flag
	bool fpsEnable = false;
	bool playerinfo = false;

	//asset pointer
	sf::Font* Calibri;

	//Text
	sf::Text fps;
	sf::Text playerRenderInfo;
	sf::Text playerPhysicsInfo;

};