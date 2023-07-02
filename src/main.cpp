#include <iostream>
#include "Message.hpp"
#include "MessageBus.hpp"
#include "framework/inputData.hpp"
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
    InputData* in = new InputData(98, 123);
    msg->setData(in);
    msgBus->postMessage(msg);
}

void receive()
{
    if(msgBus->hasMessage())
    {
        //std::cout << msgBus->getMessageType() << std::endl;
        Message* another = msgBus->getMessage();
        InputData* in = another->getInputData();
        std::cout << in->getKeyCode() << std::endl;
        //std::cout << in->getTimeStamp() << std::endl;
        delete another;
    }
}
