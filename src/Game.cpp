#include "Game.hpp"
#include "GameLogic.hpp"
#include "data/playData.hpp"
#include "system/VideoSystem.hpp"
#include "Gui.hpp"

Game ::Game()
    : renderSystem(&msgBus, &gameObjects), inputSystem(&msgBus), gameLogic(&msgBus, &gameObjects, &isRunning), soundSystem(&msgBus), videoSystem(&msgBus)
{
    isRunning = true;
    int songNo;

    std::cout << "Select Song: ";
    std::cin >> songNo;

    // amrit's music
    // sData = new SoundData();
    // sData->setdata("play", "../res/audio/music1.wav");
    // vData = new VideoData()

    switch (songNo)
    {
    case 1:
        plData = new PlayData(0.25, "Beethoven Virus", "../res/audio/beethoven.wav", "../res/videos/beethoven-virus", "../beatmap/beethoven.txt", 1409, 30, 854, 480);
        break;
    case 2:
        plData = new PlayData(0.25, "Amrit Song", "../res/audio/music1.wav", "../res/videos/beethoven-virus", "../beatmap/music1.txt", 1409, 30, 854, 480);
        break;
    case 3:
        plData = new PlayData(0.25, "Chika Dance", "../res/audio/chika-dance.wav", "../res/videos/chika-dance", "../beatmap/chika-dance.txt", 2835, 30, 854, 480);
        break;
    default:
        plData = new PlayData(0.25, "Beethoven Virus", "../res/audio/beethoven.wav", "../res/videos/beethoven-virus", "../beatmap/beethoven.txt", 1409, 30, 854, 480);
    }
    // beethoven
    playDatas.push_back(plData);

    // fujiwara
    // plData = new PlayData(0.25, "Fujiwara Dance", "../res/audio/);
}

Game ::~Game()
{
}

Game ::~Game()
{
}

void Game ::run()
{
    gameLogic.start(plData);
    Time::sGetInstance().setPreviousTime();
    while (isRunning)
    {
        Time::sGetInstance().calculateDeltaTime();
        std::cout << "dt: " << Time::sGetInstance().getDeltaTime() << std::endl;
        inputSystem.update();
        videoSystem.update();
        renderSystem.update();
        soundSystem.update();
        gameLogic.update();
    }

    // while(true)
    //{
    // gameLogic.displayEndScreen();
    // inputSystem.update();
    // videoSystem.update();
    // renderSystem.update();
    // soundSystem.update();
    //}
}
