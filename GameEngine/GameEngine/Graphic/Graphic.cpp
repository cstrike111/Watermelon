#include "Graphic.h"

Graphic::Graphic(sf::RenderWindow* window, AssetManager* am) {
	this->window = window;
	this->am = am;
	openglInit();
	loadAsset();
	ammoText1.setCharacterSize(48);
	ammoText2.setCharacterSize(48);
	ammoText1.setFillColor(sf::Color::Black);
	ammoText2.setFillColor(sf::Color::Black);
	ammoText1.setPosition(320, 30);
	ammoText2.setPosition(1340, 30);
}

Graphic::~Graphic() {
	window = nullptr;
}

void Graphic::loadAsset() {
	//load the font
	Calibri = static_cast<sf::Font*>(am->loadAsset("asset/font/Calibri.ttf", AssetManager::FONT));
	playerRenderInfo.setFont(*Calibri);
	playerPhysicsInfo.setFont(*Calibri);
	fps.setFont(*Calibri);
	win1.setFont(*Calibri);
	win2.setFont(*Calibri);
	ammoText1.setFont(*Calibri);
	ammoText2.setFont(*Calibri);
	ammoText1.setPosition(2,2);
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
	
	//draw background
	window->draw(background);
	
	//draw shape
	for (int i = 0; i < shapeList.size(); i++) {
		ShapeEntity* se = shapeList.at(i);
		sf::Shape* s = shapeList.at(i)->getShape();
		//update position
		s->setPosition(se->getPosition().x, se->getPosition().y);
		window->draw(*s);
	}


	//draw bullet
	for (int i = 0; i < bulletList.size(); i++) {
		BulletEntity* b = bulletList.at(i);
		sf::Shape* s = bulletList.at(i)->getShape();
		//update position
		s->setPosition(b->getPosition().x, b->getPosition().y);
		window->draw(*s);
	}

	//draw static sprite
	for (int i = 0; i < spriteList.size(); i++) {
		StaticSpriteEntity* se = spriteList.at(i);
		sf::Sprite* s = spriteList.at(i)->getSprite();
		window->draw(*s);
	}

	//draw static shape
	for (int i = 0; i < staticShapeList.size(); i++) {
		StaticShapeEntity* se = staticShapeList.at(i);
		sf::Shape* s = staticShapeList.at(i)->getShape();
		window->draw(*s);
	}

	//draw boundingBox
	for (int i = 0; i < boundingBoxList.size(); i++) {
		boundingBox* b = boundingBoxList.at(i);
		sf::Shape* s = boundingBoxList.at(i)->getShape();
		window->draw(*s);
	}

	//draw character
	for (int i = 0; i < chaList.size(); i++) {
		CharacterEntity* c = chaList.at(i);
		sf::Sprite* s = chaList.at(i)->getSprite();
		//update position
		s->setPosition(c->getPosition().x, c->getPosition().y);
		//get animation
		if(c->isAnimated)
		{
			c->playAnimation();
		}
		window->draw(*s);
	}

	showPlayerRenderInfo();
	showFps();
	player1Win();
	player2Win();
	drawBulletInfo();

}

void Graphic::setEventSystem(EventSystem* es){
	this->es = es;
}

void Graphic::handleEvent(int eventType) {
	switch (eventType) {
	case Event::TOGGLE_SHOW_FPS:
		if (fpsEnable) {
			fpsEnable = false;
		}
		else {
			fpsEnable = true;
		}
		break;

	case Event::TOGGLE_SHOW_INFO:
		if (playerinfo) {
			playerinfo = false;
		}
		else {
			playerinfo = true;
		}
		break;
	default:
		break;
	}
}

void Graphic::openglDraw() {

}

void Graphic::openglInit() {
	
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
		spriteList.push_back(static_cast<StaticSpriteEntity*> (e));
		break;
	case Entity::rType::CHARACTER:
		chaList.push_back(static_cast<CharacterEntity*> (e));
		break;
	case Entity::rType::BULLET:
		bulletList.push_back(static_cast<BulletEntity*> (e));
		break;
	case Entity::rType::STATIC_SHAPE:
		staticShapeList.push_back(static_cast<StaticShapeEntity*> (e));
		break;
	case Entity::rType::BORDER:
		boundingBoxList.push_back(static_cast<boundingBox*> (e));
		break;
	default:
		break;
	}
	
}

void Graphic::setProfileSystem(Profile* p) {
	this->p = p;
}

void Graphic::player1Win()
{
	if (win1flag) {
		string win = "PLAYER 1 WIN!";
		win1.setString(win);
		win1.setCharacterSize(72);
		win1.setFillColor(sf::Color::Blue);
		win1.setPosition(780, 540);
		window->draw(win1);
	}
}

void Graphic::player2Win()
{
	if (win2flag) {
		string win = "PLAYER 2 WIN!";
		win2.setString(win);
		win2.setCharacterSize(72);
		win2.setFillColor(sf::Color::Blue);
		win2.setPosition(780, 540);
		window->draw(win2);
	}
}

void Graphic::drawBulletInfo()
{
	string ammoInfo1 = "Player 1 ammo: " + ammo1;
	ammoText1.setString(ammoInfo1);
	string ammoInfo2 = "Player 2 ammo: " + ammo2;
	ammoText2.setString(ammoInfo2);
	window->draw(ammoText1);
	window->draw(ammoText2);
}

void Graphic::showFps() {
	if (fpsEnable) {
		string fpsString = "FPS: " + to_string(p->getFps());
		fps.setString(fpsString);
		fps.setCharacterSize(24);
		fps.setFillColor(sf::Color::White);
		window->draw(fps);
	}
}

void Graphic::showPlayerRenderInfo() {
	if (playerinfo) {
		float x = p->getPlayerRenderInfo().posX;
		float y = p->getPlayerRenderInfo().posY;
		string posInfoR = "Render Infomation: X = " + to_string(x) + " Y = " + to_string(y);
		playerRenderInfo.setString(posInfoR);
		playerRenderInfo.setCharacterSize(12);
		playerRenderInfo.setFillColor(sf::Color::White);
		playerRenderInfo.setPosition(0, 30);
		float posx = p->getPlayerPhysicsInfo().posX;
		float posy = p->getPlayerPhysicsInfo().posY;
		float velx = p->getPlayerPhysicsInfo().velX;
		float vely = p->getPlayerPhysicsInfo().velY;
		string posInfoP = "Physics Infomation: pos: X = " + to_string(posx) + " Y = " + to_string(posy)
			+ " vel: X = " + to_string(velx) + " Y = " + to_string(vely);
		playerPhysicsInfo.setString(posInfoP);
		playerPhysicsInfo.setCharacterSize(12);
		playerPhysicsInfo.setFillColor(sf::Color::White);
		playerPhysicsInfo.setPosition(0, 60);
		window->draw(playerRenderInfo);
		window->draw(playerPhysicsInfo);
	}
}


