#include "framework/draw.hpp"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void Draw ::InitializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG INIT ERROR: " << SDL_GetError() << std::endl;
    }
    isRunning = true;
    window = SDL_CreateWindow("GAME", 0, 40, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    std::cout << "Game Started" << std::endl;
}

void Draw ::DrawTexture(SDL_Rect srcRect, SDL_Rect dstRect)
{
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
    SDL_RenderPresent(renderer);
}

void Draw::DestroySDL()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

Draw &Draw::getInstance()
{
    static Draw instanceptr;
    return instanceptr;
}

void Draw::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

bool Draw::CheckRunning()
{
    return isRunning;
}


void Draw::LoadTexture(std::string path){
    texture = IMG_LoadTexture(renderer, path.c_str()); // c_str to convert to char* from string
}