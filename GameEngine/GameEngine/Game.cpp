#include "Game.h"

Game::Game(Physics* p, Graphic* g, EventSystem* e, AssetManager* am, FileSystem* f)
{
	this->p = p;
	this->g = g;
	this->e = e;
	this->f = f;
	this->am = am;

	//initialize the bullet lists
}

Game::~Game()
{
	delete player1;
	player1 = nullptr;
	delete player2;
	player2 = nullptr;

	bullet1.clear();
	bullet2.clear();
	
	if(level1Load)
	{	
		level1Load = false;
		platformList->clear();
		platformList = nullptr;
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
	//test for loading level
	platformList = new vector<StaticSpriteEntity*>();
	//make game data struct
	GameData* gameData = new GameData();
	gameData->platformList = platformList;
	f->loadLevel1(gameData);
	player1spawnX = gameData->player1SpawnX;
	player1spawnY = gameData->player1SpawnY;
	player2spawnX = gameData->player2SpawnX;
	player2spawnY = gameData->player2SpawnY;

	//player 1
	player1 = new CharacterEntity();
	player1->setSprite(new sf::Sprite());
	player1->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/player1.png", AssetManager::TEXTURE)));
	player1->getSprite()->setOrigin(106 / 2, 233 / 2);
	player1->setWidth(106);
	player1->setHeight(233);
	player1->setTextureRect(0, 0, 106, 233);
	player1->bodyDef.position.Set(player1spawnX, player1spawnY);
	//collision rules
	player1->fixtureDef.filter.categoryBits = Entity::collisionCategory::PLAYER1;
	player1->fixtureDef.filter.maskBits = Entity::collisionCategory::DEFAULT | Entity::collisionCategory::BULLET2;
	player1->polygonShape.SetAsBox(5.3f, 11.65f);

	//player 2
	player2 = new CharacterEntity();
	player2->setSprite(new sf::Sprite());
	player2->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/player2.png", AssetManager::TEXTURE)));
	player2->getSprite()->setOrigin(106 / 2, 233 / 2);
	player2->setWidth(106);
	player2->setHeight(233);
	player2->setTextureRect(0, 0, 106, 233);
	player2->bodyDef.position.Set(player2spawnX, player2spawnY);
	player2->fixtureDef.filter.categoryBits = Entity::collisionCategory::PLAYER2;
	player2->fixtureDef.filter.maskBits = Entity::collisionCategory::DEFAULT | Entity::collisionCategory::BULLET1;
	player2->polygonShape.SetAsBox(5.3f, 11.65f);

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
	g->addEntity(player2, Entity::rType::CHARACTER);
	g->addEntity(circle, Entity::rType::SHAPE);
	g->addEntity(platform, Entity::rType::SPRITE);
	g->addEntity(platform2, Entity::rType::SPRITE);
	g->addEntity(animationTest, Entity::rType::CHARACTER);
	p->getPlayer(player1, player2);
	p->addStaticEntity(platform);
	p->addStaticEntity(platform2);

	
	
	//f->loadLevel1();
	//load the level
	for (int i = 0; i < platformList->size(); i++)
	{
		g->addEntity(platformList->at(i), Entity::rType::SPRITE);
		p->addStaticEntity(platformList->at(i));
	}

	currentLevel = 1;

	//clean the memory
	delete gameData;
}



void Game::update()
{	//handle the event
	//check the queue
	if (e->getEventQueue()->size() != 0) {
		if (e->getEventQueue()->front().getSubSystem(Event::subsystem::GAME)) {
			//handle event
			handleEvent(e->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			e->getEventQueue()->front().popGame();
		}
	}

	//if a player touch the dead border, show win message
	
	
}



void Game::handleEvent(int eventType)
{
	switch (eventType) {
		BulletEntity * b;
	case Event::PLAYER1_FIRE:
		//add bullet
		b = createBullet(1);
		bullet1.push_back(b);
		//push bullet to the renderer and physics list
		p->addBullet(b, 1);
		g->addEntity(b, Entity::rType::BULLET);
		//delete bullet(pass the pointer of the bullet to the sub system)
		break;
	case Event::PLAYER2_FIRE:
		b = createBullet(2);
		bullet2.push_back(b);
		//push bullet to the renderer and physics list
		p->addBullet(b, 2);
		g->addEntity(b, Entity::rType::BULLET);
		break;
	//player 1 get hit
	//player 2 get hit
	//player 1 touch the dead border
	//player 2 touch the dead border

	default:
		break;
	}
}

BulletEntity* Game::createBullet(int player)
{
	BulletEntity * b = new BulletEntity();
	switch(player)
	{
	case 1:
		//configure the bullet according to the weapon type
		b->setShape(new sf::CircleShape(5));
		b->getShape()->setFillColor(sf::Color::Blue);
		b->bodyDef.bullet = true;
		b->bodyDef.fixedRotation = true;
		b->fixtureDef.isSensor = true;
		b->fixtureDef.density = 1000;
		b->bodyDef.gravityScale = 0;
		b->polygonShape.SetAsBox(0.5, 0.5);
		b->fixtureDef.filter.categoryBits = Entity::collisionCategory::BULLET1;
		b->fixtureDef.filter.maskBits = Entity::collisionCategory::DEFAULT | Entity::collisionCategory::PLAYER2;
		//face to right
		if(player1->getScale().x > 0)
		{
			float width = player1->getWidth() / player1->UNIT_PIXEL;
			float posX = player1->body->GetPosition().x;
			float posY = player1->body->GetPosition().y;
			b->bodyDef.position.Set(posX + width + 0.5, posY);
			b->bodyDef.linearVelocity = b2Vec2(b->bulletSpeed, 0);
		}
		//face to left
		else if(player1->getScale().x < 0)
		{
			float width = player1->getWidth() / player1->UNIT_PIXEL;
			float posX = player1->body->GetPosition().x;
			float posY = player1->body->GetPosition().y;
			b->bodyDef.position.Set(posX - width - 0.5, posY);
			b->bodyDef.linearVelocity = b2Vec2(-b->bulletSpeed, 0);
		}
		
		return b;
		break;

	case 2:
		b->setShape(new sf::CircleShape(5));
		b->getShape()->setFillColor(sf::Color::Blue);
		b->bodyDef.bullet = true;
		b->bodyDef.fixedRotation = true;
		b->fixtureDef.isSensor = true;
		b->bodyDef.gravityScale = 0;
		b->fixtureDef.density = 1000;
		b->polygonShape.SetAsBox(0.5, 0.5);
		//collision rules
		b->fixtureDef.filter.categoryBits = Entity::collisionCategory::BULLET2;
		b->fixtureDef.filter.maskBits = Entity::collisionCategory::DEFAULT | Entity::collisionCategory::PLAYER1;
		//face to right
		if (player2->getScale().x > 0)
		{
			float width = player2->getWidth() / player2->UNIT_PIXEL;
			float posX = player2->body->GetPosition().x;
			float posY = player2->body->GetPosition().y;
			b->bodyDef.position.Set(posX + width + 0.5, posY);		
			b->bodyDef.linearVelocity = b2Vec2(b->bulletSpeed, 0);
			//b->fixtureDef.isSensor = true;			
		}
		else if (player2->getScale().x < 0)
		{
			float width = player2->getWidth() / player2->UNIT_PIXEL;
			float posX = player2->body->GetPosition().x;
			float posY = player2->body->GetPosition().y;
			b->bodyDef.position.Set(posX - width - 0.5, posY);
			b->bodyDef.linearVelocity = b2Vec2(-b->bulletSpeed, 0);
			//b->fixtureDef.isSensor = true;
		}
		return b;
		break;

	default:
		return nullptr;
		break;
	}

	
}


