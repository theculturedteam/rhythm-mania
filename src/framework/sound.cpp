#include "framework/sound.hpp"
#include <iostream>

// Mix_Music *Sound::run_music = nullptr;
// Mix_Chunk *Sound::current_music = nullptr;

void Sound ::LoadMusic(const char *path)
{
    run_music = Mix_LoadMUS(path); // creates the music object of the music in path;
}

void Sound ::LoadChunk(const char *path)
{
    current_music = Mix_LoadWAV(path);
}

void Sound ::PlayMusic(int loop)
{
    printf("  music initialized\n");
    Mix_PlayMusic(run_music, loop);
}

void Sound ::PlayChunk(int loop)
{
    if (Mix_OpenAudio(22020, AUDIO_S16SYS, 2, 4096) != 0) // initializes the audio device
    {
        printf("can't play the music");
    }
    Mix_PlayChannel(-1, current_music, loop); //-1 chooses the available channel
}

void Sound ::PauseMusic()
{
    if (Mix_PlayingMusic())
    {
        Mix_PauseMusic();
    }
    else
        printf("music isn't playing");
}

void Sound ::ResumeMusic()
{
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
    else
        printf("Music isn't paused");
}
Sound &Sound ::get_object()
{
    static Sound instance;
    return instance;
}

Sound ::Sound()
{
    if (Mix_OpenAudio(22020, AUDIO_S16SYS, 2, 4096) != 0) // initializes the audio device
    {
        printf("can't play the music");
    }
}
void Sound :: FreeMusic()
{
    Mix_FreeMusic(run_music);
    Mix_CloseAudio();
    Mix_Quit();
}

void Sound::FreeChunk()
{
    Mix_FreeChunk(current_music);
    Mix_CloseAudio();
    Mix_Quit();
}