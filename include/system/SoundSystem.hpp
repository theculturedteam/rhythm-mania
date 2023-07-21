#include "system/System.hpp"
#include "MessageBus.hpp"
#include "data/SoundData.hpp"
#include "framework/sound.hpp"


class SoundSystem : public System
{
private:
    
public:
    void update();
    void handleMessage();
    SoundSystem(MessageBus *msgbus);

};


