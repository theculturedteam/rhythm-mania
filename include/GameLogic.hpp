#pragma once
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "framework/time.hpp"
#include "BeatMap.hpp"

class GameLogic
{
    public:
        GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects);
        ~GameLogic();

        void updateGObjectsPosition();
        void createArrowGObjects();
        void handleInputs();
        void update();

    private:
        MessageBus* msgBus;
        std::vector<GameObject*>* gameObjects;
        BeatMap beatMap;
        uint32_t startTime;
};
