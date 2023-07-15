#include "system/System.hpp"
#include "MessageBus.hpp"
#include "data/SoundData.hpp"
#include "framework/sound.hpp"

class SoundSystem : public System
{
private:
    SoundData *soundData;
    Sound &object = Sound ::get_object();

public:
    void handleMessage();
};


