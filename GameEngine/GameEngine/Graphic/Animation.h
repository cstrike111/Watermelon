#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class Animation
{
public:
	struct frameInfo
	{
		float x;
		float y;
	};

	Animation();
	~Animation();

	//information of frames
	float frameWidth = 0;
	float frameHeight = 0;
	int frameRow = 0;
	int frameColumn = 0;
	int maxFrame = 0;
	int currentFrame = 0;
	sf::Texture* texture;
	std::vector<frameInfo> frame;

	//functions
	//set texture, texture of the sprite will be handled by animation class
	void setTexture(sf::Texture* texture);
	//play animation
	sf::IntRect playAnimation();
	//get the current frame
	sf::IntRect getCurrentFrame();
	//go to next frame
	void nextFrame();
	//go to previous frame
	void previousFrame();
	//jump to specific index of frame
	void jumpToFrame(int index);
	//create animation, configurate corrently and call this before using the animation 
	void createAnimation();

};

