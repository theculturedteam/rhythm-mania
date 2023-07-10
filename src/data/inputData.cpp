#include "data/inputData.hpp"

InputData :: InputData(int keycode, uint32_t timestamp)
    : keycode(keycode), timestamp(timestamp)
{}

InputData :: ~InputData()
{}

int InputData :: getKeyCode()
{
    return keycode;
}

uint32_t InputData :: getTimeStamp()
{
    return timestamp;
}
