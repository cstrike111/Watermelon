#include "Game.h"

Game::Game(Physics* p, Graphic* g, EventSystem* e, AssetManager* am, FileSystem* f, Profile* pro, Audio* audio)
{
	this->p = p;
	this->g = g;
	this->e = e;
	this->f = f;
	this->am = am;
	this->pro = pro;
	this->audio = audio;

}

Game::~Game()
{
	delete player1;
	player1 = nullptr;
	delete player2;
	player2 = nullptr;

	//clean bullet
	vector<BulletEntity*>::iterator b1 = bullet1.begin();
	while (b1 != bullet1.end())
	{
		delete *b1;
		b1++;
	}
	vector<BulletEntity*>::iterator b2 = bullet2.begin();
	while (b2 != bullet2.end())
	{
		delete *b2;
		b2++;
	}
	bullet1.clear();
	bullet2.clear();
	
	if(levelLoad)
	{	
		levelLoad = false;
		//clean platforms
		vector<StaticSpriteEntity*>::iterator pList = (*platformList).begin();
		while (pList != (*platformList).end())
		{
			delete (*pList);
			pList++;
		}
		platformList->clear();
		platformList = nullptr;

		//clean border
		vector<boundingBox*>::iterator bList = (*borderList).begin();
		while (bList != (*borderList).end())
		{
			delete *bList;
			bList++;
		}
		borderList->clear();
		borderList = nullptr;

		//clean weapon spawn
		vector<WeaponSpawn*>::iterator wList = (*weaponSpawn).begin();
		while (wList != (*weaponSpawn).end())
		{
			delete *wList;
			wList++;
		}
		weaponSpawn->clear();
		weaponSpawn = nullptr;
		
	}
	
}

