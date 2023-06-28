#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>
class Draw{
    static SDL_Rect srcRect, dstRect;
    static const char* path;
    static SDL_Texture * texture;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    public:
    Draw();
    static void sInitializeSDL();
    static void sSetSrcRect(float x, float y); 
    static void sDrawTexture(std::string path);
    static void sSetDstRect(float x, float y,float w, float h);
    static void sFullScreenDraw(std::string path);
};