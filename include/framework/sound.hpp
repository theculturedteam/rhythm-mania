#pragma once
#include "SDL_mixer.h"
class Sound{
    static Mix_Music *run_music;
    public:
    static void PlayMusic(char *path, int loop);
    static void PauseMusic();
    static void ResumeMusic();
};