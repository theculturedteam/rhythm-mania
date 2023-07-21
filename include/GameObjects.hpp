#pragma once
#include <SDL_rect.h>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <cstring>

// Similar to PositionAndDimensionStruct
struct PositionAndDimensionStruct {
	float x;
	float y;
	float w;
	float h;

	//overloading operator overloading to automatically convert PositionAndDimensionStruct to SDL_Rect
	operator SDL_Rect() const {
		SDL_Rect rect;
		rect.x = round(x);
        rect.y = round(y);
        rect.w = round(w);
        rect.h = round(h);
        return rect;
	}
};

// Provides the size and position of texture in the texture atlas
class TexturePositionComponent {
	private:
		PositionAndDimensionStruct srcRect;
		uint16_t index = 0;

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH);
		void setIndex(uint16_t index);

		PositionAndDimensionStruct& getSrcRect();
		uint16_t getIndex();
};

// Provides the position of game objects in window
class PositionComponent {
	private:
		PositionAndDimensionStruct destRect;

	public:
		void setDestRect(float destX, float destY, float destW, float destH);
		PositionAndDimensionStruct& getDestRect();
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
		PositionAndDimensionStruct firstTexturePosition;
		int noOfFrameInAnimation;
		uint8_t animationSpeed;
		bool animate = false;

	public:
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex);
		void setNoOfFramInAnimation(int noOfFrameInAnimation);
		void setAnimationSpeed(uint8_t animationSpeed);
		void setAnimate(bool animate);

		PositionAndDimensionStruct& getFirstTexturePosition();
		int& getNoOfFrameInAnimaiton();
		uint8_t& getAnimationSpeed();
		bool& getAnimate();
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

		uint32_t objectId = 0;

	public:
		// take dynamic no of const char* arguments
		// needs to be ended with a nullptr
		// Eg, GameObject background("texture", "position", nullptr)
		GameObject(const char* format...);
		~GameObject();

		void setObjectId(uint32_t objectId);
		uint32_t getObjectId();
};