void Game::loadLevel1()
{	
	//set load flag
	levelLoad = true;
	//set up assets and entity
	//test for loading level
	platformList = new vector<StaticSpriteEntity*>();
	borderList = new vector<boundingBox*>();
	weaponSpawn = new vector<WeaponSpawn*>();
	//make game data struct
	GameData* gameData = new GameData();
	gameData->platformList = platformList;
	gameData->border = borderList;
	gameData->weaponSpawn = weaponSpawn;
	f->loadLevel1(gameData);
	player1spawnX = gameData->player1SpawnX;
	player1spawnY = gameData->player1SpawnY;
	player2spawnX = gameData->player2SpawnX;
	player2spawnY = gameData->player2SpawnY;

	//player 1
	player1 = new CharacterEntity();
	player1->setSprite(new sf::Sprite());
	player1->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/player1.png", AssetManager::TEXTURE)));
	player1->getSprite()->setOrigin(50 / 2, 100 / 2);
	player1->setWidth(50);
	player1->setHeight(100);
	player1->setTextureRect(0, 0, 50, 100);
	player1->bodyDef.position.Set(player1spawnX, player1spawnY);
	player1->playerNumber = 1;
	//collision rules
	player1->fixtureDef.filter.categoryBits = Entity::collisionCategory::PLAYER1;
	player1->fixtureDef.filter.maskBits = Entity::collisionCategory::DEFAULT | Entity::collisionCategory::BULLET2;
	player1->polygonShape.SetAsBox(2.5, 5);

	//player 2
	player2 = new CharacterEntity();
	player2->setSprite(new sf::Sprite());
	player2->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/player2.png", AssetManager::TEXTURE)));
	player2->getSprite()->setOrigin(50 / 2, 100 / 2);
	player2->setWidth(50);
	player2->setHeight(100);
	player2->setTextureRect(0, 0, 50, 100);
	player2->bodyDef.position.Set(player2spawnX, player2spawnY);
	player2->playerNumber = 2;
	player2->fixtureDef.filter.categoryBits = Entity::collisionCategory::PLAYER2;
	player2->fixtureDef.filter.maskBits = Entity::collisionCategory::DEFAULT | Entity::collisionCategory::BULLET1;
	player2->polygonShape.SetAsBox(2.5, 5);


	//add entity to graphic system and physics system
	f->setPlayer(player1); //tract player's information
	g->addEntity(player1, Entity::rType::CHARACTER);
	g->addEntity(player2, Entity::rType::CHARACTER);
	p->getPlayer(player1, player2);
	
	
	//load the level
	//platform
	for (int i = 0; i < platformList->size(); i++)
	{
		g->addEntity(platformList->at(i), Entity::rType::SPRITE);
		p->addStaticEntity(platformList->at(i));
	}
	//border
	for (int i = 0; i < borderList->size(); i++)
	{
		p->addStaticEntity(borderList->at(i));
	}
	//weapon spawn
	for (int i = 0; i < weaponSpawn->size(); i++)
	{
		g->addEntity(weaponSpawn->at(i), Entity::rType::BORDER);
		p->addStaticEntity(borderList->at(i));
	}

	//set up background
	g->background.setTexture((*(sf::Texture*) (am->loadAsset("asset/texture/page.jpg", AssetManager::TEXTURE))));
	g->background.setTextureRect(sf::IntRect(0,0,1920,1080));
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

	//check player hit stat
	vector<CharacterEntity::hitInfo>::iterator it1 = player1->hit.begin();
	while(it1 != player1->hit.end())
	{
		p->hitPlayer(it1->damage, 1, it1->direction);
		it1 = player1->hit.erase(it1);
		//hit sound
		audio->playHit1();
	}

	vector<CharacterEntity::hitInfo>::iterator it2 = player2->hit.begin();
	while (it2 != player2->hit.end())
	{
		p->hitPlayer(it2->damage, 2, it2->direction);
		it2 = player2->hit.erase(it2);
		//hit sound
		audio->playHit2();
	}

	//update jump value
	if(player1->jump)
	{
		p->jump1 = true;
	}
	if (player1->doubleJump)
	{
		p->doubleJump1 = true;
	}
	if (player2->jump)
	{
		p->jump2 = true;
	}
	if (player2->doubleJump)
	{
		p->doubleJump2 = true;
	}
	

	//delete the bullets
	//delete bullets in the renderer
	vector<BulletEntity*>::iterator gbList = g->bulletList.begin();
	while (gbList != g->bulletList.end())
	{
		if ((*gbList)->active == false)
		{
			gbList = g->bulletList.erase(gbList);
		}
		else
		{
			gbList++;
		}
	}
	//delete bullets in physics
	vector<BulletEntity*>::iterator pbList1 = p->bulletList1.begin();
	while (pbList1 != p->bulletList1.end())
	{
		if ((*pbList1)->active == false)
		{
			pbList1 = p->bulletList1.erase(pbList1);
		}
		else
		{
			pbList1++;
		}
	}
	vector<BulletEntity*>::iterator pbList2 = p->bulletList2.begin();
	while (pbList2 != p->bulletList2.end())
	{
		if ((*pbList2)->active == false)
		{
			pbList2 = p->bulletList2.erase(pbList2);
		}
		else
		{
			pbList2++;
		}
	}
	//delete bullets
	vector<BulletEntity*>::iterator b1 = bullet1.begin();
	while (b1 != bullet1.end())
	{
		if((*b1)->active == false)
		{
			delete (*b1);
			b1 = bullet1.erase(b1);
		}else
		{
			b1++;
		}
	}
	vector<BulletEntity*>::iterator b2 = bullet2.begin();
	while (b2 != bullet2.end())
	{
		if ((*b2)->active == false)
		{
			delete (*b2);
			b2 = bullet2.erase(b2);
		}
		else
		{
			b2++;
		}
	}

	//check the time
	player1BulletTime += pro->getTime();
	player2BulletTime += pro->getTime();
	//add ammo
	if(player1BulletTime > addBulletTime && player1->ammo < MAX_AMMO)
	{
		player1->ammo++;
		player1BulletTime = 0;
		g->ammo1 = to_string(player1->ammo);
	}
	if (player2BulletTime > addBulletTime && player2->ammo < MAX_AMMO)
	{
		player2->ammo++;
		player2BulletTime = 0;
		g->ammo2 = to_string(player2->ammo);
	}

	//if one player wins
	//stop updating the border
	p->win = win;
	if(win && won)
	{
		won = false;
		audio->playVictory();
	}


}



