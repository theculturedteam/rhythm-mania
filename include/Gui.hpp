#pragma once
#include <SDL_ttf.h>
#include <SDL.h>

struct{
    SDL_Texture* text;
    SDL_Rect position;
};

class Gui{
    SDL_Surface* text;
    public:
    void setPosition(int x, int y, int w, int h);
    void drawText();
    
};