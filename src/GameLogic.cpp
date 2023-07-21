#include "GameLogic.hpp"
#include "Message.hpp"
#include "data/SoundData.hpp"
#include "data/videoData.hpp"
#include <cstring>
#include <string>
#define PERFECT 50 //300 score
#define GOOD 100 //100
#define BAD 250 //50

class Coordinate
{
    public:
        int src_x, src_y, dest_x;
        Coordinate(int x, int y, int x1)
            :src_x(x), src_y(y), dest_x(x1)
        {}
};

std::map<int,Coordinate*> coordinates = 
{
    {119, new Coordinate(0, 266, AU1XPOS)},
    {6, new Coordinate(0, 266, AU2XPOS)},
    {97, new Coordinate(0, 399, AL1XPOS)},
    {4, new Coordinate(0, 399, AL2XPOS)},
    {115, new Coordinate(0, 0, AD1XPOS)},
    {5, new Coordinate(0, 0, AD2XPOS)},
    {100, new Coordinate(0, 133, AR1XPOS)},
    {3, new Coordinate(0, 133, AR2XPOS)}

};

GameLogic :: GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning)
    :msgBus(msgBus), gameObjects(gameObjects), beatVec(nullptr), isRunning(isRunning)
{
    p1Score = 0;
    p2Score = 0;
}

