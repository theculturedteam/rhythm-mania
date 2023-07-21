#pragma once
#include "GameObjects.hpp"
#include "framework/draw.hpp"
#include "framework/time.hpp"
#include "system/System.hpp"
#include "MessageBus.hpp"


class Render:public System{
	private:
    	SDL_Rect src,dst;
    	int index = 0;
    	std::vector<GameObject*>* gameObjects;  
    	Draw& instance = Draw::getInstance(); 
		Time& timeInstance = Time::sGetInstance();

    public:
    	Render(MessageBus* msgbus, std::vector<GameObject*>* gameobjects);
		~Render();
    	void handleMessage(){};
    	void update();  //updates the game objects on the screen
};
