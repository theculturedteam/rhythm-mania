#include "BeatVec.hpp"

BeatVec :: BeatVec(std::string beatPath)
{
    //parse(beatPath);
    (void)beatPath;
    //beat.push_back(new BeatValue(10000, 115, 0));
    //beat.push_back(new BeatValue(11000, 115, 0));
    //beat.push_back(new BeatValue(11500, 115, 0));
    beat1.push_back(new BeatValue(10000, 115, 0));
    beat1.push_back(new BeatValue(11000, 115, 0));
    beat1.push_back(new BeatValue(11500, 115, 0));

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


BeatValue :: BeatValue(uint32_t beatTime, int keycode, uint32_t beatDuration)
    :beatTime(beatTime), keycode(keycode), beatDuration(beatDuration)
{}


BeatValue :: ~BeatValue()
{}