void GameLogic :: start()
{
    velocity = 0.25;
    indexBeatVec = 0;
    indexBeatNo = 0;
    inputIndexBVec = 0;

    GameObject* arrow;

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(1);
    arrow->texturePositionComponent->setSrcRect(0, 932, 128, 128);
    arrow->positionComponent->setDestRect(AL1XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 932, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(2);
    arrow->texturePositionComponent->setSrcRect(0, 533, 128, 128);
    arrow->positionComponent->setDestRect(AD1XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 533, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(3);
    arrow->texturePositionComponent->setSrcRect(0, 799, 128, 128);
    arrow->positionComponent->setDestRect(AU1XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 799, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(4);
    arrow->texturePositionComponent->setSrcRect(0, 666, 128, 128);
    arrow->positionComponent->setDestRect(AR1XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 666, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    //Another player
    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(5);
    arrow->texturePositionComponent->setSrcRect(0, 932, 128, 128);
    arrow->positionComponent->setDestRect(AL2XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 932, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(6);
    arrow->texturePositionComponent->setSrcRect(0, 533, 128, 128);
    arrow->positionComponent->setDestRect(AD2XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 533, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(7);
    arrow->texturePositionComponent->setSrcRect(0, 799, 128, 128);
    arrow->positionComponent->setDestRect(AU2XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 799, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    arrow = new GameObject("texture", "position", "animation", nullptr);
	arrow->setObjectId(8);
    arrow->texturePositionComponent->setSrcRect(0, 666, 128, 128);
    arrow->positionComponent->setDestRect(AR2XPOS, AYPOS, 128, 128);
	arrow->animationComponent->setTexturePosition(0, 666, 128, 128);
	arrow->animationComponent->setAnimationSpeed(10);
	arrow->animationComponent->setNoOfFramInAnimation(2);
    gameObjects->push_back(arrow);

    std::string txt;
    txt = "Score    " + std::to_string(p1Score);
    //txt = "Score: 0";
    score1 = gui.drawText(AL1XPOS, AYPOS - 70, txt.c_str());
    gameObjects->push_back(score1);

    txt = "Score    " + std::to_string(p2Score);
    score2 = gui.drawText(AL2XPOS, AYPOS - 70, txt.c_str());
    gameObjects->push_back(score2);

    beatVec = new BeatVec("../beatmap/beethoven.txt");

    Message* msg;
    VideoData* vData;
    SoundData* sData;

    msg = new Message("video");
    vData = new VideoData("load", "../res/videos/beethoven-virus", 1409, 30, 854, 480);
    msg->setData(vData);
    msgBus->postMessage(msg);

    msg = new Message("video");
    vData = new VideoData("play");
    msg->setData(vData);
    msgBus->postMessage(msg);

    msg = new Message("sound");
    sData = new SoundData();
    sData->setdata("play", "../res/audio/beethoven.wav");
    msg->setData(sData);
    startTime = Time::sGetInstance().getCurrentTime();
    msgBus->postMessage(msg);

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
    int baseDistance = ACYPOS - AYPOS;
    double eta = baseDistance / velocity;

    for(int i = 0; i <= 3; i++)
    {
        if(indexBeatNo > beatVec->beats.size() - 1)
        {
            break;
        }

        if(beatVec->beats[indexBeatNo]->size() == 0)
        {
            indexBeatNo++;
            //indexBeatVec = 0;
            break;
        }

        if(indexBeatVec > beatVec->beats[indexBeatNo]->size() - 1)
        {
            indexBeatNo++;
            indexBeatVec = 0;
            break;
        }


        if(currentTime < (*beatVec->beats[indexBeatNo])[indexBeatVec]->beatTime - eta)
            break;


        //std::cout << "Current Time: " << currentTime << std::endl;
        //std::cout << "BeatVec time: " << beatVec.beat[indexBeatVec]->beatTime - eta << std::endl;
        GameObject* gameArrow = new GameObject("texture", "position", "movement", nullptr);
        //gameArrow->texturePositionComponent->setSrcRect(0, 0, 128, 128);
        auto key = (*beatVec->beats[indexBeatNo])[indexBeatVec]->keycode;
        auto time = (*beatVec->beats[indexBeatNo])[indexBeatVec]->beatTime;
        gameArrow->setObjectId(createId(time, key));
        gameArrow->texturePositionComponent->setSrcRect(coordinates[key]->src_x, coordinates[key]->src_y, 128, 128);
        gameArrow->positionComponent->setDestRect(coordinates[key]->dest_x, ACYPOS, 128, 128);
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
        auto keycode = in->getKeyCode();
        //std::cout << in->getKeyCode() << " " << in->getTimeStamp() - startTime << std::endl;

        if(keycode == 0)
        {
            *isRunning = false;
        }

        if(keycode > 1073741900  && keycode < 1073741907)
        {
            keycode = keycode - 1073741900;
        }


        //if(inputIndexBVec > beatVec->beats.size() - 1)
        //{
            //delete msg;
            //return;
        //}

        if(inputIndexBVec > 12)
        {
            delete msg;
            return;
        }
        //std::cout << "Reached there" << std::endl;

        //std::cout << "in: " << in->getTimeStamp() - startTime << std::endl;

        bool wrong_press = false;
        for(auto bv : *beatVec->beats[inputIndexBVec])
        {
            uint32_t diff = 1000;

            if(keycode != bv->keycode)
            {
                wrong_press = true;
                continue;
            }

            if(bv->beatTime > in->getTimeStamp() - startTime)
            {
                diff = bv->beatTime - in->getTimeStamp() + startTime;
            }
            //else if (in->getTimeStamp() - startTime > bv->beatTime)
            //{
                //diff = in->getTimeStamp() - startTime - bv->beatTime;
            //}
            else
            {
                diff = in->getTimeStamp() - startTime - bv->beatTime;
            }
            //std::cout << in->getKeyCode() << std::endl;
            //std::cout << diff << std::endl;


            if(diff < BAD)
            {
				switch (bv->keycode) {
					case 97:
						animate(1);
						break;
					case 115:
						animate(2);
						break;
					case 119:
						animate(3);
						break;
					case 100:
						animate(4);
						break;
					case 4:
						animate(5);
						break;
					case 5:
						animate(6);
						break;
					case 6:
						animate(7);
						break;
					case 3:
						animate(8);
						break;
				}

                for(auto keyc : {119, 97, 115, 100})
                {
                    if(keycode != keyc)
                    {
                        //std::cout << "In" << std::endl;
                        continue;
                    }

                    if(diff <= PERFECT)
                    {
                        p1Score += 300;
                    }
                    else if(diff <= GOOD)
                    {
                        p1Score += 100;
                    }
                    else if(diff <= BAD)
                    {
                        p1Score += 50;
                    }
                    //std::cout << p1Score << std::endl;
                    std::string txt = "Score    " + std::to_string(p1Score);
                    gui.freeTexture(score1->texturePositionComponent->getIndex());
                    gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), score1), gameObjects->end());
                    delete score1;
                    score1 = gui.drawText(AL1XPOS, AYPOS - 70, txt.c_str());
                    gameObjects->push_back(score1);
                    break;
                }

                for(auto keyc : {3, 4, 5, 6})
                {
                    if(keycode != keyc)
                    {
                        continue;
                    }

                    if(diff <= PERFECT)
                    {
                        p2Score += 300;
                    }
                    else if(diff <= GOOD)
                    {
                        p2Score += 100;
                    }
                    else if(diff <= BAD)
                    {
                        p2Score += 50;
                    }
                    std::string txt = "Score    " + std::to_string(p2Score);
                    gui.freeTexture(score2->texturePositionComponent->getIndex());
                    gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), score2), gameObjects->end());
                    delete score2;
                    score2 = gui.drawText(AL2XPOS, AYPOS - 70, txt.c_str());
                    gameObjects->push_back(score2);
                    break;
                }

                auto id = createId(bv->beatTime, bv->keycode);
                deleteGObject(id);
                break;
            } else {
                wrong_press = true;
            }
        }

        if(double_check)
        {
            if(inputIndexBVec + check_direction > beatVec->beats.size() - 1)
            {
                delete msg;
                return;
            }

            for(auto bv : *beatVec->beats[inputIndexBVec + check_direction])
            {
                uint32_t diff = 1000;

                if(keycode != bv->keycode)
                {
                    wrong_press = true;
                    continue;
                }

                if(bv->beatTime > in->getTimeStamp() - startTime)
                {
                    diff = bv->beatTime - in->getTimeStamp() + startTime;
                }
                //else if (in->getTimeStamp() - startTime > bv->beatTime)
                //{
                    //diff = in->getTimeStamp() - startTime - bv->beatTime;
                //}
                else
                {
                    diff = in->getTimeStamp() - startTime - bv->beatTime;
                }
                //std::cout << in->getKeyCode() << std::endl;
                //std::cout << diff << std::endl;


                if(diff < BAD)
                {
                    switch (bv->keycode) {
                        case 97:
                            animate(1);
                            break;
                        case 115:
                            animate(2);
                            break;
                        case 119:
                            animate(3);
                            break;
                        case 100:
                            animate(4);
                            break;
                        case 4:
                            animate(5);
                            break;
                        case 5:
                            animate(6);
                            break;
                        case 6:
                            animate(7);
                            break;
                        case 3:
                            animate(8);
                            break;
                    }

                    for(auto keyc : {119, 97, 115, 100})
                    {
                        if(keycode != keyc)
                        {
                            //std::cout << "In" << std::endl;
                            continue;
                        }

                        if(diff <= PERFECT)
                        {
                            p1Score += 300;
                        }
                        else if(diff <= GOOD)
                        {
                            p1Score += 100;
                        }
                        else if(diff <= BAD)
                        {
                            p1Score += 50;
                        }
                        //std::cout << p1Score << std::endl;
                        std::string txt = "Score    " + std::to_string(p1Score);
                        gui.freeTexture(score1->texturePositionComponent->getIndex());
                        gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), score1), gameObjects->end());
                        delete score1;
                        score1 = gui.drawText(AL1XPOS, AYPOS - 70, txt.c_str());
                        gameObjects->push_back(score1);
                        break;
                    }

                    for(auto keyc : {3, 4, 5, 6})
                    {
                        if(keycode != keyc)
                        {
                            continue;
                        }

                        if(diff <= PERFECT)
                        {
                            p2Score += 300;
                        }
                        else if(diff <= GOOD)
                        {
                            p2Score += 100;
                        }
                        else if(diff <= BAD)
                        {
                            p2Score += 50;
                        }
                        std::string txt = "Score    " + std::to_string(p2Score);
                        gui.freeTexture(score2->texturePositionComponent->getIndex());
                        gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), score2), gameObjects->end());
                        delete score2;
                        score2 = gui.drawText(AL2XPOS, AYPOS - 70, txt.c_str());
                        gameObjects->push_back(score2);
                        break;
                    }

                    auto id = createId(bv->beatTime, bv->keycode);
                    deleteGObject(id);
                    break;
                } else {
                    wrong_press = true;
                }
            }
        }

        if(wrong_press)
        {
            for(auto keyc : {119, 97, 115, 100})
            {
                if(keycode != keyc)
                {
                    //std::cout << "In" << std::endl;
                    continue;
                }

                if(p1Score != 0)
                {
                    p1Score -= 50;
                }
                std::string txt = "Score    " + std::to_string(p1Score);
                gui.freeTexture(score1->texturePositionComponent->getIndex());
                gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), score1), gameObjects->end());
                delete score1;
                score1 = gui.drawText(AL1XPOS, AYPOS - 70, txt.c_str());
                gameObjects->push_back(score1);
                break;
            }

            for(auto keyc : {3, 4, 5, 6})
            {
                if(keycode != keyc)
                {
                    continue;
                }

                if(p2Score != 0)
                {
                    p2Score -= 50;
                }
                std::string txt = "Score    " + std::to_string(p2Score);
                gui.freeTexture(score2->texturePositionComponent->getIndex());
                gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), score2), gameObjects->end());
                delete score2;
                score2 = gui.drawText(AL2XPOS, AYPOS - 70, txt.c_str());
                gameObjects->push_back(score2);
                break;
            }
        }

        delete msg;
    }
}

