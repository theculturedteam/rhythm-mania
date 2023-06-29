#include <SDL_timer.h>
#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include "framework/time.hpp"

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;
    
	Time* timeInstance = Time::sGetInstance();

	timeInstance->setPreviousTime(timeInstance->getCurrentTime());

	std::cout << "Previous Time: " << timeInstance->getPreviousTime() << std::endl;

	while (true) {
		std::cout << "DT: " << timeInstance->calculateDeltaTime(timeInstance->getCurrentTime()) << std::endl;
		printf("dt: %f", timeInstance->calculateDeltaTime(timeInstance->getCurrentTime()));
		SDL_Delay(10000);
		timeInstance->setPreviousTime(timeInstance->getCurrentTime());
	}

    return 0;
}

