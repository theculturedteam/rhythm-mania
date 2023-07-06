#include "data/SoundData.hpp"

std::string SoundData ::getpath()
{
    return path;
}

std::string SoundData ::getcommand()
{
    return command;
}
SoundData::SoundData()
{
}
void SoundData::setdata(std ::string path, std::string command)
{
    this->path = path;
    this->command = command;
}