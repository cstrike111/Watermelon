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
#include "CharacterEntity.h"
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
	void showPlayerRenderInfo();
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