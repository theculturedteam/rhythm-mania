#include "GameLogic.hpp"
#include "GameObjects.hpp"


GameLogic :: GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects)
    :msgBus(msgBus), gameObjects(gameObjects)
{}

GameLogic :: ~GameLogic()
{}


void GameLogic:: updateGameObjectsPosition()
{}
