#pragma once
#include <string>
#include <cstdint>
#include <iostream>

class Message
{
    public:
        Message(std::string type);
        ~Message();
        void set(char c);
        void set(uint32_t time);
        void set(std::string str);
        void set(std::string cmd, std::string str);
        std::string getType();

        std::string command;
        
        //Declares the variable inside union as if it's member of class
        //But the members share the memory space
        union
        {
            char input;
            uint32_t time;
            std::string str;
        };

    private:
        bool validate_type(std::string type);
        std::string type;
};
