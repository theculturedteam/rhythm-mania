#include <SDL2/SDL_timer.h>
#include <cstdint>
#include <iostream>
#include "framework/time.hpp"

Time& Time::sGetInstance() {
	static Time timeInstance; //Guaranteed to be destroyed
							  //Instantiated on first use
	return timeInstance;
}

void Time::setPreviousTime(uint32_t previousTime) {
	this->previousTime = previousTime;
}

double Time::calculateDeltaTime(uint32_t curretTime) {
	double dt = (curretTime - previousTime) / 1000.0;
	previousTime = curretTime;
	return dt;
}

uint32_t Time::getPreviousTime() {
	return previousTime;
}

uint32_t Time::getCurrentTime() {
	return SDL_GetTicks();
}

