#include <SDL2/SDL_timer.h>
#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include "GameObjects.hpp"
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "data/inputData.hpp"
#include "framework/draw.hpp"
#include "system/inputSystem.hpp"
using namespace std;

MessageBus* msgBus = new MessageBus();
bool isRunning;
SDL_Window* window;
SDL_Renderer* renderer;

void init(const char* title, int xpos, int ypos, int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    if(!IMG_Init(IMG_INIT_PNG)){
        std::cout << "IMG INIT ERROR: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    isRunning = true;
    std::cout << "Game Started" << std::endl;
}

void quitSDL() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Ended" << std::endl;
}

void testInputSystem() {
	init("Game", 0, 40, 1280, 720);

	InputSystem inputSystem(msgBus);
	Time& timeInstance = Time::sGetInstance();
	timeInstance.setPreviousTime();
	std::cout << "Previous Time: " << timeInstance.getPreviousTime() << std::endl;

	while (isRunning) {
		double dt = timeInstance.calculateDeltaTime();
		std::cout << "dt: " << dt << std::endl;

		inputSystem.update();
		if (msgBus->hasMessage()) {
			Message* msg = msgBus->getMessage();
			InputData* inputData = msg->getInputData();
			if (inputData != nullptr) {
				/* std::cout << "keycode: " << inputData->getKeyCode() << " timestamp: " << inputData->getTimeStamp() << std::endl; */
				if (inputData->getKeyCode() == 0) {
					/* std::cout << "set game is running to false" << std::endl; */
					isRunning = false;
				}
			}
			delete msg;
			inputData = NULL;
		}
		SDL_Delay(16);
	}
	quitSDL();
}

int main(int argc, char* argv[]){
	(void) argc;
	(void) argv;

	testInputSystem();

	return 0;
}
