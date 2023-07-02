#include "Message.hpp"

Message :: Message(std::string type)
{
    if(validate_type(type))
    {
        this->type = type;
    } else {
        std::cout << "Error: message type not valid" << std::endl;
    }
    pInputData = nullptr;
    pSoundData = nullptr;
}

Message :: ~Message()
{
    delete pInputData;
    delete pSoundData;
}

bool Message :: validate_type(std::string type)
{
    std::string types[] = {"sound", "input"};

    for(std::string t : types)
    {
        if(type == t)
            return true;
    }
    return false;
}

std::string Message :: getType()
{
    return type;
}

void Message :: setData(InputData* pData)
{
    pInputData = pData;
}

void Message :: setData(SoundData* pData)
{
    pSoundData = pData;
}

InputData* Message :: getInputData()
{
    if(pInputData == nullptr)
    {
        std::cout << "Error: Message::getInputData asking for nonexistent data" << std::endl;
    }
    return pInputData;
}

SoundData* Message :: getSoundData()
{
    if(pSoundData == nullptr)
    {
        std::cout << "Error: Message::getSoundData asking for nonexistent data" << std::endl;
    }
    return pSoundData;
}
