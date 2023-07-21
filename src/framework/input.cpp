#include "framework/input.hpp"

Input :: Input()
{}

Input :: ~Input()
{}

Input& Input :: getInstance()
{
    static Input instance;
    return instance;
}

std::vector<InputData*>* Input :: getInputs()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            std::cout << "Quit Event: SDL asks to quit" << std::endl;
            InputData* in = new InputData(0, 0);
            inputsVec.push_back(in);
        } else if(!event.key.repeat && (event.type == SDL_KEYDOWN))
        {
            InputData* in = new InputData(event.key.keysym.sym, event.key.timestamp);
            inputsVec.push_back(in);
        }
    };
    return &inputsVec;
};

void Input :: clearInputs()
{
    inputsVec.clear();
}
