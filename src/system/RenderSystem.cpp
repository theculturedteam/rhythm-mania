#include "system/RenderSystem.hpp"
#include <cmath>

Render:: Render(MessageBus* msgBus, std::vector<GameObject*>* gameobjects):System(msgBus), gameObjects(gameobjects){
    instance.InitializeSDL(); 
    (void)instance.LoadTexture("../res/images/4kAtlas.png"); //path of the texture(atlas)
}

void Render::update(){
    //instance.ClearTexture();
    for(GameObject* gameobj : *gameObjects){
        if(gameobj->animationComponent != nullptr && gameobj->animationComponent->getAnimate()){
			if (gameobj->animationComponent->getCurrentFrame() < gameobj->animationComponent->getNoOfFrameInAnimaiton()) {
				/* std::cout << gameobj->animationComponent->getCurrentFrame() << std::endl; */
				if (std::round(gameobj->animationComponent->getCurrentFrame()) == gameobj->animationComponent->getNoOfFrameInAnimaiton()) {
					gameobj->animationComponent->setAnimate(false);
					gameobj->animationComponent->setCurrentFrame(0);
				}

				src = gameobj->animationComponent->getTexturePosition();
				src = {(int)(133 * std::round(gameobj->animationComponent->getCurrentFrame())), src.y, src.w, src.h};
				dst = gameobj->positionComponent->getDestRect();

				instance.CopyTexture(src, dst, index);

				gameobj->animationComponent->setCurrentFrame(gameobj->animationComponent->getCurrentFrame() + gameobj->animationComponent->getAnimationSpeed() * timeInstance.getDeltaTime());

			}
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
