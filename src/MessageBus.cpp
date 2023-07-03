#include "MessageBus.hpp"

MessageBus :: MessageBus(){}
MessageBus :: ~MessageBus(){}

void MessageBus :: postMessage(Message* msg)
{
    messageQueue.push(msg);
}

Message* MessageBus :: getMessage()
{
    if(messageQueue.empty())
    {
        std::cout << "Error: Trying to get message from empty bus" << std::endl;
        return nullptr;
    }

    Message* msg = messageQueue.front();
    messageQueue.pop();
    return msg;
}

std::string MessageBus :: getMessageType()
{
    if(messageQueue.empty())
    {
        std::cout << "Error: Trying to get message type from empty bus" << std::endl;
        return "";
    }

    return messageQueue.front()->getType();
}

bool MessageBus :: hasMessage()
{
    return !messageQueue.empty();
}
