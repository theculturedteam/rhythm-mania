#include "Game.hpp"
#include "GameLogic.hpp"

Game ::Game()
    : renderSystem(&msgBus, &gameObjects), inputSystem(&msgBus), gameLogic(&msgBus, &gameObjects, &isRunning), soundSystem(&msgBus)
{
    isRunning = true;
}

Game ::~Game()
{
}

void Game ::run()
{
    gameLogic.start();
    Time::sGetInstance().setPreviousTime();
    while (isRunning)
    {
        Time::sGetInstance().calculateDeltaTime();
        std::cout << "dt: " << Time::sGetInstance().getDeltaTime() << std::endl;
        inputSystem.update();
        renderSystem.update();
        soundSystem.update();
        gameLogic.update();
    }
}
