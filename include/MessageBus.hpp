#pragma once
#include <iostream>
#include <queue>
#include <string>
#include "Message.hpp"

class MessageBus
{
    public:
        MessageBus();
        ~MessageBus();
        void postMessage(Message* msg);
        Message* getMessage();
        std::string getMessageType();
    private:
        std::queue<Message*> messageQueue;
};
