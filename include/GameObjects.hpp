#pragma once
#include <vector>

// Similar to SDL_Rect
struct PositionAndDimensionStruct {
	int x;
	int y;
	int w;
	int h;
};

// Abstract class for all other class to inherit so that game objects can be made up of vector of BaseComponent class pointers
class BaseComponent {
	private:
		virtual void emptyFunction() = 0;
};

// Provides the size and position of texture in the texture atlas
class TexturePositionComponent : public BaseComponent {
	private:
		void emptyFunction() {};
		PositionAndDimensionStruct srcRect;

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH);
		PositionAndDimensionStruct getSrcRect();
};

// Provides the position of game objects in window
class PositionComponent : public BaseComponent {
	private:
		void emptyFunction() {};
		PositionAndDimensionStruct destRect;

	public:
		void setDestRect(int destX, int destY, int destW, int destH);

		PositionAndDimensionStruct getDestRect();

};

// Provides movement parameters
class MovementComponent : public BaseComponent {
	private:
		void emptyFunction() {};
		int xVelocity = 0, yVelocity = 0;

	public:
		void setVelocity(int xVelocity, int yVelocity);

		int getXVelocity();
		int getYVelocity();

};

// Provides score parameter
class ScoreComponent : public BaseComponent {
	private:
		void emptyFunction() {};
		int score;

	public:
		void setScore(int score);

		int getScore();
};

// Provides animation related parameters
class AnimationComponent : public BaseComponent {
	private:
		void emptyFunction() {};

		// Position and size of the first texture for animation
		PositionAndDimensionStruct firstTexturePosition;
		int noOfFrameInAnimation;

	public:
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex);
		void setNoOfFramInAnimation(int noOfFrameInAnimation);

		PositionAndDimensionStruct getFirstTexturePosition();
		int getNoOfFrameInAnimaiton();

};

// Actual class all the game objects are made up of
class GameObject {
	private:
		std::vector<BaseComponent*> components;
};

