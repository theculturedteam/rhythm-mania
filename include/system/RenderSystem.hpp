#pragma once
#include "GameObjects.hpp"
#include "framework/draw.hpp"
#include "system.hpp"
#include "MessageBus.hpp"


class Render:public System{
    int noOfFrames; //to count the number of frames in animation
    PositionAndDimensionStruct srcRect; //gameobjects's global data type struct
    PositionAndDimensionStruct dstRect;
    SDL_Rect src,dst;
    std::vector<GameObject*>* gameObjects;  
    Draw& instance = Draw::getInstance(); 
    void convert(PositionAndDimensionStruct srcRect, PositionAndDimensionStruct dstRect); // convert struct to SDL_rect type for draw framework
    public:
    Render(MessageBus* msgbus, std::vector<GameObject*>* gameobjects);
    void handleMessage(){};
    void update();  //updates the game objects on the screen
    ~Render();
};