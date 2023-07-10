#include "framework/draw.hpp"
#include <SDL_render.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void Draw ::InitializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        std::cout << "IMG INIT ERROR: " << SDL_GetError() << std::endl;
    }

    isRunning = true;
    window = SDL_CreateWindow("GAME", 0, 40, 1280, 720, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    std::cout << "Game Started" << std::endl;
}

void Draw ::DrawTexture(SDL_Rect srcRect, SDL_Rect dstRect)
{
	//SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
    //SDL_RenderPresent(renderer);
}

void Draw::DestroySDL()
{
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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

SDL_Texture* Draw::getTexture() {
	return texture;
}

SDL_Renderer* Draw::getRenderer() {
	return renderer;
}

void Draw::setTexture(SDL_Texture* texture) {
	this->texture = texture;
}
