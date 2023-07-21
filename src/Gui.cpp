#include "Gui.hpp"

Gui::Gui(){
    textFont = TTF_OpenFont("../res/fonts/Hooverville-ymK3.ttf", 36);
    color = { 0xFF, 0xFF, 0xFF, 0xFF};
}

GameObject* Gui::drawText(int xint, int yint, const char* text){
    textButton = new GameObject("texture", "position", nullptr);
    sText = TTF_RenderText_Solid(textFont, text, color);
    textButton->texturePositionComponent->setSrcRect(0, 0, sText->w, sText->h);
    textButton->positionComponent->setDestRect(xint, yint, sText->w, sText->h);
    font1.texture = instance.ConvertTexture(sText);
    index = instance.addTexture(font1.texture);
    textButton->texturePositionComponent->setIndex(index);
    return textButton;
}

GameObject* Gui::drawButton(){
    
    return nullptr;
}



