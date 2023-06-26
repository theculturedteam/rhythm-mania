#pragma once
#include "SDL_mixer.h"
class Sound{
    Mix_Music *run_music;
    int loop;
    public:
    Sound(char* path, int loop);
    ~Sound();
};