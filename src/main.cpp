#include <iostream>
#include <SDL2/SDL.h>
#include "framework/time.hpp"

int main(int argc,  char* argv[]) {

	(void) argc;
    (void) argv;

	std::cout << "Hello from main" << std::endl;


	while (true) {
		std::cout << Time::sGetTime() << std::endl;
	}

	return 0;
}
