#pragma once
#include <string>
#include <sys/types.h>


class Message
{
    public:
        Message(std::string type);
        void set(char c);
        void set(u_int32_t time);
        void set(std::string str);

    private:
        bool validate_type(std::string type);
        std::string type;
        
        //Declares the variable inside union as if it's member of class
        //But the members share the memory space
        union
        {
            char input;
            u_int32_t time;
            std::string str;
        };
};
