#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL_events.h>
#include "framework/inputData.hpp"

class Input
{
    public:
        static Input& getInstance();
        ~Input();
        std::vector<InputData*>* getInputs();
        void clearInputs();

        Input(Input const&) = delete; // Avoiding copy of the instance
        void operator=(Input const&) = delete; // Overriding = to avoid copy

    private:
        Input();
        std::vector<InputData*> inputsVec;
        SDL_Event event;
};
