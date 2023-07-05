#pragma once
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "framework/time.hpp"
#include "BeatMap.hpp"
#include "time.h"

class GameLogic
{
    public:
        GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects);
        ~GameLogic();

        void updateGameObjectsPosition();
        void createArrowGObjects();
        void handleInputs();
        void update();

    private:
        MessageBus* msgBus;
        std::vector<GameObject*>* gameObjects;
        BeatMap beatMap;
        uint32_t startTime;
};
