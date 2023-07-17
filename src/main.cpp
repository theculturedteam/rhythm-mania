#include <iostream>
#include <SDL2/SDL.h>

#include "GameObjects.hpp"
#include "data/videoData.hpp"
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "data/inputData.hpp"
#include "framework/draw.hpp"
#include "system/InputSystem.hpp"
#include "system/VideoSystem.hpp"

MessageBus* msgBus = new MessageBus();

void testVideoSystem() {
	Draw& drawInstance = Draw::getInstance();
	Time& timeInstance = Time::sGetInstance();

	Message* msgLoadVideo = new Message("video");
	VideoData* loadVideo= new VideoData("load", "../res/videos/chika-dance", 2835, 30, 845, 480);
	msgLoadVideo->setData(loadVideo);
	msgBus->postMessage(msgLoadVideo);

	Message* msgPlayVideo = new Message("video");
	VideoData* playVideo = new VideoData("play");
	msgPlayVideo->setData(playVideo);
	msgBus->postMessage(msgPlayVideo);

	drawInstance.InitializeSDL();	
	VideoSystem videoSystem(msgBus);
	videoSystem.update();

	timeInstance.setPreviousTime();
    while (drawInstance.CheckRunning()) {
        timeInstance.calculateDeltaTime();

        drawInstance.HandleEvents();
    
        videoSystem.update();
    }
	delete msgBus;
	drawInstance.DestroySDL();
}

int main(int argc, char* argv[]){
	(void) argc;
	(void) argv;

	testVideoSystem();
	SDL_Delay(2000); // Delay for 2 seconds

	return 0;
}
