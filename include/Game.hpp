#pragma once
#include "GameLogic.hpp"
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "data/playData.hpp"
#include "system/InputSystem.hpp"
#include "system/SoundSystem.hpp"
#include "system/RenderSystem.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void run();

    private:
        MessageBus msgBus;
        std::vector<GameObject*> gameObjects;
        std::vector<PlayData*> playDatas;
        Render renderSystem;
        InputSystem inputSystem;
        GameLogic gameLogic;
        SoundSystem soundSystem;
        bool isRunning;
        int gameState;
};
