#include "GameLogic.hpp"
#include "GameObjects.hpp"


GameLogic :: GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects)
    :msgBus(msgBus), gameObjects(gameObjects), beatMap("")
{
    Time &t = Time::sGetInstance();
    startTime = t.getCurrentTime();
}

GameLogic :: ~GameLogic()
{}


void GameLogic :: updateGameObjectsPosition()
{}


void GameLogic :: createArrowGObjects()
{}

void GameLogic :: handleInputs()
{}

void GameLogic :: update()
{}
