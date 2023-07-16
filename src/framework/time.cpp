#include <SDL2/SDL_timer.h>
#include <cstdint>
#include <iostream>
#include "framework/time.hpp"

Time& Time::sGetInstance() {
	static Time timeInstance; //Guaranteed to be destroyed
							  //Instantiated on first use
	return timeInstance;
}

void Time::setPreviousTime() {
	previousTime = getCurrentTime();
}

double Time::calculateDeltaTime() {
	curretTime = getCurrentTime();
	deltaTime = (curretTime - previousTime) / 1000.0;
    previousTime = getCurrentTime();
	return deltaTime;
}

uint32_t Time::getPreviousTime() {
	return previousTime;
}

uint32_t Time::getCurrentTime() {
	return SDL_GetTicks();
}

double Time::getDeltaTime() {
	return deltaTime;
}
