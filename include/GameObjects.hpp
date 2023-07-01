#pragma once
#include <initializer_list>
#include <string>

// Similar to SDL_Rect
struct PositionAndDimensionStruct {
	int x;
	int y;
	int w;
	int h;
};

// Provides the size and position of texture in the texture atlas
class TexturePositionComponent {
	private:
		PositionAndDimensionStruct srcRect;

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH);
		PositionAndDimensionStruct& getSrcRect();

		std::string getComponentType() {return "texture";};
};

// Provides the position of game objects in window
class PositionComponent {
	private:
		PositionAndDimensionStruct destRect;

	public:
		void setDestRect(int destX, int destY, int destW, int destH);
		PositionAndDimensionStruct& getDestRect();

		std::string getComponentType() {return "position";};

};

// Provides movement parameters
class MovementComponent {
	private:
		int xVelocity = 0, yVelocity = 0;

	public:
		void setVelocity(int xVelocity, int yVelocity);

		int& getXVelocity();
		int& getYVelocity();

		std::string getComponentType() {return "movement";};
};

// Provides score parameter
class ScoreComponent {
	private:
		int score;

	public:
		void setScore(int score);

		int& getScore();

		std::string getComponentType() {return "score";};

};

// Provides animation related parameters
class AnimationComponent {
	private:
		// Position and size of the first texture for animation
		PositionAndDimensionStruct firstTexturePosition;
		int noOfFrameInAnimation;

	public:
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex);
		void setNoOfFramInAnimation(int noOfFrameInAnimation);

		PositionAndDimensionStruct& getFirstTexturePosition();
		int& getNoOfFrameInAnimaiton();

		std::string getComponentType() {return "animation";};

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

