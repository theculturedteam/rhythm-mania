#include "GameLogic.hpp"
#include "GameObjects.hpp"


GameLogic :: GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects)
    :msgBus(msgBus), gameObjects(gameObjects), beatMap("")
{
    startTime = Time::sGetInstance().getCurrentTime();
}

GameLogic :: ~GameLogic()
{}


void GameLogic :: updateGObjectsPosition()
{
    for(GameObject* gO : *gameObjects)
    {
        if(gO->movementComponent != nullptr && gO->positionComponent != nullptr)
        {
            double dt = Time::sGetInstance().calculateDeltaTime();
            PositionAndDimensionStruct temp = gO->positionComponent->getDestRect();
            temp.x += gO->movementComponent->getXVelocity() * dt;
            temp.y += gO->movementComponent->getYVelocity() * dt;
            gO->positionComponent->setDestRect(temp.x, temp.y, temp.w, temp.h);
        }
    }
}


void GameLogic :: createArrowGObjects()
{
    uint32_t currentTime = startTime - Time::sGetInstance().getCurrentTime();
    int baseDistance = 1080 - APOS;
    double eta = baseDistance / velocity;
    eta = eta + currentTime + 1000;
    (void) eta;

}

void GameLogic :: handleInputs()
{}

void GameLogic :: update()
{}
