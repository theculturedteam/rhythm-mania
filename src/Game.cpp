#include "Game.hpp"
#include "GameLogic.hpp"
#include "data/playData.hpp"
#include "system/VideoSystem.hpp"
#include "Gui.hpp"

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
    while(isRunning)
    {
        Time::sGetInstance().calculateDeltaTime();
        inputSystem.update();
        videoSystem.update();
        renderSystem.update();
        soundSystem.update();
        gameLogic.update();
    }

    //while(true)
    //{
        //gameLogic.displayEndScreen();
        //inputSystem.update();
        //videoSystem.update();
        //renderSystem.update();
        //soundSystem.update();
    //}
}
