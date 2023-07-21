#include "BeatVec.hpp"

BeatVec :: BeatVec(std::string beatPath)
{
    //parse(beatPath);
    //(void)beatPath;
    //beat.push_back(new BeatValue(10000, 115, 0));
    //beat.push_back(new BeatValue(11000, 115, 0));
    //beat.push_back(new BeatValue(11500, 115, 0));
    //beat1.push_back(new BeatValue(6000, 115));
    //beat1.push_back(new BeatValue(6200, 115));
    //beat1.push_back(new BeatValue(7000, 115));
    //beat1.push_back(new BeatValue(8500, 115));
    //beat2.push_back(new BeatValue(11000, 115));

    //beats.push_back(&beat1);
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
    parse(beatPath);
}

BeatVec :: ~BeatVec()
{}

void BeatVec :: parse(std::string beatPath)
{
    //(void)beatPath;
    std::ifstream mapfile(beatPath);
    while(mapfile >> beatTime >> keycode)
    {
        //std::cout << beatTime << " " << keycode << std::endl;
        if(beatTime < 10000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat1.push_back(beatValue);
        }
        else if (beatTime < 20000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat2.push_back(beatValue);
        }
        else if (beatTime < 30000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat3.push_back(beatValue);
        }
        else if (beatTime < 40000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat4.push_back(beatValue);
        }
        else if (beatTime < 50000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat5.push_back(beatValue);
        }
        else if (beatTime < 60000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat6.push_back(beatValue);
        }
        else if (beatTime < 70000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat7.push_back(beatValue);
        }
        else if (beatTime < 80000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat8.push_back(beatValue);
        }
        else if (beatTime < 90000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat9.push_back(beatValue);
        }
        else if (beatTime < 100000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat10.push_back(beatValue);
        }
        else if (beatTime < 110000)
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat11.push_back(beatValue);
        }
        else
        {
            BeatValue *beatValue = new BeatValue(beatTime, keycode);
            beat12.push_back(beatValue);
        }
    }
    mapfile.close();
    beats.push_back(&beat1);
    beats.push_back(&beat2);
    beats.push_back(&beat3);
    beats.push_back(&beat4);
    beats.push_back(&beat5);
    beats.push_back(&beat6);
    beats.push_back(&beat7);
    beats.push_back(&beat8);
    beats.push_back(&beat9);
    beats.push_back(&beat10);
    beats.push_back(&beat11);
    beats.push_back(&beat12);
}


BeatValue :: BeatValue(uint32_t beatTime, int keycode)
    :beatTime(beatTime), keycode(keycode)
{}


BeatValue :: ~BeatValue()
{}
