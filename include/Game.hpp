#pragma once
#include "GameLogic.hpp"
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "system/InputSystem.hpp"
#include "system/SoundSystem.hpp"
#include "system/RenderSystem.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void run();
        void testGui();
    private:
        MessageBus msgBus;
        std::vector<GameObject*> gameObjects;
        Render renderSystem;
        InputSystem inputSystem;
        //SoundSystem soundSystem;
        GameLogic gameLogic;
        bool isRunning;
        int gameState;
};
