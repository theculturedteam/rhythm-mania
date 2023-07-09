#pragma once
#include <SDL2/SDL.h>

class Time {
	private:
		// member variable
		uint32_t previousTime;
		uint32_t curretTime;
		double deltaTime;

		Time() {};

	public: 
		// deleting methods we dont want like construtor and operator
		Time(Time const&) = delete;
		void operator=(Time const&) = delete;

		static Time& sGetInstance();

		void setPreviousTime();
		double calculateDeltaTime();

		uint32_t getPreviousTime();
		uint32_t getCurrentTime();
		double getDeltaTime();
};
