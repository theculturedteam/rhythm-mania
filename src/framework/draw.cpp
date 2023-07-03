#include "framework/draw.hpp"

bool Draw::isRunning;
const char* Draw::path = "";
SDL_Texture* Draw::texture = nullptr;
SDL_Window* Draw::window = nullptr;
SDL_Renderer* Draw::renderer = nullptr;
Draw* Draw::instanceptr;


void Draw :: sInitializeSDL(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
    }

    if(!IMG_Init(IMG_INIT_PNG)){
        std::cout << "IMG INIT ERROR: " << SDL_GetError() << std::endl;
    }
    isRunning = true;
    window = SDL_CreateWindow("GAME", 0, 40, 1280, 720, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    std::cout << "Game Started" << std::endl; 
}

void Draw :: sDrawTexture(std::string path, SDL_Rect srcRect, SDL_Rect dstRect){
    texture = IMG_LoadTexture(renderer, path.c_str()); // c_str to convert to char* from string
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
    SDL_RenderPresent(renderer);
}

void Draw::DestroySDL(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

Draw* Draw::getInstance(){
    {
        if(instanceptr == NULL){
            instanceptr = new Draw();
            return instanceptr;
        }
        return instanceptr;
    }
}

void Draw::sHandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

bool Draw::sCheckRunning(){
    std::cout<< isRunning<< std::endl;
    return isRunning;
}


void Draw :: sFullScreenDraw(std::string path, SDL_Rect srcRect, SDL_Rect dstRect){
    SDL_RenderGetViewport(renderer, &dstRect);
    sDrawTexture(path, srcRect, dstRect);
}