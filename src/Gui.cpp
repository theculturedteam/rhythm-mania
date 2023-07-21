 #include "Gui.hpp"

Gui::Gui(){
    textFont = TTF_OpenFont("../res/fonts/Hooverville-ymK3.ttf", 65);
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

// GameObject* Gui::drawButton(int xint, int yint, const char* text){
//     textButton = new GameObject("texture", "position", nullptr);
//     sText = TTF_RenderText_Solid(textFont, text, color);// this text
//     SDL_Surface* button = IMG_Load("../res.images/4kAtlas.png");
//     SDL_Surface* combined = SDL_CreateRGBSurface(0, 512, 128, 32, 0, 0, 0, 0);
//     SDL_Rect dstRect = {0, 0, 512, 128};
//     SDL_Rect srcRectButton ={0, 1577, 512, 128};    
//     SDL_BlitSurface(button, &srcRectButton, combined, &dstRect);
//     SDL_BlitSurface(sText, NULL, combined, &dstRect);
//     textButton->texturePositionComponent->setSrcRect(0, 0, combined->w, combined->h);
//     textButton->positionComponent->setDestRect(xint, yint, 512, 128);
//     font1.texture = instance.ConvertTexture(combined);
//     index = instance.addTexture(font1.texture);
//     textButton->texturePositionComponent->setIndex(index);
//     SDL_FreeSurface(button);
//     SDL_FreeSurface(sText);
//     return textButton;
// }

GameObject* Gui::drawButton(int xint, int yint, const char* text) {
    textButton = new GameObject("texture", "position", nullptr);
    sText = TTF_RenderText_Solid(textFont, text, color);

    SDL_Surface* button = IMG_Load("../res/images/button.png");

    if(button == NULL){
        std::cout << "You are fucked" << std::endl;
    }
    SDL_Rect dstRect = {button->w / 2 - sText->w/2, button->h/2 - sText->h/2, sText->w, sText->h};
    SDL_BlitSurface(sText, NULL, button, &dstRect);
    auto texture = instance.ConvertTexture(button);
    auto index = instance.addTexture(texture);

    textButton->texturePositionComponent->setSrcRect(0, 0, 512, 128);
    textButton->texturePositionComponent->setIndex(index);
    textButton->positionComponent->setDestRect(xint, yint, 512, 128);
    SDL_FreeSurface(sText);
    return textButton;
}








