#include "data/SoundData.hpp"

std::string SoundData ::getpath()
{
    return path;
}

std::string SoundData ::getcommand()
{
    return command;
}

int SoundData ::getloop()
{
    return loop;
}

SoundData::SoundData()
{
}

void SoundData::setdata(std::string command, std ::string path, int loop)
{
    this->path = path;
    this->command = command;
    this->loop = loop;
}