#include <iostream>
#include "Message.hpp"
#include "MessageBus.hpp"
using namespace std;

void post();
void receive();

MessageBus* msgBus = new MessageBus();

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;

    while(true)
    {
    post();
    receive();
    }
    //std::cout << msgBus->getMessageType() << std::endl;
    return 0;
}


void post()
{
    Message* msg = new Message("input");
    msg->set('a');
    msgBus->postMessage(msg);
}

void receive()
{
    if(msgBus->hasMessage())
    {
        std::cout << msgBus->getMessageType() << std::endl;
        Message* another = msgBus->getMessage();
        delete another;
    }
}
