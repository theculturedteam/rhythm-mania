#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class KeyCodeInfo
{
public:
    std::string keycode;
    int duration;
};

class Bitmap
{
    std::map<int, KeyCodeInfo> keycodeinfo;
    int time;
    std::string keycode;
    int duration;

    public:
    void bitmap();

};