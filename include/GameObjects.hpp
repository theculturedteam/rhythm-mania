#pragma once
#include <SDL_rect.h>

// For game objects like background, stationary arrows etc that do not need to move
// Also other classes inherit from this class, so this provides source texture and
// destination for that texture
class StationaryGameObject {
	private:
		SDL_Rect srcRect, destRect;
	public:
		// this sets the x, y coordinate for the top left pixel of source textute
		// and also its width and height which is later used by RenderCopy
		// to display that texture
		void setSrcRect(int srcX, int srcY, int srcW, int srcH);
		// this sets the x, y coordinate for the top left pixel of destination in
		//
		void setDestRect(int destX, int destY, int destW, int destH);

		SDL_Rect getSrcRect();
		SDL_Rect getDestRect();
};


// For game objects like moving arrows, that are movable but also do not need to be 
// animated, for both movable and animated objects use MovableAndAnimatableGameObject
// as described below
class MovableGameObject : public StationaryGameObject {
	private:
		int xVelocity = 0, yVelocity = 0;
	public:
		void setVelocity(int xVelocity, int yVelocity);

		int getXVelocity();
		int getYVelocity();
};

// For game objects like ideal NPC, that have animations but do not move
class AnimatableGameObject : public StationaryGameObject {
	private:
		SDL_Rect firstTexturePosition;
		int noOfFrameInAnimation;
	public:
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex);
		void setNoOfFramInAnimation(int noOfFrameInAnimation);

		SDL_Rect getFirstTexturePosition();
		int getNoOfFrameInAnimaiton();
};

// For game objects that move and also have animations
class MovableAndAnimatableGameObject : public MovableGameObject , public AnimatableGameObject {
};
