#include <iostream>
#include "framework/time.hpp"
#include "framework/draw.hpp"
int main(int argc, char *argv[])
{

    (void)argc;
    (void)argv;

    std::cout << "Hello from main" << std::endl;

    Time *time = new Time();

    Draw &singleton = Draw::getInstance();

    singleton.InitializeSDL();

    SDL_Rect srcRect;
    SDL_Rect dstRect;
    srcRect.w = 371;
    srcRect.h = 403;
    srcRect.x = 0;
    srcRect.y = 0;
    dstRect.w = 64;
    dstRect.h = 64;
    dstRect.x = 500;
    dstRect.y = 500;

    bool isRunning = singleton.CheckRunning();
    singleton.ClearTexture();
    singleton.LoadTexture("../res/images/arrow_left.png");
    while (isRunning)
    {
        singleton.CopyTexture(srcRect, dstRect);
        singleton.PresentTexture();
        singleton.HandleEvents();
        isRunning = singleton.CheckRunning();
    }
    singleton.DestroySDL();
    time->hello();
    return 0;
}
