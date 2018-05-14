#include "Game.h"

Game::Game(Physics* p, Graphic* g, EventSystem* e, AssetManager* am, FileSystem* f)
{
	this->p = p;
	this->g = g;
	this->e = e;
	this->f = f;
	this->am = am;
}

Game::~Game()
{
	if(level1Load)
	{	
		level1Load = false;
		platformList->clear();
		platformList = nullptr;
		delete player1;
		player1 = nullptr;
		delete platform;
		platform = nullptr;
		delete platform2;
		platform2 = nullptr;
		delete circle;
		circle = nullptr;
		delete animationTest;
		animationTest = nullptr;
	}
	
}

void Game::loadLevel1()
{
	//set up assets and entity
	//player
	player1 = new CharacterEntity();
	player1->setSprite(new sf::Sprite());
	player1->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/player.png", AssetManager::TEXTURE)));
	player1->getSprite()->setOrigin(106 / 2, 233 / 2);
	player1->setWidth(106);
	player1->setHeight(233);
	player1->setTextureRect(0, 0, 106, 233);
	player1->bodyDef.position.Set(0, 0);
	player1->polygonShape.SetAsBox(5.3f, 11.65f);

	//platform
	platform = new StaticSpriteEntity();
	platform->setSprite(new sf::Sprite());
	platform->setPosition(glm::vec2(200, 300));
	platform->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/wood.jpg", AssetManager::TEXTURE)));
	platform->getSprite()->setOrigin(200 / 2, 50 / 2);
	platform->setTextureRect(0, 0, 200, 50);
	//platform->setWidth(200);
	//platform->setHeight(50);
	platform->bodyDef.position.Set(20.0f, -30.0f);
	platform->polygonShape.SetAsBox(10.0f, 2.5f); //half length!

	platform2 = new StaticSpriteEntity();
	platform2->setSprite(new sf::Sprite());
	platform2->setPosition(glm::vec2(500, 600));
	platform2->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/wood.jpg", AssetManager::TEXTURE)));
	platform2->getSprite()->setOrigin(200 / 2, 50 / 2);
	platform2->setTextureRect(0, 0, 200, 50);
	//platform2->setWidth(200);
	//platform2->setHeight(50);
	platform2->bodyDef.position.Set(50.0f, -60.0f);
	platform2->polygonShape.SetAsBox(10.0f, 2.5f);

	//demo circle
	circle = new ShapeEntity();
	circle->setShape(new sf::CircleShape(50));
	circle->getShape()->setFillColor(sf::Color::Green);
	f->demoCircle(circle);

	//animation test
	animationTest = new CharacterEntity();
	animationTest->setSprite(new sf::Sprite());
	//set up animation
	//20x30
	Animation* animation = new Animation();
	animation->setTexture((sf::Texture*)am->loadAsset("asset/animation/spritesheet.png", AssetManager::TEXTURE));
	animation->frameColumn = 2;
	animation->frameRow = 4;
	animation->frameWidth = 100;
	animation->frameHeight = 64;
	animation->createAnimation();
	animationTest->setAnimation(*animation);
	animationTest->getSprite()->setOrigin(animation->frameWidth / 2, animation->frameHeight / 2);
	animationTest->setPosition(glm::vec2(200, 300));
	animationTest->bodyDef.position.Set(30, 30);
	animationTest->polygonShape.SetAsBox(5.3f, 11.65f);

	//add entity to graphic system and physics system
	f->setPlayer(player1); //tract player's information
	g->addEntity(player1, Entity::rType::CHARACTER);
	g->addEntity(circle, Entity::rType::SHAPE);
	g->addEntity(platform, Entity::rType::SPRITE);
	g->addEntity(platform2, Entity::rType::SPRITE);
	g->addEntity(animationTest, Entity::rType::CHARACTER);
	p->getPlayer(player1);
	p->addStaticEntity(platform);
	p->addStaticEntity(platform2);

	//test for loading level
	platformList = new vector<StaticSpriteEntity*>();
	f->loadLevel1(platformList);
	//load the level
	for (int i = 0; i < platformList->size(); i++)
	{
		g->addEntity(platformList->at(i), Entity::rType::SPRITE);
		p->addStaticEntity(platformList->at(i));
	}
}

void Game::update()
{
}
