#pragma once
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "framework/time.hpp"
#include "BeatVec.hpp"

#define APOS 80

class GameLogic
{
    public:
        GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning);
        ~GameLogic();

        void updateGObjectsPosition();
        void createArrowGObjects();
        void handleInputs();
        void update();

    private:
        MessageBus* msgBus;
        std::vector<GameObject*>* gameObjects;
        BeatVec beatVec;
        uint32_t startTime;
        std::vector<BeatValue*>::size_type indexBeatVec;
        float velocity; // temporary, will be provided through constructor
        bool* isRunning;
};
