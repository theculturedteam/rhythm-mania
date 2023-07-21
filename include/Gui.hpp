#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include "framework/draw.hpp"
#include "GameObjects.hpp"
struct Font{
    SDL_Texture* texture;
    SDL_Rect position;
};

class Gui{
    GameObject* textButton; 
    SDL_Surface* sText;
    Font font1;
    const char* text;
    TTF_Font* textFont;
    SDL_Color color;
    uint16_t index;
    Draw& instance = Draw::getInstance();
    public:
    Gui();
    GameObject* drawText(int xint, int yint, const char* text);
    GameObject* drawButton(int xint, int yint,const char* text);
    void freeTexture(int index);
};
