#pragma once
#include <SDL_rect.h>
#include <iostream>

// Provides the size and position of texture in the texture atlas
class TexturePositionComponent {
	private:
		SDL_Rect srcRect;

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH);
		SDL_Rect& getSrcRect();
};

// Provides the position of game objects in window
class PositionComponent {
	private:
		SDL_Rect destRect;

	public:
		void setDestRect(float destX, float destY, float destW, float destH);
		SDL_Rect& getDestRect();
};

// Provides movement parameters
class MovementComponent {
	private:
		int xVelocity = 0, yVelocity = 0;

	public:
		void setVelocity(int xVelocity, int yVelocity);

		int& getXVelocity();
		int& getYVelocity();
};

// Provides score parameter
class ScoreComponent {
	private:
		int score;

	public:
		void setScore(int score);

		int& getScore();
};

// Provides animation related parameters
class AnimationComponent {
	private:
		// Position and size of the first texture for animation
		SDL_Rect firstTexturePosition;
		int noOfFrameInAnimation;

	public:
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex);
		void setNoOfFramInAnimation(int noOfFrameInAnimation);

		SDL_Rect& getFirstTexturePosition();
		int& getNoOfFrameInAnimaiton();
};

// Actual class all the game objects are made up of
class GameObject {
	public:
		// pointers for each component class
		TexturePositionComponent* texturePositionComponent = nullptr;
		PositionComponent* positionComponent = nullptr;
		MovementComponent* movementComponent = nullptr;
		ScoreComponent* scoreComponent = nullptr;
		AnimationComponent* animationComponent = nullptr;

	public:
		// take dynamic no of const char* arguments
		// needs to be ended with a nullptr
		// Eg, GameObject background("texture", "position", nullptr)
		GameObject(const char* format...);
		~GameObject();
};

