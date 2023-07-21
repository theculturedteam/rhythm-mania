#include "data/playData.hpp"

PlayData :: PlayData(int velocity, SoundData* sData, VideoData* vData)
    : velocity(velocity), sData(sData), vData(vData)
{}

PlayData :: ~PlayData()
{
    delete sData;
    delete vData;
}
