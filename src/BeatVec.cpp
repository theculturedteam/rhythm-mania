#include "BeatVec.hpp"

BeatVec :: BeatVec(std::string beatPath)
{
    //parse(beatPath);
    (void)beatPath;
    //beat.push_back(new BeatValue(10000, 115, 0));
    //beat.push_back(new BeatValue(11000, 115, 0));
    //beat.push_back(new BeatValue(11500, 115, 0));
    beat1.push_back(new BeatValue(6000, 115));
    //beat1.push_back(new BeatValue(6200, 115));
    beat1.push_back(new BeatValue(7000, 115));
    beat1.push_back(new BeatValue(8500, 115));

    beats.push_back(&beat1);
    //beats.push_back(&beat2);
    //beats.push_back(&beat3);
    //beats.push_back(&beat4);
    //beats.push_back(&beat5);
    //beats.push_back(&beat6);
    //beats.push_back(&beat7);
    //beats.push_back(&beat8);
    //beats.push_back(&beat9);
    //beats.push_back(&beat10);
    //beats.push_back(&beat11);
    //beats.push_back(&beat12);
}

BeatVec :: ~BeatVec()
{}

void BeatVec :: parse(std::string beatPath)
{
    (void)beatPath;
}


BeatValue :: BeatValue(uint32_t beatTime, int keycode)
    :beatTime(beatTime), keycode(keycode)
{}


BeatValue :: ~BeatValue()
{}
