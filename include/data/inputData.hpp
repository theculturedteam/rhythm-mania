#pragma once
#include <cstdint>

class InputData
{
    public:
        InputData(int keycode, uint32_t timestamp);
        ~InputData();
        int getKeyCode();
        uint32_t getTimeStamp();

    private:
        int keycode;
        uint32_t timestamp;
};
