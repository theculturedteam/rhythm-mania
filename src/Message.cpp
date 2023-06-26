#include "Message.hpp"
#include <iostream>

Message :: Message(std::string type)
{
    if(validate_type(type))
    {
        this->type = type;
    } else {
        std::cout << "Error: message type not valid" << std::endl;
    }
}

bool Message :: validate_type(std::string type)
{
    std::string types[] = {"command", "time", "input", "path"};

    for(std::string t : types)
    {
        if(type == t)
            return true;
    }
    return false;
}

void Message :: set(char c)
{
    this->input = c;
}

void Message :: set(u_int32_t time)
{
    this->time = time;
}

void Message :: set(std::string str)
{
    this->str = str;
}

void Message :: set(std::string cmd, std::string str)
{
    this->command = cmd;
    this->str = str;
}
