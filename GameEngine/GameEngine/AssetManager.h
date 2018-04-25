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
	//enum for asset type
	enum AssetType {
		SOUND,
		MUSIC,
		TEXTURE,
		MESH,
		FONT,
	};
	AssetManager();
	~AssetManager();

	//this function is for loading asset. if the asset is loaded, it will return a pointer to that asset.
	void* loadAsset(string path, AssetType type);
	//this function will return a pointer of asset if loaded
	void* getAsset(string path, AssetType type);
	//check whether the asset is loaded
	bool isLoad(string path, AssetType type);
	//update asset manager
	void update();
	//handle event
	void handleEvent(int eventType);
	//delete the asset of in the map
	bool deleteAsset(string path, AssetType type);
	//set the event system
	void setEventSystem(EventSystem* es);

private:
	EventSystem * es; //EventSystem pointer

	//map for buffers
	map<string, sf::SoundBuffer*> soundBuffer;
	map<string, sf::Music*> musicBuffer;
	map<string, sf::Texture*> texture;
	map<string, sf::Font*> fontBuffer;

};