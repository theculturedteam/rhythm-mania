#include "data/videoData.hpp"
#include <cstdint>

VideoData::VideoData(std::string command, std::string videoDir, uint16_t noOfFrames, int videoSpeed)
	:command(command), videoDir(videoDir), noOfFrames(noOfFrames), videoSpeed(videoSpeed)
{}

std::string VideoData::getCommad() {
	return command;
}

std::string VideoData::getVideoDir() {
	return videoDir;
}

uint16_t VideoData::getNoOfFrames() {
	return noOfFrames;
}

int VideoData::getVideoSpeed() {
	return videoSpeed;
}

VideoData :: ~VideoData()
{
    std::cout << "Video data deleted" << std::endl;
}
