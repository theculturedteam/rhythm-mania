#include "Gui.hpp"

Gui::Gui(){
    textButton = new GameObject("texture", "position", nullptr);
}

void Gui::setPosition(int xint, int yint, int wint, int hint){
    font1.position.x = xint;
    font1.position.y = yint;
    font1.position.w = wint;
    font1.position.h = hint;
    sText = TTF_RenderText_Blended();
}

GameObject* Gui::drawText(){

    font1.text = instance.ConvertTexture(sText);
    index = instance.addTexture(font1.text);

}



