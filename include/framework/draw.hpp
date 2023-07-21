#pragma once
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <unordered_map>
#include <utility>

class Draw {
	private:
		Draw(){};

		SDL_Window* window;
		SDL_Renderer* renderer;

    	const char* path;

		std::unordered_map<int, SDL_Texture*> textureMap;
		int mapIndex = -1;

		// Temp variable
    	bool isRunning = false;

    public:
    	Draw(Draw const&) = delete;
    	void operator=(Draw const&)  = delete;

    	static Draw& getInstance();

    	bool InitializeSDL();

		int LoadTexture(const char* path);
    	void CopyTexture(SDL_Rect srcRect, SDL_Rect dstRect, int key);
    	void PresentTexture();
    	void ClearTexture();

    	void DestroySDL();

		void DestroyTexture(int key);

		void DimBackground(uint8_t alpha);
		
		SDL_Texture* ConvertTexture(SDL_Surface* surface);

		uint16_t addTexture(SDL_Texture* texture);

		// Temp function
    	void HandleEvents();
    	bool CheckRunning();
};
