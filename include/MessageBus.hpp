#pragma once
#include <queue>
#include "Message.hpp"

class MessageBus
{
    public:
        MessageBus();
    private:
        std::queue<Message> messageQueue;
};
