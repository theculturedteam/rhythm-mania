#include <iostream>
#include "framework/time.hpp"

int main(int argc,  char* argv[]) {

	(void) argc;
    (void) argv;

	std::cout << "Hello from main" << std::endl;

	Time *time = new Time();

	time->hello();

	return 0;
}
