#pragma once
#include "GameLogic.hpp"
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "system/inputSystem.hpp"
#include "system/SoundSystem.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void run();
    private:
        MessageBus msgBus;
        InputSystem inputSystem;
        //SoundSystem soundSystem;
        GameLogic gameLogic;
        std::vector<GameObject*> gameObjects;
        bool isRunning;
        int gameState;
};
