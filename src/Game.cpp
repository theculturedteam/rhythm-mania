#include "Game.hpp"
#include "GameLogic.hpp"

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
    while(isRunning)
    {
        Time::sGetInstance().calculateDeltaTime();
        inputSystem.update();
        renderSystem.update();
        gameLogic.update();
    }
}