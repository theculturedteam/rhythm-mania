#include <SDL_timer.h>
#include <cstdint>
#include <iostream>
#include "framework/time.hpp"

Time* Time::sTimeInstancePtr = NULL;

//getInstance() is a static method that returns an instance when it is invoked. 
//It returns the same instance if it is invoked more than once as an instance
Time* Time::sGetInstance() {
	// If there is no instance of this class them we create an instance
	if (sTimeInstancePtr == NULL) {
		sTimeInstancePtr = new Time();

		return sTimeInstancePtr;
	}
	else {
		// If sTimeInstancePtr != NULL that means the class already has an instance.
		// So, we just return that instance
		return sTimeInstancePtr;
	}
}

void Time::setPreviousTime(uint32_t previousTime) {
	this->previousTime = previousTime;
}

uint32_t Time::getPreviousTime() {
	return previousTime;
}

uint32_t Time::getCurrentTime() {
	return SDL_GetTicks();
}

double Time::calculateDeltaTime(uint32_t curretTime) {
	return ((curretTime - previousTime) / 1000.0);
}
