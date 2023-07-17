#pragma once
#include "GameObjects.hpp"
#include "framework/draw.hpp"
#include "system.hpp"
#include "MessageBus.hpp"


class Render:public System{
    SDL_Rect src,dst;
    int index;
    std::vector<GameObject*>* gameObjects;  
    Draw& instance = Draw::getInstance(); 
    public:
    Render(MessageBus* msgbus, std::vector<GameObject*>* gameobjects);
    void handleMessage(){};
    void update();  //updates the game objects on the screen
    ~Render();
};