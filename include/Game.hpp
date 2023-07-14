#pragma once
#include "GameLogic.hpp"
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
};
