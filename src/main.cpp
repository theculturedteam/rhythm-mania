#include <iostream>
#include "framework/time.hpp"
#include "framework/draw.hpp"
int main(int argc,  char* argv[]) {

	(void) argc;
    (void) argv;

	std::cout << "Hello from main" << std::endl;

	Time *time = new Time();
	
	Draw::sInitializeSDL();
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	srcRect.w = 32;
	srcRect.h = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	dstRect.w = 64;
	dstRect.h = 64;
	dstRect.x = 300;
	dstRect.y = 400;
	bool isRunning = Draw::sCheckRunning();
	while (isRunning)
	{
		Draw::sHandleEvents();
		Draw::sDrawTexture("../res/images/healthbar1.png", srcRect, dstRect);
		isRunning = Draw::sCheckRunning();
	}
	Draw::DestroySDL();
	time->hello();

	return 0;
}
