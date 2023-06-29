#pragma once
#include "SDL2/SDL_mixer.h"
class Sound{
    private:
    Mix_Music *run_music;
    Mix_Chunk *current_music;
    static Sound *instance;
    // Sound();

public:
    
    static Sound *get_object();
     void PlayMusic(const char *path, int loop);
     void PlayChunk(const char *path, int loop);
     void PauseMusic();
     void ResumeMusic();
};
