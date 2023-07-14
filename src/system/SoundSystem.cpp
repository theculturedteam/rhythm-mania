#include "system/SoundSystem.hpp"

void SoundSystem ::handleMessage()
{
    if (msgBus->hasMessage())
    {
        if (msgBus->getMessageType() == "sound")
        {
            if (soundData->getcommand() == "play")
            {
                object.LoadMusic(soundData->getpath().c_str());
                object.PlayMusic(soundData->getloop());
            }
            else if (soundData->getcommand() == "pause")
            {
                object.PauseMusic();
            }
            else if (soundData->getcommand() == "resume")
            {
                object.ResumeMusic();
            }
            else if (soundData->getcommand() == "free")
            {
                object.FreeMusic();
            }
            else
            {
                printf("The command is invalid");
            }
        }
    }
}
