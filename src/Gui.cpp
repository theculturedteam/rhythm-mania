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

// GameObject* Gui::drawButton(int xint, int yint, const char* text){
//     textButton = new GameObject("texture", "position", nullptr);
//     sText = TTF_RenderText_Solid(textFont, text, color);// this text
//     SDL_Surface* button = IMG_Load("../res.images/4kAtlas.png");
//     SDL_Surface* combined = SDL_CreateRGBSurface(0, 512, 128, 32, 0, 0, 0, 0);
//     SDL_Rect dstRect = {0, 0, 512, 128};
//     SDL_Rect srcRectButton = {0, 1577, 512, 128};    
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

    SDL_Surface* button = IMG_Load("../res/images/4kAtlas.png");

    if(button == NULL){
        std::cout << "You are fucked" << std::endl;
    }
    SDL_Surface* combined = SDL_CreateRGBSurface(0, 512, 128, 32, 255, 255, 255, 255);

    SDL_Rect srcRectButton = { 0, 1577, 512, 128 };
    SDL_Rect dstRectButton = { 0, 0, 512, 128 };
    SDL_BlitSurface(button, &srcRectButton, combined, &dstRectButton);

    // int textX = (512 - sText->w) / 2; // Center horizontally
    // int textY = (128 - sText->h) / 2; // Center vertically

    SDL_Rect buttonDstRectText = { 0, 0, sText->w, sText->h };
    SDL_BlitSurface(sText, &buttonDstRectText, combined, &dstRectButton);

    textButton->texturePositionComponent->setSrcRect(0, 0, 512, 128);
    std::cout << "Here" << std::endl;
    textButton->positionComponent->setDestRect(xint, yint, 512, 128);


    font1.texture = instance.ConvertTexture(combined);
    index = instance.addTexture(font1.texture);
    textButton->texturePositionComponent->setIndex(index);

    SDL_FreeSurface(button);
    SDL_FreeSurface(sText);

    return textButton;
}








