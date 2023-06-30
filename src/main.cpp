#include <iostream>
#include <SDL2/SDL.h>
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "framework/sound.hpp"
using namespace std;

void soundtest();
const int screen_width = 640;
const int screen_height = 480;
MessageBus* msgBus = new MessageBus();

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;
        SDL_Window* window = NULL;

        SDL_Surface* screenSurface = NULL;
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        {
            printf("SDl could not be inintialized");
        }
        else
        {
            window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
            if(window == NULL)
            {
                printf("window could not be created! sdl_error : %s\n", SDL_GetError());
            }
            else
            {
                screenSurface = SDL_GetWindowSurface(window);
                SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
                SDL_UpdateWindowSurface(window);
                printf("started");
                soundtest();
                SDL_Event e; 
                bool quit = false; 
                while (quit == false)
                {
                    while(SDL_PollEvent(&e)) 
                    {
                        if (e.type == SDL_QUIT) 
                        quit = true;
                        }
                }
                
            }
        }
        SDL_DestroyWindow(window);
        SDL_Quit();
        
    // while(true)
    // {
    //     printf("started");
    //     void soundtest();
    //     // post();
    //     // receive();
    // }
        return 0;
}


// void post()
// {
//     Message* msg = new Message("input");
//     msg->set('a');
//     msgBus->postMessage(msg);
// }

// void receive()
// {
//     Message* another = msgBus->getMessage();
//     cout << another->getType() << std::endl;
//     delete another;
// }
 void soundtest(){
    int choice;

    Sound *object = Sound :: get_object();
    // object.PlayChunk("../res/audio/music1.wav", 1);
    object->LoadMusic("../res/audio/music1.wav");
    object->PlayMusic(1);
    printf("enter");
    scanf("%d", &choice);
    if (choice == 1)
    {
            object->PauseMusic();
        }
        scanf("%d", &choice);
        if (choice == 1)
        {
            object->ResumeMusic();
        }
 }