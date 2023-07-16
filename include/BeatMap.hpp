#pragma once
#include <iostream>
#include <cstdint>
#include <unordered_map>

class BeatValue
{
    public:
        BeatValue(int keycode, uint32_t beatDuration);
        ~BeatValue();
        int keycode;
        uint32_t beatDuration;
};

class BeatMap
{
    public:
        BeatMap(std::string beatPath);
        ~BeatMap();
        std::unordered_map<uint32_t, BeatValue*> beat;
    private:
        void parse(std::string beatPath);
};
