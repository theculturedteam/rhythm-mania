#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>
class Draw{
    static float x_pos, y_pos; //where texture is on screen
    static SDL_Rect srcRect, dstRect;
    static const char* path;
    static SDL_Texture * texture;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    public:
    static void sInitializeSDL();
    static void sSetTexture(float x, float y, std::string path);
    static void sDrawTexture(float x_pos, float y_pos);
};