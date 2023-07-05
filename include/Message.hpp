#pragma once
#include <iostream>
#include <string>
#include "data/inputData.hpp"
#include "data/soundData.hpp"

class Message
{
    public:
        Message(std::string type);
        ~Message();
        std::string getType();

        void setData(InputData* pData);
        void setData(SoundData* pData);
        InputData* getInputData();
        SoundData* getSoundData();

    private:
        bool validate_type(std::string type);
        std::string type;
        InputData* pInputData;
        SoundData* pSoundData;
};
