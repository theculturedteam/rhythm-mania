#include "BeatMap.hpp"

BeatMap :: BeatMap(std::string beatPath)
{
    parse(beatPath);
}

BeatMap :: ~BeatMap()
{}

void BeatMap :: parse(std::string beatPath)
{
    (void)beatPath;
}


BeatValue :: BeatValue(int keycode, uint32_t beatDuration)
    :keycode(keycode), beatDuration(beatDuration)
{}


BeatValue :: ~BeatValue()
{}
