#include "Game.hpp"
#include "GameLogic.hpp"
#include "Gui.hpp"

Game :: Game()
    :renderSystem(&msgBus, &gameObjects), inputSystem(&msgBus), gameLogic(&msgBus, &gameObjects, &isRunning)
{
    isRunning = true;
}


Game :: ~Game()
{}

void Game :: run()
{
    Time::sGetInstance().setPreviousTime();
    testGui();
    while(isRunning)
    {
        Time::sGetInstance().calculateDeltaTime();
        inputSystem.update();
        renderSystem.update();
        gameLogic.update();
    }
}

void Game::testGui(){
	Gui gui;
	GameObject* text;
	text = gui.drawText(100, 100, 50 , 50, "hello");
    text->positionComponent->setDestRect(200, 200, 100, 100);
	gameObjects.push_back(text);
}