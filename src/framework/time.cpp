#include <SDL_timer.h>
#include <iostream>
#include "framework/time.hpp"

Uint32 Time::sGetTime() {
	return SDL_GetTicks();
}
