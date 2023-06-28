#include "GameObjects.hpp"

// Do not look at this for documentaion, documentaion available in header file GameObjects.hh

void TexturePositionComponent::setSrcRect(int srcX, int srcY, int srcW, int srcH) {
	srcRect.x = srcX;
	srcRect.y = srcY;
	srcRect.w = srcW;
	srcRect.h = srcH;
}

PositionAndDimensionStruct TexturePositionComponent::getSrcRect() {
	return srcRect;
}

void PositionComponent::setDestRect(int destX, int destY, int destW, int destH) {
	destRect.x = destX;
	destRect.y = destY;
	destRect.w = destW;
	destRect.h = destH;
}

PositionAndDimensionStruct PositionComponent::getDestRect() {
	return destRect;
}

void MovementComponent::setVelocity(int xVelocity, int yVelocity) {
	this->xVelocity = xVelocity;
	this->yVelocity = yVelocity;
}

int MovementComponent::getXVelocity() {
	return xVelocity;
}

int MovementComponent::getYVelocity() {
	return yVelocity;
}

void ScoreComponent::setScore(int score) {
	this->score = score;
}

int ScoreComponent::getScore() {
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

PositionAndDimensionStruct AnimationComponent::getFirstTexturePosition() {
	return firstTexturePosition;
}

int AnimationComponent::getNoOfFrameInAnimaiton() {
	return noOfFrameInAnimation;
}
