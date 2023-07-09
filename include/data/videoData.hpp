#pragma once
#include <cstdint>
#include <string>
#include <iostream>

class VideoData {
    public:
        VideoData(std::string command, std::string videoDir, uint16_t noOfFrames, int videoSpeed);
        ~VideoData();

		std::string getCommad();
		std::string getVideoDir();
		uint16_t getNoOfFrames();
		int getVideoSpeed();

    private:
		std::string command = "";
		std::string videoDir = "";
		uint16_t noOfFrames = 0;
		int videoSpeed = 0;
};
