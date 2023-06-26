#include <iostream>
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
using namespace std;

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;
    
	std::cout << "Hello from main" << std::endl;
	Time *time = new Time();

	time->hello();
    cout << "Hello World" << endl;
    Message *msg = new Message("input");
    msg->set('k');

    return 0;
}
