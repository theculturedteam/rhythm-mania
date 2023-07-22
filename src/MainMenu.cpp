#include "MainMenu.hpp"

MainMenu::MainMenu(MessageBus* msgBus, std::vector<GameObject*>* gameObjects, bool* isInMenu, std::vector<PlayData*> playDatas) 
	:msgBus(msgBus), gameObjects(gameObjects), isInMenu(isInMenu), playDatas(playDatas)
{
}

void MainMenu::drawMenu() {
	Gui gui;
	gui.drawText(640, 0, "RHYTHM MANIA");

	for (PlayData* playData : playDatas) {
		static uint8_t yint = 100;
		gui.drawButton(640, yint, playData->title.c_str());
		yint += 70;
	}

}
