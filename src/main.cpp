#include <iostream>
#include "framework/time.hpp"
#include "framework/draw.hpp"
int main(int argc,  char* argv[]) {

	(void) argc;
    (void) argv;

	std::cout << "Hello from main" << std::endl;

	Time *time = new Time();
	
	Draw* singleton = Draw::getInstance();
	singleton->sInitializeSDL();
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
	
	bool isRunning = singleton->sCheckRunning();
	while (isRunning)
	{
		singleton->sHandleEvents();
		//singleton->sFullScreenDraw("../res/images/healthbar1.png", srcRect, dstRect);
		singleton->sDrawTexture("../res/images/healthbar1.png", srcRect, dstRect);
		isRunning = singleton->sCheckRunning();
	}
	singleton->DestroySDL();
	time->hello();

	return 0;
}
