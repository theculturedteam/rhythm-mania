#include "Game.hpp"
#include "GameLogic.hpp"
#include "data/playData.hpp"
#include "system/VideoSystem.hpp"

Game :: Game()
    :renderSystem(&msgBus, &gameObjects), inputSystem(&msgBus), gameLogic(&msgBus, &gameObjects, &isRunning), soundSystem(&msgBus), videoSystem(&msgBus)
{
    isRunning = true;

    
    PlayData* plData;
    //amrit's music
    //sData = new SoundData();
    //sData->setdata("play", "../res/audio/music1.wav");
    //vData = new VideoData()
    
    //beethoven
    plData = new PlayData(0.25, "Beethoven Virus", "../res/audio/beethoven.wav", "../res/videos/beethoven-virus", 1409, 30, 854, 480);
    playDatas.push_back(plData);

    //fujiwara
    //plData = new PlayData(0.25, "Fujiwara Dance", "../res/audio/);

}


Game :: ~Game()
{
}

void Game :: run()
{
    gameLogic.start();
    Time::sGetInstance().setPreviousTime();
    testGui();
    while(isRunning)
    {
        Time::sGetInstance().calculateDeltaTime();
        inputSystem.update();
        videoSystem.update();
        renderSystem.update();
        soundSystem.update();
        gameLogic.update();
    }
}

void Game::testGui(){
	Gui gui;
	GameObject* text;
    GameObject* button;
	text = gui.drawText(100, 100, "hello");
    button = gui.drawButton(500, 500, "START GAME");
    // text->positionComponent->setDestRect(200, 200, 100, 100);

    gameObjects.push_back(button);
	gameObjects.push_back(text);
}