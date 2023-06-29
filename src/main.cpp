#include <iostream>
#include <SDL2/SDL.h>
#include "GameObjects.hpp"
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
using namespace std;

void post();
void receive();

int main(int argc, char* argv[]){
    (void) argc;
    (void) argv;
    
	GameObject player1 = GameObject();

	TexturePositionComponent* texturePositionComponent= new TexturePositionComponent();
	player1.addComponent(texturePositionComponent);
	PositionComponent* positionComponent= new PositionComponent();
	player1.addComponent(positionComponent);
	MovementComponent* movementComponent= new MovementComponent();
	player1.addComponent(movementComponent);
	ScoreComponent* scoreComponent= new ScoreComponent();
	player1.addComponent(scoreComponent);
	AnimationComponent* animaitonComponent= new AnimationComponent();
	player1.addComponent(animaitonComponent);

	for(auto* ptr : player1.getVector()) {
		ptr->setSrcRect(69, 10, 20, 20);
		std::cout << ptr->getSrcRect().x << std::endl;

		if (ptr->getComponentType() == "texture") {
			ptr->setSrcRect(10, 11, 12, 13);
			std::cout << ptr->getSrcRect().x << std::endl;
			std::cout << ptr->getSrcRect().y << std::endl;
			std::cout << ptr->getSrcRect().w << std::endl;
			std::cout << ptr->getSrcRect().h << std::endl;
		}
		else if (ptr->getComponentType() == "position") {
			ptr->setDestRect(14, 15, 16, 17);
			std::cout << ptr->getDestRect().x << std::endl;
			std::cout << ptr->getDestRect().y << std::endl;
			std::cout << ptr->getDestRect().w << std::endl;
			std::cout << ptr->getDestRect().h << std::endl;
		}
		else if (ptr->getComponentType() == "movement") {
			ptr->setVelocity(18, 19);
			std::cout << ptr->getXVelocity() << std::endl;
			std::cout << ptr->getYVelocity() << std::endl;
		}
		else if (ptr->getComponentType() == "score") {
			ptr->setScore(20);
			std::cout << ptr->getScore() << std::endl;
		}
		else if (ptr->getComponentType() == "animation") {
			ptr->setFirstTexturePosition(21, 22, 23, 24);
			std::cout << ptr->getSrcRect().x << std::endl;
			std::cout << ptr->getSrcRect().y << std::endl;
			std::cout << ptr->getSrcRect().w << std::endl;
			std::cout << ptr->getSrcRect().h << std::endl;

			ptr->setNoOfFramInAnimation(25);
			std::cout << ptr->getNoOfFrameInAnimaiton() << std::endl;
		}
	}

	for(auto* ptr : player1.getVector()) {
		delete ptr;
	}

    return 0;
}

