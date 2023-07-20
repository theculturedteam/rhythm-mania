#include "GameObjects.hpp"

void TexturePositionComponent::setSrcRect(int srcX, int srcY, int srcW, int srcH) {
	srcRect.x = srcX;
	srcRect.y = srcY;
	srcRect.w = srcW;
	srcRect.h = srcH;
}

PositionAndDimensionStruct& TexturePositionComponent::getSrcRect() {
	return srcRect;
}

void PositionComponent::setDestRect(float destX, float destY, float destW, float destH) {
	destRect.x = destX;
	destRect.y = destY;
	destRect.w = destW;
	destRect.h = destH;
}

PositionAndDimensionStruct& PositionComponent::getDestRect() {
	return destRect;
}

void MovementComponent::setVelocity(int xVelocity, int yVelocity) {
	this->xVelocity = xVelocity;
	this->yVelocity = yVelocity;
}

int& MovementComponent::getXVelocity() {
	return xVelocity;
}

int& MovementComponent::getYVelocity() {
	return yVelocity;
}

void ScoreComponent::setScore(int score) {
	this->score = score;
}

int& ScoreComponent::getScore() {
	return score;
}

void AnimationComponent::setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) {
	firstTexturePosition.x = xOfFirstTex;
	firstTexturePosition.y = yOfFirstTex;
	firstTexturePosition.w = wOfFirstTex;
	firstTexturePosition.h = hOfFirstTex;
}

void AnimationComponent::setNoOfFramInAnimation(int noOfFrameInAnimation) {
	this->noOfFrameInAnimation = noOfFrameInAnimation;
}

PositionAndDimensionStruct& AnimationComponent::getFirstTexturePosition() {
	return firstTexturePosition;
}

int& AnimationComponent::getNoOfFrameInAnimaiton() {
	return noOfFrameInAnimation;
}

GameObject::GameObject(const char* format...) {
	// Macros from <cstdarg> that are used to access and process variable arguments
	va_list args;
	va_start(args, format);

	// takes the first argument
	const char* component = format;
	while (component != nullptr) {
		/* std::cout << component << std::endl; */
		if (strcmp(component, "texture") == 0) {
			texturePositionComponent = new TexturePositionComponent();
			/* std::cout << "Created texturePositionComponent" << std::endl; */
		} 
		else if (strcmp(component, "position") == 0) {
			positionComponent = new PositionComponent();
			/* std::cout << "Created positionComponent" << std::endl; */
		} 
		else if (strcmp(component, "movement") == 0) {
			movementComponent = new MovementComponent();
			/* std::cout << "Created movementComponent" << std::endl; */
		} 
		else if (strcmp(component, "score") == 0) {
			scoreComponent = new ScoreComponent();
			/* std::cout << "Created scoreComponent" << std::endl; */
		} 
		else if (strcmp(component, "animation") == 0) {
			animationComponent = new AnimationComponent();
			/* std::cout << "Created animationComponent" << std::endl; */
		} 
		else {
			std::cout << "Not a valid component" << std::endl;
		}

		// sets component to the next argument
		component = va_arg(args, const char*);
	}

	va_end(args);
}

GameObject::~GameObject() {
	delete texturePositionComponent;
	texturePositionComponent = NULL;
	delete positionComponent;
	positionComponent = NULL;
	delete movementComponent;
	movementComponent = NULL;
	delete scoreComponent;
	scoreComponent = NULL;
	delete animationComponent;
	animationComponent = NULL;
}
