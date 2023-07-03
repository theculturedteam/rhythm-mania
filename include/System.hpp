#pragma once
#include "MessageBus.hpp"

class System
{
    public:
        System(MessageBus* msgBus);
        virtual void handleMessage() = 0;
        virtual ~System() = default;
        virtual void update() = 0;
    private:
        MessageBus* msgBus;
};