void Game::handleEvent(int eventType)
{
	switch (eventType) {
		BulletEntity * b;
	case Event::PLAYER1_FIRE:
		if(player1->ammo > 0)
		{
			//add bullet
			b = createBullet(1);
			bullet1.push_back(b);
			//push bullet to the renderer and physics list
			p->addBullet(b, 1);
			g->addEntity(b, Entity::rType::BULLET);
			//decrease ammo
			player1->ammo--;
			//play sound
			audio->playHadouken1();
			g->ammo1 = to_string(player1->ammo);
		}
		break;
	case Event::PLAYER2_FIRE:
		if (player2->ammo > 0)
		{
			b = createBullet(2);
			bullet2.push_back(b);
			//push bullet to the renderer and physics list
			p->addBullet(b, 2);
			g->addEntity(b, Entity::rType::BULLET);
			//decrease ammo
			player2->ammo--;
			//play sound
			audio->playHadouken2();
			g->ammo2 = to_string(player2->ammo);
		}
		break;
	case Event::PLAYER1_WIN:
		win = true;
		g->win1flag = true;
		cout << "player 1 win" << endl;
		break;
	case Event::PLAYER2_WIN:
		win = true;
		g->win2flag = true;
		cout << "player 2 win" << endl;
		break;
	case Event::PLAYER1_MOVE_UP:
		if(player1->jump)
		{
			player1->jump = false;
			p->jump1 = false;
		}else
		{
			if (player1->doubleJump) {
				player1->doubleJump = false;
				p->doubleJump1 = false;
			}
		}
		break;
	case Event::PLAYER2_MOVE_UP:
		if (player2->jump)
		{
			player2->jump = false;
			p->jump2 = false;
		}
		else
		{
			if (player2->doubleJump) {
				player2->doubleJump = false;
				p->doubleJump2 = false;
			}
		}
		break;

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
		b->setShape(new sf::RectangleShape(sf::Vector2f(25,25)));
		b->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/hadouken.png", AssetManager::TEXTURE)));
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
			b->setScale(glm::vec2(1, 1));
			b->bodyDef.linearVelocity = b2Vec2(b->bulletSpeed, 0);
		}
		//face to left
		else if(player1->getScale().x < 0)
		{
			float width = player1->getWidth() / player1->UNIT_PIXEL;
			float posX = player1->body->GetPosition().x;
			float posY = player1->body->GetPosition().y;
			b->bodyDef.position.Set(posX - width - 0.5, posY);
			b->setScale(glm::vec2(-1, 1));
			b->bodyDef.linearVelocity = b2Vec2(-b->bulletSpeed, 0);
		}
		
		return b;
		break;

	case 2:
		b->setShape(new sf::RectangleShape(sf::Vector2f(25, 25)));
		b->getShape()->setFillColor(sf::Color::Blue);
		b->setTexture(static_cast<sf::Texture*> (am->loadAsset("asset/texture/hadouken.png", AssetManager::TEXTURE)));
		b->bodyDef.bullet = true;
		b->bodyDef.fixedRotation = true;
		b->fixtureDef.isSensor = true;
		b->bodyDef.gravityScale = 0;
		b->fixtureDef.density = 1;
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
			b->setScale(glm::vec2(1, 1));
			b->bodyDef.linearVelocity = b2Vec2(b->bulletSpeed, 0);			
		}
		else if (player2->getScale().x < 0)
		{
			float width = player2->getWidth() / player2->UNIT_PIXEL;
			float posX = player2->body->GetPosition().x;
			float posY = player2->body->GetPosition().y;
			b->bodyDef.position.Set(posX - width - 0.5, posY);
			b->setScale(glm::vec2(-1, 1));
			b->bodyDef.linearVelocity = b2Vec2(-b->bulletSpeed, 0);
		}
		return b;
		break;

	default:
		return nullptr;
		break;
	}

	
}


