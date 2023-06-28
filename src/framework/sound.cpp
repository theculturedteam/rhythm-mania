#include "framework/sound.hpp"
#include<iostream>

void Sound ::PlayMusic(char *path, int loop)
{
    if (Mix_OpenAudio(22020, AUDIO_S16SYS, 2, 4096) != 0) // initializes the audio device
    {
        printf("can't play the music");
    }
    run_music = Mix_LoadMUS(path); // creates the music object of the music in path;
    Mix_PlayMusic(run_music, loop);
}

void Sound :: PauseMusic()
{
    if(Mix_PlayingMusic)
    {
        Mix_PauseMusic();
    }
    else
        printf("Music isn't playing");
}

void Sound :: ResumeMusic()
{
    if (Mix_PausedMusic)
    {
        Mix_ResumeMusic();
    }
    else
        printf("Music isn't paused");
}