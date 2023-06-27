#include "framework/draw.hpp"

void Draw::sSetTexture(float x, float y,  std::string path){
    srcRect.x = x;
    srcRect.y = y;
    path = path.c_str(); 
    std::cout<<"CREATED";
}

//temporary function for test
void Draw :: sInitializeSDL(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
    }

    if(!IMG_Init(IMG_INIT_PNG)){
        std::cout << "IMG INIT ERROR: " << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow("GAME", 0, 40, 1280, 720, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    std::cout << "Game Started" << std::endl;
    
}

void Draw :: sDrawTexture(float x_pos, float y_pos){
    dstRect.x = x_pos;
    dstRect.y = y_pos;
    texture = IMG_LoadTexture(renderer, path);
    SDL_RenderCopy(renderer, texture,&srcRect, &dstRect);
    SDL_RenderPresent(renderer);
}