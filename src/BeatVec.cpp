#include "BeatVec.hpp"

BeatVec :: BeatVec(std::string beatPath)
{
    //parse(beatPath);
    (void)beatPath;
    beat.push_back(new BeatValue(10000, 115, 0));
    beat.push_back(new BeatValue(11000, 115, 0));
    beat.push_back(new BeatValue(11500, 115, 0));
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
