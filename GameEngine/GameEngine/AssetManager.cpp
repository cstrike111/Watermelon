#include "AssetManager.h"

AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {
	//clean sound buffer
	//delete contains in the map
	for (map<string, sf::SoundBuffer*>::iterator it = soundBuffer.begin(); it != soundBuffer.end(); it++) {
		delete it->second;
	}
	//clear the map
	soundBuffer.clear();

	//clean music buffer
	//delete contains in the map
	for (map<string, sf::Music*>::iterator it = musicBuffer.begin(); it != musicBuffer.end(); it++) {
		delete it->second;
	}
	//clear the map
	musicBuffer.clear();

	//clean texture
	//delete contains in the map
	for (map<string, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++) {
		delete it->second;
	}
	//clear the map
	texture.clear();

	//clean font
	//delete contains in the map
	for (map<string, sf::Font*>::iterator it = fontBuffer.begin(); it != fontBuffer.end(); it++) {
		delete it->second;
	}
	//clear the map
	fontBuffer.clear();
}

void* AssetManager::loadAsset(string path, AssetType type) {
	switch (type) {
	case AssetType::SOUND:
		//load sound
		if (soundBuffer.find(path) == soundBuffer.end()) {
			//if the sound is not in the buffer, load it
			sf::SoundBuffer* s = new sf::SoundBuffer();
			s->loadFromFile(path);
			soundBuffer[path] = s;
			return static_cast<sf::SoundBuffer*>(soundBuffer[path]);
		}
		else {
			//else, return the point 
			return static_cast<sf::SoundBuffer*>(soundBuffer[path]);
		}
		break;

	case AssetType::MUSIC:
		//load music
		if (musicBuffer.find(path) == musicBuffer.end()) {
			//if the music is not in the buffer, load it
			sf::Music* m = new sf::Music();
			m->openFromFile(path);
			musicBuffer[path] = m;
			return static_cast<sf::Music*> (musicBuffer[path]);
		}
		else {
			//else, return the point 
			return static_cast<sf::Music*> (musicBuffer[path]);
		}
		break;

	case AssetType::TEXTURE:
		//load Texture
		if (texture.find(path) == texture.end()) {
			//if the texture is not in the buffer, load it
			sf::Texture* t = new sf::Texture();
			t->loadFromFile(path);
			texture[path] = t;
			return texture[path];
		}
		else {
			//else, return the point 
			return static_cast<sf::Texture*> (texture[path]);
		}
		break;

	case AssetType::FONT:
		//load font
		if (fontBuffer.find(path) == fontBuffer.end()) {
			//if the font is not in the buffer, load it
			sf::Font* f = new sf::Font();
			f->loadFromFile(path);
			fontBuffer[path] = f;
			return fontBuffer[path];
		}
		else {
			//else, return the point 
			return static_cast<sf::Font*> (fontBuffer[path]);
		}
		break;

	default:
		return nullptr;
		break;
	}
}

void* AssetManager::getAsset(string path, AssetType type) {
	switch (type) {
		//get the corresponding asset by path
		//first, find whether the file is loaded
		//yes -> return the pointer, no -> return a null pointer
	case AssetType::SOUND:
		if (soundBuffer.find(path) != soundBuffer.end()) {
			return static_cast<sf::SoundBuffer*>(soundBuffer[path]);
		}
		else {
			cout << "Oops! There is no " << path << "." <<endl;
			return nullptr;
		}
		break;

	case AssetType::MUSIC:
		if (musicBuffer.find(path) != musicBuffer.end()) {
			return musicBuffer[path];
		}
		else {
			cout << "Oops! There is no " << path << "." << endl;
			return nullptr;
		}
		break;

	case AssetType::TEXTURE:
		if (texture.find(path) != texture.end()) {
			return texture[path];
		}
		else {
			cout << "Oops! There is no " << path << "." << endl;
			return nullptr;
		}
		break;

	case AssetType::FONT:
		if (fontBuffer.find(path) != fontBuffer.end()) {
			return fontBuffer[path];
		}
		else {
			cout << "Oops! There is no " << path << "." << endl;
			return nullptr;
		}
		break;
	default:
		break;
	}
}

bool AssetManager::isLoad(string path, AssetType type) {
	//find the corresponding asset by path and tell the caller whether the asset is loaded
	switch (type) {
	case AssetType::SOUND:
		if (soundBuffer.find(path) != soundBuffer.end()) {
			return true;
		}
		else {
			return false;
		}
		break;

	case AssetType::MUSIC:
		if (musicBuffer.find(path) != musicBuffer.end()) {
			return true;
		}
		else {
			return false;
		}
		break;
	case AssetType::TEXTURE:
		if (texture.find(path) != texture.end()) {
			return true;
		}
		else {
			return false;
		}
		break;
	case AssetType::FONT:
		if (fontBuffer.find(path) != fontBuffer.end()) {
			return true;
		}
		else {
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}

void AssetManager::update() {
	//check the queue
	if (es->getEventQueue()->size() != 0) {
		if (es->getEventQueue()->front().getSubSystem(Event::subsystem::ASSETMANAGER)) {
			//handle event
			handleEvent(es->getEventQueue()->front().getEventType());
			//tell the event that the sub-system has finished its job
			es->getEventQueue()->front().popAssetManager();
		}
	}
}

void AssetManager::handleEvent(int eventType) {
	switch (eventType) {
	default:
		break;
	}
}

bool AssetManager::deleteAsset(string path, AssetType type) {
	switch (type) {
	case AssetType::SOUND:
		//sound
		if (soundBuffer.find(path) != soundBuffer.end()) {
			//delete the contain
			delete soundBuffer[path];
			//delete the pointer
			soundBuffer.erase(path);
			return true;
		}
		else {
			return false;
		}
		break;

	case AssetType::MUSIC:
		//music
		if (musicBuffer.find(path) != musicBuffer.end()) {
			//delete the contain
			delete musicBuffer[path];
			//delete the pointer
			musicBuffer.erase(path);
			return true;
		}
		else {
			return false;
		}
		break;
	case AssetType::TEXTURE:
		//texture
		if (texture.find(path) != texture.end()) {
			//delete the contain
			delete texture[path];
			//delete the pointer
			texture.erase(path);
			return true;
		}
		else {
			return false;
		}
		break;
	case AssetType::FONT:
		//font
		if (fontBuffer.find(path) == fontBuffer.end()) {
			//delete the contain
			delete fontBuffer[path];
			//delete the pointer
			fontBuffer.erase(path);
			return true;
		}
		else {
			return false;
		}
		break;
	default:
		return false;
		break;
	}

}

void AssetManager::setEventSystem(EventSystem* es) {
	this->es = es;
}

