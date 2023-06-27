#include "MessageBus.hpp"

MessageBus :: MessageBus(){}
MessageBus :: ~MessageBus(){}

void MessageBus :: postMessage(Message* msg)
{
    messageQueue.push(msg);
}

Message* MessageBus :: getMessage()
{
    Message* msg = messageQueue.front();
    messageQueue.pop();
    return msg;
}

std::string MessageBus :: getMessageType()
{
    return messageQueue.front()->getType();
}
