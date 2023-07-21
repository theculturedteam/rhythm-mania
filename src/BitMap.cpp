#include"BitMap.hpp"

void Bitmap :: bitmap()
{
    std :: ifstream mapfile("../bitmap/bitmap1.txt");
    // int time, duration;
    // std::string keycode;
    while(mapfile >> time >> keycode >> duration)
    {
        KeyCodeInfo info;
        info.keycode = keycode;
        info.duration = duration;
        keycodeinfo.insert(std::make_pair(time, info));
    }

    mapfile.close();
    
    //to access the values in map
    //only to test the code segment
    while (keycodeinfo.count(102982)>0)
    {
        KeyCodeInfo info = keycodeinfo.at(102982);
        keycode = info.keycode;
        duration = info.duration;
        std:: printf("%s\n", keycode.c_str());
        std :: printf("%d", duration);
        keycodeinfo.erase(102982);

    }
    

}