uint32_t GameLogic :: createId(uint32_t x, int y1)
{
    uint32_t y = y1;
    return x >= y ? x * x + x + y: y * y + x;
}

void GameLogic :: deleteGObject(uint32_t id)
{
    for(auto gO : *gameObjects)
    {
        if(gO->getObjectId() == id)
        {
            gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gO), gameObjects->end());
        }
    }

}

void GameLogic :: update()
{
    //if(endScreen)
    //{
        //displayEndScreen();
        //handleEndInputs();
        //return;
    //}
    createArrowGObjects();
    updateGObjectsPosition();
    handleInputs();
}

void GameLogic::animate(uint32_t id) {
    for(auto gO : *gameObjects)
    {
        if(gO->getObjectId() == id)
        {
			gO->animationComponent->setAnimate(true);
        }
    }
}

void GameLogic :: displayEndScreen()
{
    Message* msg = new Message("video");
    VideoData* vData = new VideoData("pause");
    msg->setData(vData);
    msgBus->postMessage(msg);

    GameObject* endBanner;
    std::string txt;
    if(p1Score > p2Score)
    {
        txt = "Player 1 Won";
    } else if (p1Score < p2Score)
    {
        txt = "Player 2 Won";
    }
    else {
    txt = "Draw";
    }
    endBanner = gui.drawText(1920 - 100, 1080 -100, txt.c_str());
    gameObjects->push_back(endBanner);
}

void GameLogic :: handleEndInputs()
{
    while(msgBus->hasMessage() && msgBus->getMessageType() == "input")
    {
        delete msgBus->getMessage();
        gameObjects->clear();
        *isRunning = false;
    }
}
