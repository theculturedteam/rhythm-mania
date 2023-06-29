#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>
class Draw{
    static const char* path;
    static SDL_Texture * texture;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool isRunning;
    public:
    static void sInitializeSDL();
    static void sDrawTexture(std::string path, SDL_Rect srcRect, SDL_Rect dstRect);
    static void DestroySDL();
    static void sHandleEvents();
    static bool sCheckRunning();
    // static void sFullScreenDraw(std::string path);
};