#include "data/playData.hpp"

PlayData :: PlayData(float velocity, std::string title, std::string soundPath, std::string videoDir, std::string beatMapDir, uint16_t noOfFrames, int videoSpeed, int textureWidth, int textureHeight)
{
    this->velocity = velocity;
    this->title = title;
    this->soundPath = soundPath;
    this->videoDir = videoDir;
	this->beatMapDir = beatMapDir;
    this->noOfFrames = noOfFrames;
    this->videoSpeed = videoSpeed;
    this->textureWidth = textureWidth;
    this->textureHeight = textureHeight;
}

PlayData :: ~PlayData()
{}
