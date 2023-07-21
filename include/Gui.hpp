#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include "draw.hpp"
#include "GameObjects.hpp"
struct Font{
    SDL_Texture* text;
    SDL_Rect position;
};

class Gui{
    GameObject* textButton; 
    SDL_Surface* sText;
    Font font1;
    TTF_Font* textFont;
    SDL_Color* 
    uint16_t index;
    Draw& instance = Draw::getInstance();
    public:
    void setPosition(int x, int y, int w, int h);
    GameObject* drawText();

};