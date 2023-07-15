#include "Game.hpp"

Game :: Game()
    :inputSystem(&msgBus), gameLogic(&msgBus, &gameObjects)
{}


Game :: ~Game()
{}

void Game :: run()
{
}
