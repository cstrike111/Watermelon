#include "Animation.h"



Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::setTexture(sf::Texture * texture)
{
	this->texture = texture;
}

sf::IntRect Animation::playAnimation()
{
	//get the current frame
	sf::IntRect currentRect = getCurrentFrame();
	//go to next frame
	nextFrame();
	return currentRect;
}

sf::IntRect Animation::getCurrentFrame()
{
	frameInfo currentInfo = frame[currentFrame];
	sf::IntRect frameRect(currentInfo.x, currentInfo.y, frameWidth, frameHeight);
	return frameRect;
}

void Animation::nextFrame()
{
	currentFrame++;
	//if the index is bigger than the max index, go back to 0
	if(currentFrame >= maxFrame)
	{
		currentFrame = 0;
	}
}

void Animation::previousFrame()
{
	currentFrame--;
	//if the index is smaller than 0, stay at 0
	if (currentFrame < 0)
	{
		currentFrame = 0;
	}
}

void Animation::jumpToFrame(int index)
{
	if (index < maxFrame && index >= 0)
	{
		currentFrame = index;
	}
}

void Animation::createAnimation()
{
	int currentIndex = 0;
	int currentX = 0;
	int currentY = 0;
	for(int i = 0; i < frameRow; i++)
	{	//for every row
		//calculate the coordinate, reset x
		currentX = 0;
		currentY = i * frameHeight;
		for(int j = 0; j < frameColumn; j++)
		{
			//for every column, add the coordinate of the frame
			currentX = j * frameWidth;
			frame.push_back({(float) currentX,(float)currentY });
			//go to next frame
			currentIndex;
		}
	}
	//calculate the max frame
	maxFrame = frameRow * frameColumn;
}




