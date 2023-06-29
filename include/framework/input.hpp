#pragma once
#include <SDL_events.h>
#include <iostream>

class Input
{
    public:
        static Input& getInstance();
        ~Input();
        void getInputs();

        Input(Input const&) = delete; // Avoiding copy of the instance
        void operator=(Input const&) = delete; // Overriding = to avoid copy

    private:
        Input();
        SDL_Event event;
};
