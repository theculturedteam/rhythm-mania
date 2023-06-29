#pragma once
#include <string>
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
	public:
		virtual ~BaseComponent();
		virtual std::string getComponentType() = 0;

	public:
		virtual void setSrcRect(int srcX, int srcY, int srcW, int srcH) = 0;
		virtual PositionAndDimensionStruct& getSrcRect() = 0;
		virtual void setDestRect(int destX, int destY, int destW, int destH) = 0;
		virtual PositionAndDimensionStruct& getDestRect() = 0;
		virtual void setVelocity(int xVelocity, int yVelocity) = 0;
		virtual int& getXVelocity() = 0;
		virtual int& getYVelocity() = 0;
		virtual void setScore(int score) = 0;
		virtual int& getScore() = 0;
		virtual void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) = 0;
		virtual void setNoOfFramInAnimation(int noOfFrameInAnimation) = 0;
		virtual PositionAndDimensionStruct& getFirstTexturePosition() = 0;
		virtual int& getNoOfFrameInAnimaiton() = 0;
};

// Provides the size and position of texture in the texture atlas
class TexturePositionComponent : public BaseComponent {
	private:
		PositionAndDimensionStruct srcRect;

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH) override;
		PositionAndDimensionStruct& getSrcRect() override;

		std::string getComponentType() override {return "texture";};

	public:
		void setDestRect(int destX, int destY, int destW, int destH) override;
		PositionAndDimensionStruct& getDestRect() override;
		void setVelocity(int xVelocity, int yVelocity) override;
		int& getXVelocity() override;
		int& getYVelocity() override;
		void setScore(int score) override;
		int& getScore() override;
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) override;
		void setNoOfFramInAnimation(int noOfFrameInAnimation) override;
		PositionAndDimensionStruct& getFirstTexturePosition() override;
		int& getNoOfFrameInAnimaiton() override;
};

// Provides the position of game objects in window
class PositionComponent : public BaseComponent {
	private:
		PositionAndDimensionStruct destRect;

	public:
		void setDestRect(int destX, int destY, int destW, int destH) override;
		PositionAndDimensionStruct& getDestRect() override;

		std::string getComponentType() override {return "position";};

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH) override;
		PositionAndDimensionStruct& getSrcRect() override;
		void setVelocity(int xVelocity, int yVelocity) override;
		int& getXVelocity() override;
		int& getYVelocity() override;
		void setScore(int score) override;
		int& getScore() override;
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) override;
		void setNoOfFramInAnimation(int noOfFrameInAnimation) override;
		PositionAndDimensionStruct& getFirstTexturePosition() override;
		int& getNoOfFrameInAnimaiton() override;
};

// Provides movement parameters
class MovementComponent : public BaseComponent {
	private:
		int xVelocity = 0, yVelocity = 0;

	public:
		void setVelocity(int xVelocity, int yVelocity) override;

		int& getXVelocity() override;
		int& getYVelocity() override;

		std::string getComponentType() override {return "movement";};

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH) override;
		PositionAndDimensionStruct& getSrcRect() override;
		void setDestRect(int destX, int destY, int destW, int destH) override;
		PositionAndDimensionStruct& getDestRect() override;
		void setScore(int score) override;
		int& getScore() override;
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) override;
		void setNoOfFramInAnimation(int noOfFrameInAnimation) override;
		PositionAndDimensionStruct& getFirstTexturePosition() override;
		int& getNoOfFrameInAnimaiton() override;
};

// Provides score parameter
class ScoreComponent : public BaseComponent {
	private:
		int score;

	public:
		void setScore(int score) override;

		int& getScore() override;

		std::string getComponentType() override {return "score";};

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH) override;
		PositionAndDimensionStruct& getSrcRect() override;
		void setDestRect(int destX, int destY, int destW, int destH) override;
		PositionAndDimensionStruct& getDestRect() override;
		void setVelocity(int xVelocity, int yVelocity) override;
		int& getXVelocity() override;
		int& getYVelocity() override;
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) override;
		void setNoOfFramInAnimation(int noOfFrameInAnimation) override;
		PositionAndDimensionStruct& getFirstTexturePosition() override;
		int& getNoOfFrameInAnimaiton() override;
};

// Provides animation related parameters
class AnimationComponent : public BaseComponent {
	private:
		// Position and size of the first texture for animation
		PositionAndDimensionStruct firstTexturePosition;
		int noOfFrameInAnimation;

	public:
		void setFirstTexturePosition(int xOfFirstTex, int yOfFirstTex, int wOfFirstTex, int hOfFirstTex) override;
		void setNoOfFramInAnimation(int noOfFrameInAnimation) override;

		PositionAndDimensionStruct& getFirstTexturePosition() override;
		int& getNoOfFrameInAnimaiton() override;

		std::string getComponentType() override {return "animation";};

	public:
		void setSrcRect(int srcX, int srcY, int srcW, int srcH) override;
		PositionAndDimensionStruct& getSrcRect() override;
		void setDestRect(int destX, int destY, int destW, int destH) override;
		PositionAndDimensionStruct& getDestRect() override;
		void setVelocity(int xVelocity, int yVelocity) override;
		int& getXVelocity() override;
		int& getYVelocity() override;
		void setScore(int score) override;
		int& getScore() override;
};

// Actual class all the game objects are made up of
class GameObject {
	private:
		std::vector<BaseComponent*> components;

	public:
		void addComponent(BaseComponent* component);

		std::vector<BaseComponent*>& getVector();
};

