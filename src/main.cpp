#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "framework/time.hpp"
#include "framework/input.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
using namespace std;

void post();
void receive();
void init(const char* title, int xpos, int ypos, int width, int height);
void qquit();

MessageBus* msgBus = new MessageBus();
bool isRunning;
SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;

    init("Game", 0, 40, 1280, 720);

    Input& input = Input::getInstance();

    while(isRunning)
    {
        for(InputData* in : *input.getInputs())
        {
            std::cout << in->getKeyCode() << std::endl;
            std::cout << std::endl;
            //std::cout << in->getTimeStamp() << std::endl;
            if(in->getKeyCode() == 0)
            {
                isRunning = false;
            }
            delete in;
        }
        input.clearInputs();
    }

    qquit();
    return 0;
}


void post()
{
    Message* msg = new Message("input");
    msg->set('a');
    msgBus->postMessage(msg);
}

void receive()
{
    Message* another = msgBus->getMessage();
    cout << another->getType() << std::endl;
    delete another;
}

void init(const char* title, int xpos, int ypos, int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    if(!IMG_Init(IMG_INIT_PNG)){
        std::cout << "IMG INIT ERROR: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    isRunning = true;
    std::cout << "Game Started" << std::endl;
}

void qquit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Ended" << std::endl;
}
