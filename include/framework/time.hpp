#pragma once
#include <SDL2/SDL.h>
#include <SDL_stdinc.h>

class Time {
	private:
		// member variable
		Uint32 previousTime;

		// static pointer which will point to
		// the instance of this class
		static Time* sTimeInstancePtr;

		Time() {};

	public: 
		// deleting copy constructor
		Time(const Time& obj) = delete;

		static Time* sGetInstance();
		void setPreviousTime(uint32_t previousTime);
		uint32_t getPreviousTime();
		uint32_t getCurrentTime();
		double calculateDeltaTime(uint32_t curretTime);
};
