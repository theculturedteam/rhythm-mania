#include <iostream>
#include "Message.hpp"
#include "MessageBus.hpp"
using namespace std;

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;
    
    cout << "Hello World" << endl;
    Message *msg = new Message("input");
    msg->set('k');

    return 0;
}
