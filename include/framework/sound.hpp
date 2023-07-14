#pragma once
#include "SDL_mixer.h"
#include "iostream"
class Sound
{
private:
    Mix_Music *run_music;
    Mix_Chunk *current_music;
    Sound();

public:
    static Sound &get_object();
    void PlayMusic(int loop);
    void PlayChunk(int loop);
    void LoadMusic(const char *path); // to load music i.e. to create music object run_music
    void LoadChunk(const char *path); // to load hunk i.e. current_music
    void PauseMusic();
    void ResumeMusic();
    void FreeMusic();
    void FreeChunk();
};
