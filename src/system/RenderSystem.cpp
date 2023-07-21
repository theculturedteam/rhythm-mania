#include "system/RenderSystem.hpp"

Render:: Render(MessageBus* msgBus, std::vector<GameObject*>* gameobjects):System(msgBus), gameObjects(gameobjects){
    instance.InitializeSDL(); 
    (void)instance.LoadTexture("../res/images/4kAtlas.png"); //path of the texture(atlas)
}

void Render::update(){
    instance.ClearTexture();
    for(GameObject* gameobj : *gameObjects){
        if(gameobj->animationComponent != nullptr){
            //animation part from atlas(will implement later..)
        }
        else if(gameobj->positionComponent != nullptr && gameobj->texturePositionComponent != nullptr){
            index = gameobj->texturePositionComponent->getIndex();
            src = gameobj->texturePositionComponent->getSrcRect();
            dst = gameobj->positionComponent->getDestRect();
            instance.CopyTexture(src,dst,index);
        }
        else{
            return;
        }
    }
    instance.PresentTexture();
}


Render::~Render(){
    instance.DestroyTexture(index);
    instance.DestroySDL();
}
