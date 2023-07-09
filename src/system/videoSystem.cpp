#include <SDL_rect.h>
#include <SDL_render.h>
#include <string>
#include <iomanip>
#include "System.hpp"
#include "data/videoData.hpp"
#include "system/videoSystem.hpp"

VideoSystem::VideoSystem(MessageBus* msgBus) 
	:System(msgBus)
{}

void VideoSystem::handleMessage() {
	if (msgBus->hasMessage() && msgBus->getMessageType() == "video") {
		Message* msg = msgBus->getMessage();
		VideoData* videoData = msg->getVideoData();

		if (videoData->getCommad() == "load") {
			videoDir = videoData->getVideoDir();
			noOfFrames = videoData->getNoOfFrames();
			videoSpeed = videoData->getVideoSpeed();

			for (int i= 1; i<= noOfFrames; i++) {
				std::ostringstream oss;
        		oss << std::setw(5) << std::setfill('0') << i;
				SDL_Texture* texture = IMG_LoadTexture(drawInstance.getRenderer(), (videoDir + "/" + oss.str() + ".jpeg").c_str());
				textures.push_back(texture);
			}
			
			SDL_QueryTexture(textures[0], NULL, NULL, &textureWidth, &textureHeight);
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

	std::cout << "frame: " << frame << std::endl;
	std::cout << "noOfFrames: " << noOfFrames << std::endl;
	std::cout << "videoSpeed: " << videoSpeed << std::endl;

	if (frame < noOfFrames && isPlaying) {
		drawInstance.setTexture(textures[frame]);

        SDL_RenderClear(drawInstance.getRenderer());

		SDL_Rect srcRect = {0, 0, textureWidth, textureHeight};
		SDL_Rect destRect = {0, 0, 1920, 1080};

		drawInstance.DrawTexture(srcRect, destRect);

		//SDL_DestroyTexture(textures[frame]);

		frame += videoSpeed * timeInstance.getDeltaTime();
		std::cout << "deltaTime: " << timeInstance.getDeltaTime() << std::endl;
		std::cout << "frame: " << frame << std::endl;
        SDL_RenderPresent(drawInstance.getRenderer());
	}
}

VideoSystem::~VideoSystem() {
	for (SDL_Texture* texture : textures) {
		SDL_DestroyTexture(texture);
	}
    std::cout << "Texture deleted" << std::endl;
}
