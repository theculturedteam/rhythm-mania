#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>

class BeatValue
{
    public:
        BeatValue(uint32_t beatTime, int keycode);
        ~BeatValue();
        uint32_t beatTime;
        int keycode;
};

class BeatVec
{
    public:

        BeatVec(std::string beatPath);
        ~BeatVec();
        std::vector<BeatValue*> beat1;
        std::vector<BeatValue*> beat2;
        std::vector<BeatValue*> beat3;
        std::vector<BeatValue*> beat4;
        std::vector<BeatValue*> beat5;
        std::vector<BeatValue*> beat6;
        std::vector<BeatValue*> beat7;
        std::vector<BeatValue*> beat8;
        std::vector<BeatValue*> beat9;
        std::vector<BeatValue*> beat10;
        std::vector<BeatValue*> beat11;
        std::vector<BeatValue*> beat12;
        std::vector<std::vector<BeatValue*>*> beats;
    private:
        uint32_t beatTime;
        int keycode;
        void parse(std::string beatPath);
};
