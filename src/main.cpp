#include <iostream>
#include "framework/time.hpp"
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
    Message* another = msgBus->getMessage();
    cout << another->getType() << std::endl;
    delete another;
}
