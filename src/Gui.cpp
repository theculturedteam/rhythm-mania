#include "Gui.hpp"

Gui::Gui(){
    textFont = TTF_OpenFont("../res/fonts/Hooverville-ymK3.ttf", 18);
    color = { 0xFF, 0xFF, 0xFF, 0xFF};
}

void Gui::setPosition(int xint, int yint, int wint, int hint){
    font1.position.x = xint;
    font1.position.y = yint;
    font1.position.w = wint;
    font1.position.h = hint;
}

GameObject* Gui::drawText(int xint, int yint , int wint , int hint, const char* text){
    textButton = new GameObject("texture", "position", nullptr);
    setPosition(xint, yint, wint, hint);
    sText = TTF_RenderText_Blended(textFont, text, color);
    font1.texture = instance.ConvertTexture(sText);
    index = instance.addTexture(font1.texture);
    textButton->texturePositionComponent->setIndex(index);
    return textButton;
}

GameObject* Gui::drawButton(){
    return nullptr;
}



