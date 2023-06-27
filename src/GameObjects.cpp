#include "GameObjects.hpp"

// Do not look at this for documentaion, documentaion available in header file GameObjects.hpp

void StationaryGameObject::setSrcRect(int srcX, int srcY, int srcW, int srcH) {
	srcRect.x = srcX;
	srcRect.y = srcY;
	srcRect.w = srcW;
	srcRect.h = srcH;
}

SDL_Rect StationaryGameObject::getSrcRect() {
	return srcRect;
}

void StationaryGameObject::setDestRect(int destX, int destY, int destW, int destH) {
	destRect.x = destX;
	destRect.y = destY;
	destRect.w = destW;
	destRect.h = destH;
}

SDL_Rect StationaryGameObject::getDestRect() {
	return destRect;
}

void MovableGameObject::setVelocity(int xVelocity, int yVelocity) {
	this->xVelocity = xVelocity;
	this->yVelocity = yVelocity;
}

int MovableGameObject::getXVelocity() {
	return xVelocity;
}

int MovableGameObject::getYVelocity() {
	return yVelocity;
}

void AnimatableGameObject::setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) {
	firstTexturePosition.x = xOfFirstTex;
	firstTexturePosition.y = yOfFirstTex;
	firstTexturePosition.w = wOfFirstTex;
	firstTexturePosition.h = hOfFirstTex;
}

void AnimatableGameObject::setNoOfFramInAnimation(int noOfFrameInAnimation) {
	this->noOfFrameInAnimation = noOfFrameInAnimation;
}

SDL_Rect AnimatableGameObject::getFirstTexturePosition() {
	return firstTexturePosition;
}

int AnimatableGameObject::getNoOfFrameInAnimaiton() {
	return noOfFrameInAnimation;
}
