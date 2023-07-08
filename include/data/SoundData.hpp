#pragma once
#include <iostream>

class SoundData
{
private:
    std::string path;
    std:: string command;
    int loop;
public:
    std:: string getpath();
    std:: string getcommand();
    int getloop();
    void setdata(std::string command, std ::string path = "", int loop = 0);
    SoundData();
};
