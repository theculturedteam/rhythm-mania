#include "data/videoData.hpp"
#include "system/videoSystem.hpp"
#include <iostream>

VideoSystem::VideoSystem(MessageBus* msgBus) 
	:System(msgBus)
{}

void VideoSystem::handleMessage() {
	if (msgBus->hasMessage() && msgBus->getMessageType() == "video") {
		Message* msg = msgBus->getMessage();
		VideoData* videoData = msg->getVideoData();

		if (videoData->getCommad() == "load") {
			if (videoData->getVideoDir() != "" &&
				videoData->getNoOfFrames() != 0 &&
				videoData->getVideoSpeed() != 0 &&
				videoData->getTextureWidth() != 0 &&
				videoData->getTextureHeight() != 0
				) 
			{
				videoDir = videoData->getVideoDir();
				noOfFrames = videoData->getNoOfFrames();
				videoSpeed = videoData->getVideoSpeed();
				textureWidth = videoData->getTextureWidth();
				textureHeight = videoData->getTextureHeight();

				for (int i= 1; i<= noOfFrames; i++) {
					SDL_Texture* texture = IMG_LoadTexture(drawInstance.getRenderer(), (videoDir + "/" + std::to_string(i) + ".jpeg").c_str());
					textures.push_back(texture);
				}

				/* SDL_QueryTexture(textures[0], NULL, NULL, &textureWidth, &textureHeight); */
			} else {
				std::cout << "Video System: One of the parameters required to load textures is not set" << std::endl;
			}
		} 
		else if (videoData->getCommad() == "play") {
			isPlaying = true;
		} 
		else if (videoData->getCommad() == "pause") {
			isPlaying = false;
		}
		else {
			std::cout << "Video System: Not a valid command" << std::endl;
		}

		delete msg;
		msg = NULL;
	}
	/* else { */
	/* 	std::cout << "Video System: Not a message of type video" << std::endl; */
	/* } */
}

void VideoSystem::update() {
	handleMessage();

	if (frame < noOfFrames && isPlaying) {
		SDL_RenderClear(drawInstance.getRenderer());

		drawInstance.setTexture(textures[frame]);


		SDL_Rect srcRect = {0, 0, textureWidth, textureHeight};
		SDL_Rect destRect = {0, 0, 1920, 1080};

		drawInstance.DrawTexture(srcRect, destRect);

		frame += videoSpeed * timeInstance.getDeltaTime();
        SDL_RenderPresent(drawInstance.getRenderer());
	}
}

VideoSystem::~VideoSystem() {
	for (SDL_Texture* texture : textures) {
		SDL_DestroyTexture(texture);
	}
    std::cout << "Texture deleted" << std::endl;
	textures.clear();
}
