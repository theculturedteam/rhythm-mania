#pragma once
#include "System.hpp"
#include "MessageBus.hpp"
#include "framework/draw.hpp"
#include "framework/time.hpp"
#include <vector>

class VideoSystem : public System {
	private:
		Draw& drawInstance = Draw::getInstance();
		Time& timeInstance = Time::sGetInstance();

		bool isPlaying = false;

		std::string videoDir = "";
		uint16_t noOfFrames = 0;
		int videoSpeed = 0;
		int textureWidth = 0;
		int textureHeight = 0;

		float frame = 0;

		std::vector<SDL_Texture*> textures;

	public:
		VideoSystem(MessageBus* msgBus);
		~VideoSystem();
		void handleMessage();
		void update();
};
