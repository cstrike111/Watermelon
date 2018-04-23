#include "AssetManager.h"

AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {
	//use for loop to clean every in the map
	soundBuffer.clear();
	musicBuffer.clear();
	texture.clear();
}

void* AssetManager::loadAsset(string path, AssetType type) {
	switch (type) {
	case AssetType::SOUND:
		//load sound
		if (soundBuffer.find(path) == soundBuffer.end()) {
			//if the sound is not in the buffer, load it
			sf::SoundBuffer* s = new sf::SoundBuffer();
			s->loadFromFile(path);
			soundBuffer["path"] = s;
			return soundBuffer["path"];
		}
		break;

	case AssetType::MUSIC:
		//load music
		if (musicBuffer.find(path) == musicBuffer.end()) {
			//if the music is not in the buffer, load it
			sf::Music* m = new sf::Music();
			m->openFromFile(path);
			musicBuffer["path"] = m;
			return musicBuffer["path"];
		}
		break;
	case AssetType::TEXTURE:
		//load Texture
		if (texture.find(path) == texture.end()) {
			//if the texture is not in the buffer, load it
			sf::Texture* t = new sf::Texture();
			t->loadFromFile(path);
			texture["path"] = t;
			return texture["path"];
		}
		break;
	case AssetType::FONT:
		//load font
		if (fontBuffer.find(path) == fontBuffer.end()) {
			//if the font is not in the buffer, load it
			sf::Font* f = new sf::Font();
			f->loadFromFile(path);
			fontBuffer["path"] = f;
			return fontBuffer["path"];
		}
		break;
	}
}

void* AssetManager::getAsset(string path, AssetType type) {
	switch (type) {
		//get the corresponding asset by path
	case AssetType::SOUND:
		return soundBuffer["path"];
		break;

	case AssetType::MUSIC:
		return musicBuffer["path"];
		break;

	case AssetType::TEXTURE:
		return texture["path"];
		break;

	case AssetType::FONT:
		return fontBuffer["path"];
		break;
	}
}

bool AssetManager::isLoad(string path, AssetType type) {
	switch (type) {
	case AssetType::SOUND:
		if (soundBuffer.find(path) != soundBuffer.end()) {
			return true;
		}
		break;

	case AssetType::MUSIC:
		if (musicBuffer.find(path) != musicBuffer.end()) {
			return true;
		}
		break;
	case AssetType::TEXTURE:
		if (texture.find(path) != texture.end()) {
			return true;
		}
		break;
	case AssetType::FONT:
		if (fontBuffer.find(path) != fontBuffer.end()) {
			return true;
		}
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
		//load sound
		if (soundBuffer.find(path) == soundBuffer.end()) {
			//if the sound is not in the buffer, load it
			sf::SoundBuffer* s = new sf::SoundBuffer();
			s->loadFromFile(path);
			soundBuffer["path"] = s;
			return soundBuffer["path"];
		}
		break;

	case AssetType::MUSIC:
		//load music
		if (musicBuffer.find(path) == musicBuffer.end()) {
			//if the music is not in the buffer, load it
			sf::Music* m = new sf::Music();
			m->openFromFile(path);
			musicBuffer["path"] = m;
			return musicBuffer["path"];
		}
		break;
	case AssetType::TEXTURE:
		//load Texture
		if (texture.find(path) == texture.end()) {
			//if the texture is not in the buffer, load it
			sf::Texture* t = new sf::Texture();
			t->loadFromFile(path);
			texture["path"] = t;
			return texture["path"];
		}
		break;
	case AssetType::FONT:
		//load font
		if (fontBuffer.find(path) == fontBuffer.end()) {
			//if the font is not in the buffer, load it
			sf::Font* f = new sf::Font();
			f->loadFromFile(path);
			fontBuffer["path"] = f;
			return fontBuffer["path"];
		}
		break;
	}
}

void AssetManager::setEventSystem(EventSystem* es) {
	this->es = es;
}

