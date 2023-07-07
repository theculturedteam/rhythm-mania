#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>
//to load and draw different textures on the screen
class Draw{
    const char* path;
    SDL_Texture * texture;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    static Draw& instanceptr;
    Draw(){};
    public:
    Draw(const Draw& obj) = delete;
    void operator=(Draw const&)  = delete;
    static Draw& getInstance();
    void InitializeSDL();
    void DrawTexture(SDL_Rect srcRect, SDL_Rect dstRect);
    void DestroySDL();
    void HandleEvents();
    void LoadTexture(std::string);
    bool CheckRunning();
};