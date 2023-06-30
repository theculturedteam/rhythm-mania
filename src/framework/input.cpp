#include "framework/input.hpp"

Input& Input :: getInstance()
{
    static Input instance;
    return instance;
}

InputData* Input :: getInputs()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            std::cout << "Quit Event: SDL asks to quit" << std::endl;
            InputData* in = new InputData(0, 0);
            return in;
        } else if(!event.key.repeat && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP))
        {
            InputData* in = new InputData(event.key.keysym.sym, event.key.timestamp);
            return in; //Please call delete in GameLogic
        }
    };
    return nullptr;
};
