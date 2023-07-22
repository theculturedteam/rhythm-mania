#pragma once
#include <iostream>
#include <cstdint>

class PlayData
{
    public:
        PlayData(float velocity, std::string title, std::string soundPath, std::string videoDir, std::string beatMapDir, uint16_t noOfFrames, int videoSpeed, int textureWidth, int textureHeight);
        ~PlayData();

        float velocity;
        std::string title;
        std::string soundPath;
        std::string videoDir;
		std::string beatMapDir;
        uint16_t noOfFrames;
        int videoSpeed;
        int textureWidth;
        int textureHeight;
};
