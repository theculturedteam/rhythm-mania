#pragma once
#include "MessageBus.hpp"
#include "GameObjects.hpp"
#include "Gui.hpp"
#include "data/playData.hpp"

class MainMenu{
	private:
		MessageBus* msgBus;
		std::vector<GameObject*>* gameObjects;
		bool* isInMenu;

        std::vector<PlayData*> playDatas;

	public:
        MainMenu(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isRunning, std::vector<PlayData*> playDatas);
        ~MainMenu();

		void drawMenu();
};
