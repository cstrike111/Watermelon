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
#include "..\Entity\StaticShapeEntity.h"
#include "..\Entity\CharacterEntity.h"
#include "..\Entity\BulletEntity.h"
#include "..\Entity\boundingbox.h"
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
	void player1Win();
	void player2Win();
	void drawBulletInfo();

	//bullet list
	vector<BulletEntity*> bulletList;

	//background
	sf::Sprite background;
	sf::Text win1;
	sf::Text win2;
	sf::Text ammoText1;
	sf::Text ammoText2;
	string ammo1;
	string ammo2;

	//win flag
	bool win1flag = false; //player 1
	bool win2flag = false; //player 2

private:
	bool load; // whether the image is loaded
	sf::RenderWindow* window; //a sfml window pointer
	EventSystem* es; //pointer for event system
	Profile* p; //profile system pointer
	AssetManager* am; //asset manager pointer
	vector<ShapeEntity*> shapeList; //a list of shapes
	vector<Entity*> meshList; //a list of mesh
	vector<StaticSpriteEntity*> spriteList; //a list of sprite
	vector<StaticShapeEntity*> staticShapeList; //a list of static shape
	vector<CharacterEntity*> chaList; //a list of Character
	vector<boundingBox*> boundingBoxList; //a list of boundingBox

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