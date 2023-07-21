#include "Game.hpp"

int main(int argc, char* argv[]){
	(void) argc;
	(void) argv;

	testRenderSystem();
	return 0;
}


// void testGui(){
// 	Gui gui;
// 	GameObject* text ;
// 	text = gui.drawText(100, 100, 50 , 50, "hello");
// 	std::vector<GameObject*>* gameObjects =  new std::vector<GameObject*>{text};
// }