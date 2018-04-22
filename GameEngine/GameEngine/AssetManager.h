#pragma once
#include <string>
#include <map>
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "EventSystem.h"
#include "Entity.h"
using namespace std;

class AssetManager {
public:
	enum AssetType {
		SOUND,
		MUSIC,
		TEXTURE,
		MESH,
		SHADER
	};
	AssetManager();
	~AssetManager();

	void* loadAsset(string path, AssetType type);
	void* getAsset(string path, AssetType type);
	bool isLoad(string path, AssetType type);
	void update();
	void handleEvent();
	bool deleteAsset(string path, AssetType type);
	void setEventSystem(EventSystem* es);

private:
	map<string, sf::SoundBuffer> soundBuffer;
	map<string, sf::Music> musicBuffer;
	map<string, sf::Texture> Texture;
	map<string, Entity*> Entity;
	//mesh map
};