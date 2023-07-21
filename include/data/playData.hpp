#pragma once
#include <data/SoundData.hpp>
#include <data/videoData.hpp>

class PlayData
{
    public:
        PlayData(int velocity, SoundData* sData, VideoData* vData);
        ~PlayData();

        int velocity;
        SoundData* sData;
        VideoData* vData;
};
