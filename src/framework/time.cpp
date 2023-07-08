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
	double dt = (curretTime - previousTime) / 1000.0;
	return dt;
}

uint32_t Time::getPreviousTime() {
	return previousTime;
}

uint32_t Time::getCurrentTime() {
	return SDL_GetTicks();
}

