#pragma once
#include <iostream>
#include <cstdint>
#include <vector>

class BeatValue
{
    public:
        BeatValue(uint32_t beatTime, int keycode, uint32_t beatDuration);
        ~BeatValue();
        uint32_t beatTime;
        int keycode;
        uint32_t beatDuration;
};

class BeatVec
{
    public:
        BeatVec(std::string beatPath);
        ~BeatVec();
        std::vector<BeatValue*> beat;
    private:
        void parse(std::string beatPath);
};
