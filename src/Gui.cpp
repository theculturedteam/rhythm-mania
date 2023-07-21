#include "Gui.hpp"

Gui::Gui(){
    Font font1;
    instance = Draw::getInstance();
}

Gui::setPosition(int xint, int yint, int wint, int hint){
    font1.position.x = xint;
    font1.position.y = yint;
    font1.position.w = wint;
    font1.position.h = hint;
}

Gui::drawText(){
    text = Draw::ConvertTexture(sText);
    
}