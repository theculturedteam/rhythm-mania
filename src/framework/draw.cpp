#include "framework/draw.hpp"

Draw :: Draw(){
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.h = 32;
    srcRect.w = 32;
    dstRect.h = srcRect.h * 4;
    dstRect.w = srcRect.w * 4;
    std::cout<<"CREATED";
}

void Draw::sSetSrcRect(float x, float y){
    srcRect.x = x;
    srcRect.y = y;
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

void Draw :: sDrawTexture(std::string path){
    texture = IMG_LoadTexture(renderer, path.c_str()); // c_str to convert to char* from string
    SDL_RenderCopy(renderer, texture,&srcRect, &dstRect);
    SDL_RenderPresent(renderer);
}


void Draw ::sSetDstRect(float x, float y, float w, float h){
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = w;
    dstRect.h = h;    
}


void Draw :: sFullScreenDraw(std::string path){
    SDL_RenderGetViewport(renderer, &dstRect);
    sDrawTexture(path);
}