#include "GameLogic.hpp"
#include "GameObjects.hpp"


GameLogic :: GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning)
    :msgBus(msgBus), gameObjects(gameObjects), beatVec(""), isRunning(isRunning)
{
    velocity = 0.25;
    indexBeatVec = 0;
    startTime = Time::sGetInstance().getCurrentTime();
    GameObject* arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 403, 370);
    arrow->positionComponent->setDestRect(10, 80, 403 / 3, 370 / 3);
    gameObjects->push_back(arrow);

    //GameObject* ar = new GameObject("texture", "position", "movement", nullptr);
    //ar->texturePositionComponent->setSrcRect(0, 0, 403, 370);
    //ar->positionComponent->setDestRect(40, 80, 403 / 3, 370 / 3);
    //ar->movementComponent->setVelocity(0, -10);
    //gameObjects->push_back(ar);
}

GameLogic :: ~GameLogic()
{}


void GameLogic :: updateGObjectsPosition()
{
    for(GameObject* gO : *gameObjects)
    {
        if(gO->movementComponent != nullptr && gO->positionComponent != nullptr)
        {
            double dt = Time::sGetInstance().getDeltaTime();
            PositionAndDimensionStruct& temp = gO->positionComponent->getDestRect();
            temp.x += gO->movementComponent->getXVelocity() * dt;
            temp.y += gO->movementComponent->getYVelocity() * dt;
            gO->positionComponent->setDestRect(temp.x, temp.y, temp.w, temp.h);
        }
    }
}


void GameLogic :: createArrowGObjects()
{
    uint32_t currentTime = Time::sGetInstance().getCurrentTime() - startTime;
    int baseDistance = 1070 - APOS;
    double eta = baseDistance / velocity;
    if(indexBeatVec < beatVec.beat.size())
    {
        if(currentTime >= beatVec.beat[indexBeatVec]->beatTime - eta)
        {
            std::cout << "Current Time: " << currentTime << std::endl;
            std::cout << "BeatVec time: " << beatVec.beat[indexBeatVec]->beatTime - eta << std::endl;
            GameObject* gameArrow = new GameObject("texture", "position", "movement", nullptr);
            gameArrow->texturePositionComponent->setSrcRect(0, 0, 403, 370);
            gameArrow->positionComponent->setDestRect(10, 1070, 403 / 3, 370 / 3);
            gameArrow->movementComponent->setVelocity(0, -velocity * 1000);
            gameObjects->push_back(gameArrow);
            indexBeatVec++;
            //std::cout << "Generated at " << Time::sGetInstance().getCurrentTime() << std::endl;
        }
    }

}

void GameLogic :: handleInputs()
{
    if(msgBus->hasMessage())
    {
        if(msgBus->getMessageType() == "input")
        {
            Message* msg = msgBus->getMessage();
            InputData* in = msg->getInputData();
            if(in->getKeyCode() == 0)
            {
                *isRunning = false;
            }
            delete msg;
        }
    }
}

void GameLogic :: update()
{
    createArrowGObjects();
    updateGObjectsPosition();
    handleInputs();
}
