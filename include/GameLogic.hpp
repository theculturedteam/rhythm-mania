#pragma once
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdint>
#include "GameObjects.hpp"
#include "MessageBus.hpp"
#include "framework/time.hpp"
#include "data/SoundData.hpp"
#include "BeatVec.hpp"

#define AYPOS 100
#define ACYPOS 1070

#define AL1XPOS 40
#define AD1XPOS 178
#define AU1XPOS 309
#define AR1XPOS 444

#define AL2XPOS 1348
#define AD2XPOS 1481
#define AU2XPOS 1614
#define AR2XPOS 1752

class GameLogic
{
    public:
        GameLogic(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning);
        ~GameLogic();

        void updateGObjectsPosition();
        void createArrowGObjects();
        void handleInputs();
        void update();
        void start();
		void animate(uint32_t id);

    private:
        MessageBus* msgBus;
        std::vector<GameObject*>* gameObjects;
        BeatVec* beatVec;
        uint32_t startTime;
        std::vector<BeatValue*>::size_type indexBeatVec;
        std::vector<BeatValue*>::size_type indexBeatNo;
        std::vector<BeatValue*>::size_type inputIndexBVec;
        float velocity; // temporary, will be provided through constructor
        bool* isRunning;
        uint32_t createId(uint32_t timestamp, int keycode);
        void deleteGObject(uint32_t id);

        int p1Score, p2Score;
};
