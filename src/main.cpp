#include <SDL2/SDL_timer.h>
#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include "GameObjects.hpp"
#include "data/videoData.hpp"
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "data/inputData.hpp"
#include "framework/draw.hpp"
#include "system/inputSystem.hpp"
#include "system/videoSystem.hpp"
using namespace std;

MessageBus* msgBus = new MessageBus();

void testVideoSystem() {
	Draw& drawInstance = Draw::getInstance();
	Time& timeInstance = Time::sGetInstance();

	Message* msgLoadVideo = new Message("video");
	VideoData* loadVideo= new VideoData("load", "../res/videos/chika-dance", 2835, 90);
	msgLoadVideo->setData(loadVideo);
	msgBus->postMessage(msgLoadVideo);

	Message* msgPlayVideo = new Message("video");
	VideoData* playVideo = new VideoData("play", "../res/videos/chika-dance", 2835, 30);
	msgPlayVideo->setData(playVideo);
	msgBus->postMessage(msgPlayVideo);

	drawInstance.InitializeSDL();	
	VideoSystem videoSystem(msgBus);
	videoSystem.update();

	timeInstance.setPreviousTime();
	while (drawInstance.CheckRunning()) {
		timeInstance.calculateDeltaTime();
		timeInstance.setPreviousTime();

		drawInstance.HandleEvents();
	
		videoSystem.update();
	}
	drawInstance.DestroySDL();
}
int main(int argc, char* argv[]){
	(void) argc;
	(void) argv;

	testVideoSystem();

	return 0;
}
