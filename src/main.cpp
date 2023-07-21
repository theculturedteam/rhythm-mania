#include <iostream>
#include <SDL.h>
#include "GameObjects.hpp"
#include "framework/time.hpp"
#include "Message.hpp"
#include "MessageBus.hpp"
#include "data/inputData.hpp"
#include "framework/draw.hpp"
#include "system/RenderSystem.hpp"
#include "Game.hpp"
using namespace std;

MessageBus* msgBus = new MessageBus();

// void testTimeFramework() {
// 	std::cout << "Testing Time Framework" << std::endl;
// 	SDL_Init(SDL_INIT_TIMER);

// 	Time& timeInstance = Time::sGetInstance();

// 	timeInstance.setPreviousTime(timeInstance.getCurrentTime());

// 	std::cout << "Previous Time: " << timeInstance.getPreviousTime() << std::endl;

// 	while (true) {
// 		double dt = timeInstance.calculateDeltaTime(timeInstance.getCurrentTime());
// 		std::cout << "dt: " << dt << std::endl;
// 		SDL_Delay(16);
// 	}
// }

void testGameObject() {
	std::cout << "Testing Game Object" << std::endl;
	std::cout << "debug0" << std::endl;
	GameObject player1("texture", "position", "movement", "score", "animation", nullptr);

	player1.texturePositionComponent->setSrcRect(10, 11, 12, 13);
	std::cout << "x: " << player1.texturePositionComponent->getSrcRect().x << std::endl;
	std::cout << "y: " << player1.texturePositionComponent->getSrcRect().y << std::endl;
	std::cout << "w: " << player1.texturePositionComponent->getSrcRect().w << std::endl;
	std::cout << "h: " << player1.texturePositionComponent->getSrcRect().h << std::endl;

	player1.positionComponent->setDestRect(14, 15, 16, 17);
	std::cout << "x: " << player1.positionComponent->getDestRect().x << std::endl;
	std::cout << "y: " << player1.positionComponent->getDestRect().y << std::endl;
	std::cout << "w: " << player1.positionComponent->getDestRect().w << std::endl;
	std::cout << "h: " << player1.positionComponent->getDestRect().h << std::endl;

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

// void testDrawFramework() {
//     Draw &singleton = Draw::getInstance();

//     singleton.InitializeSDL();

//     SDL_Rect srcRect;
//     SDL_Rect dstRect;
//     srcRect.w = 32;
//     srcRect.h = 32;
//     srcRect.x = 0;
//     srcRect.y = 0;
//     dstRect.w = 64;
//     dstRect.h = 64;
//     dstRect.x = 500;
//     dstRect.y = 500;

//     bool isRunning = singleton.CheckRunning();
//     singleton.LoadTexture("../res/images/arrow_left.png");
//     while (isRunning)
//     {
//         singleton.HandleEvents();
//         // singleton->sFullScreenDraw("../res/images/healthbar1.png", srcRect, dstRect);

//         singleton.DrawTexture( srcRect, dstRect);
//         isRunning = singleton.CheckRunning();
//     }
//     singleton.DestroySDL();
// }


void testRenderSystem(){

	GameObject* arrow1 = new GameObject("position", "texture", nullptr);
	GameObject* arrow2 = new GameObject("position", "texture", nullptr);
	GameObject* arrow3 = new GameObject("position", "texture", nullptr);
	GameObject* arrow4 = new GameObject("position", "texture",nullptr);
	GameObject* arrow1glow = new GameObject("position","texture",nullptr);
	GameObject* arrow2glow = new GameObject("position","texture",nullptr);
	GameObject* arrow3glow = new GameObject("position","texture",nullptr);
	GameObject* arrow4glow = new GameObject("position","texture",nullptr);
	GameObject* gui = new GameObject("position","texture",nullptr);

	arrow1->texturePositionComponent->setSrcRect(0, 533 , 128, 128);
	arrow1->positionComponent->setDestRect(100, 100, 128, 128);
	arrow2->texturePositionComponent->setSrcRect(0, 666 , 128, 128);
	arrow2->positionComponent->setDestRect(300, 100, 128, 128);
	arrow3->texturePositionComponent->setSrcRect(0, 799, 128, 128);
	arrow3->positionComponent->setDestRect(500, 100, 128, 128);
	arrow4->texturePositionComponent->setSrcRect(0, 932, 128, 128);
	arrow4->positionComponent->setDestRect(700, 100, 128, 128);
	arrow1glow->texturePositionComponent->setSrcRect(133, 0, 128, 128);
	arrow1glow->positionComponent->setDestRect(100, 300, 128, 128);
	arrow2glow->texturePositionComponent->setSrcRect(133, 133, 128, 128);
	arrow2glow->positionComponent->setDestRect(300, 300, 128, 128);
	arrow3glow->texturePositionComponent->setSrcRect(133, 133*2, 128, 128);
	arrow3glow->positionComponent->setDestRect(500, 300, 128, 128);
	arrow4glow->texturePositionComponent->setSrcRect(133, 133*3, 128, 128);
	arrow4glow->positionComponent->setDestRect(700, 300, 128, 128);
	gui->texturePositionComponent->setSrcRect(0, 1577,512, 128);
	gui->positionComponent->setDestRect(100, 500, 512, 128);
	std::vector<GameObject*>* gameobjects = new std::vector<GameObject*>{arrow1, arrow2, arrow3,arrow4, arrow1glow, arrow2glow, arrow3glow, arrow4glow, gui};
	Render renderSystem(msgBus,gameobjects);
	Draw& drawInstance = Draw::getInstance();
	bool checkRunning = drawInstance.CheckRunning();
	while(checkRunning){
		drawInstance.HandleEvents();	
		renderSystem.update();
		checkRunning = drawInstance.CheckRunning();
	}

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

	Game gameInstance;
	gameInstance.run();
	return 0;
}


// void testGui(){
// 	Gui gui;
// 	GameObject* text ;
// 	text = gui.drawText(100, 100, 50 , 50, "hello");
// 	std::vector<GameObject*>* gameObjects =  new std::vector<GameObject*>{text};
// }