#include "framework/input.hpp"
#include <SDL_events.h>

Input& Input :: getInstance()
{
    static Input instance;
    return instance;
}

void Input :: getInputs()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            std::cout << "SDL asks to quit" << std::endl;
        } else if(!event.key.repeat && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)){
            switch(event.key.keysym.sym){
                case SDLK_RETURN:
                    break;
                case SDLK_w:
                    break;
                case SDLK_UP:
                    break;
                case SDLK_a:
                    break;
                case SDLK_LEFT:
                    break;
                case SDLK_s:
                    break;
                case SDLK_RIGHT:
                    break;
                case SDLK_d:
                    break;
                case SDLK_DOWN:
                    break;
            }
        }
    };
};
