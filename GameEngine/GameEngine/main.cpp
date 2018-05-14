#include <iostream>
#include "Graphic.h"
#include "UserInterface.h"
#include "Audio.h"
#include "Physics.h"
#include "ShapeEntity.h"
#include "AssetManager.h"
#include "Profile.h"
#include "FileSystem.h"
#include "StaticSpriteEntity.h"
#include "CharacterEntity.h"
#include "Animation.h"

//configuration of the parameters
//resolution
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

//world parameters
b2Vec2 gravity(0.0f, 0.0f);

//declare of sub-system and window
Graphic* g; //renderer
UserInterface* ui; //user interface sub-system
EventSystem* es; //event system
Audio* a; //audio system
Physics* p; //physics system
AssetManager* asset; //Asset Manager
Profile* pro; //Profile system
FileSystem* file; //file system
sf::RenderWindow* window;

//pointer of entity
CharacterEntity* player;
StaticSpriteEntity* platform;
ShapeEntity* circle;
CharacterEntity* animationTest;

bool init() {
	//initializing flag
	bool success = true;

	//create window
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "A SUPER FUN GAME!");
	if (window->isOpen()) {
		success = true;
		window->setFramerateLimit(60); //limit the fps
		//pass the window to sub-systems and create sub-systems
		//be careful with the order
		es = new EventSystem(window);
		asset = new AssetManager();
		g = new Graphic(window, asset);
		ui = new UserInterface(window);
		p = new Physics(gravity);
		a = new Audio(asset);
		pro = new Profile();
		file = new FileSystem();

		//pass the profile system to sub-systems
		g->setProfileSystem(pro);
		p->setProfileSystem(pro);

		//pass the event system to sub-systems
		g->setEventSystem(es);
		ui->setEventSystem(es);
		a->setEventSystem(es);
		p->setEventSystem(es);
		a->setEventSystem(es);
		asset->setEventSystem(es);
		pro->setEventSystem(es);
		file->setEventSystem(es);

		//set up assets and entity
		//player
		player = new CharacterEntity();
		player->setSprite(new sf::Sprite());
		player->setTexture(static_cast<sf::Texture*> (asset->loadAsset("asset/texture/player.png", AssetManager::TEXTURE)));
		player->getSprite()->setOrigin(106 / 2, 233 / 2);
		player->setWidth(106);
		player->setHeight(233);
		player->setTextureRect(0, 0, 106, 233);
		player->bodyDef.position.Set(92, -63);
		player->polygonShape.SetAsBox(5.3f, 11.65f);

		//platform
		platform = new StaticSpriteEntity();
		platform->setSprite(new sf::Sprite());
		platform->setPosition(glm::vec2(200, 300));
		platform->setTexture(static_cast<sf::Texture*> (asset->loadAsset("asset/texture/wood.jpg", AssetManager::TEXTURE)));
		platform->getSprite()->setOrigin(200 / 2, 50 / 2);
		platform->setTextureRect(0, 0, 200, 50);
		platform->setWidth(200);
		platform->setHeight(50);
		platform->bodyDef.position.Set(20.0f, -30.0f);
		platform->polygonShape.SetAsBox(10.0f, 2.5f);

		//demo circle
		circle = new ShapeEntity();
		circle->setShape(new sf::CircleShape(50));
		circle->getShape()->setFillColor(sf::Color::Green);
		file->demoCircle(circle);

		//animation test
		animationTest = new CharacterEntity();
		animationTest->setSprite(new sf::Sprite());
		//set up animation
		//20x30
		Animation* animation = new Animation();
		animation->setTexture((sf::Texture*)asset->loadAsset( "asset/animation/spritesheet.png", AssetManager::TEXTURE));
		animation->frameColumn = 2;
		animation->frameRow = 4;
		animation->frameWidth = 100;
		animation->frameHeight = 64;
		animation->createAnimation();
		animationTest->setAnimation(*animation);
		animationTest->getSprite()->setOrigin(animation->frameWidth/2, animation->frameHeight / 2);
		animationTest->setPosition(glm::vec2(200, 300));
		animationTest->bodyDef.position.Set(30, 30);
		animationTest->polygonShape.SetAsBox(5.3f, 11.65f);
		
		

		//add entity to graphic system and physics system
		file->setPlayer(player); //tract player's information
		g->addEntity(player, Entity::rType::CHARACTER);
		g->addEntity(circle, Entity::rType::SHAPE);
		g->addEntity(platform, Entity::rType::SPRITE);
		g->addEntity(animationTest, Entity::rType::CHARACTER);
		p->getPlayer(player);
		p->addStaticEntity(platform);
	
	}
	else {
		success = false;
	}
	return success;
}

void close() {
	//clean the memory
	//window
	window->close();
	window = nullptr;

	//clean the graphic subsystem
	delete g;
	g = nullptr;

	//clean the input subsystem
	delete ui;
	ui = nullptr;

	//clean the event system
	delete es;
	es = nullptr;

	//clean the physics system
	delete p;
	p = nullptr;

	//clean asset manager system
	delete asset;
	asset = nullptr;

	//clean audio system
	delete a;
	a = nullptr;

	//clean profile system
	delete pro;
	pro = nullptr;

	//clean file system
	delete file;
	file = nullptr;

	//clean the memory of entities
	//delete player
	delete player;
	player = nullptr;

	delete platform;
	platform = nullptr;

	delete circle;
	circle = nullptr;
	

}

//game loop
void gameLoop() {
	es->update();
	g->update();
	ui->update();
	a->update();
	p->update();
	asset->update();
	pro->update();
	file->update();
}

int main()
{		
	//start
	if (!init()) {
		cout << "Oops! Something wrong happened!\n";
	}
	else {
		//game loop
		while (window->isOpen()) {
			gameLoop();
		}
	}
	//close
	close();

	return 0;
}