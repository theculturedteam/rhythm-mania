#pragma once
#include <algorithm>
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "framework/time.hpp"
#include "BeatVec.hpp"

#define APOS 50

class GameLogic
{
    public:
        GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning);
        ~GameLogic();

        void updateGObjectsPosition();
        void createArrowGObjects();
        void handleInputs();
        void update();
        void setTime();

    private:
        MessageBus* msgBus;
        std::vector<GameObject*>* gameObjects;
        BeatVec beatVec;
        uint32_t startTime;
        std::vector<BeatValue*>::size_type indexBeatVec;
        std::vector<BeatValue*>::size_type inputIndexBVec;
        float velocity; // temporary, will be provided through constructor
        bool* isRunning;
        float tempX, tempY;
};
