#include "system/RenderSystem.hpp"

Render:: Render(MessageBus* msgBus, std::vector<GameObject*>* gameobjects):System(msgBus), gameObjects(gameobjects){
    // this->gameObjects = gameObjects;
    instance.LoadTexture("../res/images/arrow_down.png"); //path of the texture(atlas)
}

void Render::update(){
    instance.ClearTexture();
    for(GameObject* gameobj : *gameObjects){
        if(gameobj->animationComponent != nullptr){
            //animation part from atlas(will implement later..)
        }
        else if(gameobj->positionComponent != nullptr && gameobj->texturePositionComponent != nullptr){
            srcRect = gameobj->texturePositionComponent->getSrcRect();
            dstRect = gameobj->positionComponent->getDestRect();
            convert(srcRect, dstRect);
            instance.CopyTexture(src,dst);
        }
        else{
            std::cout << "Game Object does not meet requirements to render on screen"<< std::endl;
            return;
        }
    }
    instance.PresentTexture();
}


void Render::convert(PositionAndDimensionStruct srcRect, PositionAndDimensionStruct dstRect){
    src.x = srcRect.x;
    src.y = srcRect.y;
    src.w = srcRect.w;
    src.h = srcRect.h;
    dst.x = dstRect.x;
    dst.y = dstRect.y;
    dst.w = dstRect.w;
    dst.h = dstRect.h;
}

Render::~Render(){
    instance.DestroySDL();
}