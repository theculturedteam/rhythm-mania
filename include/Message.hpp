#pragma once
#include <iostream>
#include <string>
#include "data/inputData.hpp"
#include "data/soundData.hpp"
#include "data/videoData.hpp"

class Message
{
    public:
        Message(std::string type);
        ~Message();
        std::string getType();

        void setData(InputData* pData);
        void setData(SoundData* pData);
        void setData(VideoData* pData);

        InputData* getInputData();
        SoundData* getSoundData();
        VideoData* getVideoData();

    private:
        bool validate_type(std::string type);
        std::string type;

        InputData* pInputData;
        SoundData* pSoundData;
        VideoData* pVideoData;
};
