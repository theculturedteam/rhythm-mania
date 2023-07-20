#include <SDL2/SDL_timer.h>
#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include "GameObjects.hpp"
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "framework/inputData.hpp"
using namespace std;

MessageBus* msgBus = new MessageBus();

void testTimeFramework() {
	std::cout << "Testing Time Framework" << std::endl;
	SDL_Init(SDL_INIT_TIMER);

	Time& timeInstance = Time::sGetInstance();

	timeInstance.setPreviousTime(timeInstance.getCurrentTime());

	std::cout << "Previous Time: " << timeInstance.getPreviousTime() << std::endl;

	while (true) {
		double dt = timeInstance.calculateDeltaTime(timeInstance.getCurrentTime());
		std::cout << "dt: " << dt << std::endl;
		SDL_Delay(16);
	}
}

void testGameObject() {
	std::cout << "Testing Game Object" << std::endl;
	std::cout << "debug0" << std::endl;
	GameObject player1("texture", "position", "movement", "score", "animation", nullptr);

	player1.texturePositionComponent->setSrcRect(10, 11, 12, 13);
	std::cout << "x: " << player1.texturePositionComponent->getSrcRect().x << std::endl;
	std::cout << "y: " << player1.texturePositionComponent->getSrcRect().y << std::endl;
	std::cout << "w: " << player1.texturePositionComponent->getSrcRect().w << std::endl;
	std::cout << "h: " << player1.texturePositionComponent->getSrcRect().h << std::endl;

	player1.positionComponent->setDestRect(14.01, 15.51, 16.99, 17.04);
	std::cout << "x: " << player1.positionComponent->getDestRect().x << std::endl;
	std::cout << "y: " << player1.positionComponent->getDestRect().y << std::endl;
	std::cout << "w: " << player1.positionComponent->getDestRect().w << std::endl;
	std::cout << "h: " << player1.positionComponent->getDestRect().h << std::endl;

	SDL_Rect rect = player1.positionComponent->getDestRect();

	std::cout << "SDL_Rect.x: " << rect.x << std::endl;
	std::cout << "SDL_Rect.y: " << rect.y << std::endl;
	std::cout << "SDL_Rect.w: " << rect.w << std::endl;
	std::cout << "SDL_Rect.h: " << rect.h << std::endl;

	player1.movementComponent->setVelocity(18, 19);
	std::cout << "xVelocity: " << player1.movementComponent->getXVelocity() << std::endl;
	std::cout << "yVelocity: " << player1.movementComponent->getYVelocity() << std::endl;

	player1.scoreComponent->setScore(20);
	std::cout << "score: " << player1.scoreComponent->getScore() << std::endl;

	player1.animationComponent->setFirstTexturePosition(21, 22, 23, 24);
	std::cout << "x: " << player1.animationComponent->getFirstTexturePosition().x << std::endl;
	std::cout << "y: " << player1.animationComponent->getFirstTexturePosition().y << std::endl;
	std::cout << "w: " << player1.animationComponent->getFirstTexturePosition().w << std::endl;
	std::cout << "h: " << player1.animationComponent->getFirstTexturePosition().h << std::endl;

	player1.animationComponent->setNoOfFramInAnimation(25);
	std::cout << "noOfFrameInAnimation: " << player1.animationComponent->getNoOfFrameInAnimaiton() << std::endl;
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

void testMessageBus() {
	std::cout << "Testing Message Bus" << std::endl;

	while(true)
	{
		post();
		receive();
	}
	//std::cout << msgBus->getMessageType() << std::endl;
}

int main(int argc, char* argv[]){
	(void) argc;
	(void) argv;

	/* testTimeFramework(); */
	testGameObject();
	/* testMessageBus(); */

	return 0;
}


