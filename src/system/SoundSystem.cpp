#include "system/SoundSystem.hpp"

SoundSystem::SoundSystem(MessageBus *msgBus)
    : System(msgBus)
{
}

void SoundSystem ::update()
{
    handleMessage();
}

void SoundSystem ::handleMessage()
{
    if (msgBus->hasMessage())
    {
        if (msgBus->getMessageType() == "sound")
        {
            Message *message = msgBus->getMessage();
            Sound &object = Sound ::get_object();
            SoundData *soundData;
            soundData = message->getSoundData();
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
            delete message;
        }
    }
}
