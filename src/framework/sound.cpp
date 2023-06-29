#include "framework/sound.hpp"
#include<iostream>

// Mix_Music *Sound::run_music = nullptr;
// Mix_Chunk *Sound::current_music = nullptr;
Sound *Sound :: instance = nullptr;

void Sound ::PlayMusic(const char *path, int loop)
{
    if (Mix_OpenAudio(22020, AUDIO_S16SYS, 2, 4096) != 0) // initializes the audio device
    {
        printf("can't play the music");
    }
    printf("music initialized");
    run_music = Mix_LoadMUS(path); // creates the music object of the music in path;
    Mix_PlayMusic(run_music, loop);
}

void Sound ::PlayChunk(const char *path, int loop)
{
    if (Mix_OpenAudio(22020, AUDIO_S16SYS, 2, 4096) != 0) // initializes the audio device
    {
        printf("can't play the music");
    }
    current_music = Mix_LoadWAV(path); // creates the music object of the music in path;
    Mix_PlayChannel(-1, current_music, loop);  //-1 chooses the available channel 
}

void Sound :: PauseMusic()
{
    if(Mix_PlayingMusic())
    {
        Mix_PauseMusic();
    }
    else
        printf("music isn't playing");
}

void Sound :: ResumeMusic()
{
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
    else
        printf("Music isn't paused");
}
Sound* Sound :: get_object(){
        if(instance == NULL){
            instance = new Sound();
            return instance;
        }
        return instance;
}

Sound :: Sound(){}