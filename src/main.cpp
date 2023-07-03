#include <SDL2/SDL_timer.h>
#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include "framework/time.hpp"

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;

	SDL_Init(SDL_INIT_TIMER);
    
	Time& timeInstance = Time::sGetInstance();

	timeInstance.setPreviousTime(timeInstance.getCurrentTime());

	std::cout << "Previous Time: " << timeInstance.getPreviousTime() << std::endl;

	while (true) {
		double dt = timeInstance.calculateDeltaTime(timeInstance.getCurrentTime());
		std::cout << "dt: " << dt << std::endl;
		SDL_Delay(16);
	}

    return 0;
}

