#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include "draw.hpp"
struct Font{
    SDL_Texture* text;
    SDL_Rect position;
};

class Gui{
    SDL_Surface* sText;
    Draw& instance;
    public:
    Gui();
    void setPosition(int x, int y, int w, int h);
    void drawText();

};