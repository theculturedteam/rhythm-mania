#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>
class Draw{
	private:
		static Draw& instanceptr;
		Draw(){};

		SDL_Texture* texture;
		SDL_Window* window;
		SDL_Renderer* renderer;

    	const char* path;

		// Temp variable
    	bool isRunning;
    public:
    	Draw(const Draw& obj) = delete;
    	void operator=(Draw const&)  = delete;

    	static Draw& getInstance();

    	void InitializeSDL();

		void LoadTexture(std::string);
    	void CopyTexture(SDL_Rect srcRect, SDL_Rect dstRect);
    	void PresentTexture();
    	void ClearTexture();

    	void DestroySDL();
		
		// Temp function
    	void HandleEvents();
    	bool CheckRunning();
};
