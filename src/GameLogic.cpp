#include "GameLogic.hpp"
#include <cstdint>
#define PERFECT 20
#define GOOD 50
#define BAD 70

GameLogic :: GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning)
    :msgBus(msgBus), gameObjects(gameObjects), beatVec(""), isRunning(isRunning)
{
}

void GameLogic :: start()
{
    velocity = 0.25;
    indexBeatVec = 0;
    indexBeatNo = 0;
    inputIndexBVec = 0;
    startTime = Time::sGetInstance().getCurrentTime();

    GameObject* arrow;

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AL1XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AD1XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AU1XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AR1XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    //Another player
    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AL2XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AD2XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AU2XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", nullptr);
    arrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
    arrow->positionComponent->setDestRect(AR2XPOS, AYPOS, 128, 128);
    gameObjects->push_back(arrow);

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

            if(temp.y + temp.h < 0)
            {
                gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gO), gameObjects->end());
                //std::cout << "Removed" << std::endl;
                delete gO;
            }
        }
    }
}


void GameLogic :: createArrowGObjects()
{
    uint32_t currentTime = Time::sGetInstance().getCurrentTime() - startTime;
    int baseDistance = 1070 - AYPOS;
    double eta = baseDistance / velocity;

    for(int i = 0; i <= 3; i++)
    {
        if(indexBeatNo > beatVec.beats.size() - 1)
        {
            break;
        }

        if(beatVec.beats[indexBeatNo]->size() == 0)
        {
            //indexBeatNo++;
            //indexBeatVec = 0;
            break;
        }

        if(indexBeatVec > beatVec.beats[indexBeatNo]->size() - 1)
        {
            indexBeatNo++;
            indexBeatVec = 0;
            break;
        }


        if(currentTime < (*beatVec.beats[indexBeatNo])[indexBeatVec]->beatTime - eta)
            break;


        //std::cout << "Current Time: " << currentTime << std::endl;
        //std::cout << "BeatVec time: " << beatVec.beat[indexBeatVec]->beatTime - eta << std::endl;
        GameObject* gameArrow = new GameObject("texture", "position", "movement", nullptr);
        gameArrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
        gameArrow->positionComponent->setDestRect(10, 1070, 128, 128);
        gameArrow->movementComponent->setVelocity(0, -velocity * 1000);
        gameObjects->push_back(gameArrow);
        indexBeatVec++;
        //std::cout << "Generated at " << Time::sGetInstance().getCurrentTime() << std::endl;

    }
}

void GameLogic :: handleInputs()
{
    while(msgBus->hasMessage() && msgBus->getMessageType() == "input")
    {
        uint32_t currentTime = Time::sGetInstance().getCurrentTime() - startTime;
        bool double_check = false;

        int check_direction = 0;
        auto rem = currentTime % 10000;
        if((rem >= 9880 || rem <= 120) && currentTime > 120)
        {
            double_check = true;
            if(rem >= 9880)
                check_direction = 1;
            else if (rem <= 120)
                check_direction = -1;

            //std::cout << currentTime << std::endl;
            //std::cout << "True" << std::endl;
        }

        inputIndexBVec = std::ceil(currentTime / 10000);

        Message* msg = msgBus->getMessage();
        InputData* in = msg->getInputData();

        if(in->getKeyCode() == 0)
        {
            *isRunning = false;
        }

        if(inputIndexBVec > beatVec.beats.size() - 1)
        {
            delete msg;
            return;
        }

        //std::cout << "in: " << in->getTimeStamp() - startTime << std::endl;

        for(auto bv : *beatVec.beats[inputIndexBVec])
        {
            uint32_t diff = 0;

            if(in->getKeyCode() != bv->keycode)
                break;

            if(bv->beatTime > in->getTimeStamp() - startTime)
            {
                diff = bv->beatTime - in->getTimeStamp() + startTime;
            }
            else if (in->getTimeStamp() - startTime > bv->beatTime)
            {
                diff = in->getTimeStamp() - startTime - bv->beatTime;
            }
            //std::cout << in->getKeyCode() << std::endl;
            //std::cout << diff << std::endl;


            if(diff < 100)
            {
                std::cout << "Got em" << std::endl;
                break;
            }
        }

        if(double_check)
        {

            if(inputIndexBVec + check_direction > beatVec.beats.size() - 1)
            {
                delete msg;
                return;
            }

            for(auto bv : *beatVec.beats[inputIndexBVec + check_direction])
            {
                uint32_t diff = 0;

                if(in->getKeyCode() != bv->keycode)
                    break;

                if(bv->beatTime > in->getTimeStamp() - startTime)
                {
                    diff = bv->beatTime - in->getTimeStamp() + startTime;
                }
                else
                {
                    diff = in->getTimeStamp() - bv->beatTime;
                }


                //std::cout << "in: " << in->getTimeStamp() - currentTime << std::endl;
                //std::cout<< "diff: " << diff << std::endl;
                if(diff < 100)
                {
                    std::cout << "Got em" << std::endl;
                    break;
                }
            }
            //std::cout << "Finished checking" << std::endl;
        }
        
        delete msg;
    }
}

void GameLogic :: update()
{
    createArrowGObjects();
    updateGObjectsPosition();
    handleInputs();
}
