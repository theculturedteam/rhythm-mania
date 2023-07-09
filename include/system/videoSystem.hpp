#pragma once
#include "System.hpp"
#include "MessageBus.hpp"
#include "framework/draw.hpp"
#include "framework/time.hpp"
#include <SDL_stdinc.h>
#include <vector>

class VideoSystem : public System {
	private:
		Draw& drawInstance = Draw::getInstance();
		Time& timeInstance = Time::sGetInstance();

		bool isPlaying = false;

		std::string videoDir = "";
		Uint16 noOfFrames = 0;
		int videoSpeed = 30;
		float frame = 0;

		int textureWidth = 0;
		int textureHeight = 0;

		std::vector<SDL_Texture*> textures;

	public:
		VideoSystem(MessageBus* msgBus);
		void handleMessage();
		~VideoSystem();
		void update();
};
