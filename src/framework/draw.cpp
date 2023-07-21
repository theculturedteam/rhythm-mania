#include "framework/draw.hpp"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

Draw& Draw::getInstance()
{
    static Draw instanceptr;
    return instanceptr;
}

//initializes video,audio and image subsystems of SDL2
bool Draw::InitializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
		isRunning = false;
		return false;
    }

	// load support for the JPG and PNG image formats
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if((initted&flags) != flags) {
		std::cout << "IMG_Init: Failed to init required jpg and png support!" << std::endl;
		std::cout << "IMG_Init: " << IMG_GetError() << std::endl;
		isRunning = false;
		return false;
	}

	if (TTF_Init() == -1) {
		std::cout << "TTF_Init: Failed to init TTF" << std::endl;
		isRunning = false;
		return false;
	}
	
    isRunning = true;

	// Setting window size to 1280 x 720 helps in debugging
	// Removed SDL_WINDOW_RESIZABLE flag because the Window gets Squeezed in i3wm
    window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Enable alpha blending required by DimBackground

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// Clear the entire screen to our selected color.
	// See SDL wiki
    SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

    std::cout << "Game Started" << std::endl;
	return true;
}

//load an image to the gpu texture (SDL_Texture*) Always load texture before using CopyTexture() or PresentTexture() call
int Draw::LoadTexture(const char* path){
	mapIndex++;
	SDL_Texture* texture = IMG_LoadTexture(renderer, path);
	textureMap.insert({mapIndex, texture});
	return mapIndex;
}

//Copy a portion of the texture to the current rendering target.
void Draw::CopyTexture(SDL_Rect srcRect, SDL_Rect dstRect, int key)
{
	if (textureMap.find(key) != textureMap.end()) {
		SDL_RenderCopy(renderer, textureMap.at(key), &srcRect, &dstRect);
	} else {
		std::cout << "No value of key: " << key << " found" << std::endl;
	}
}

//Update the screen with any rendering performed since the previous call.
void Draw::PresentTexture(){
    SDL_RenderPresent(renderer);
}

//Clear the current rendering target with the drawing color.
void Draw::ClearTexture(){
    SDL_RenderClear(renderer);
}

void Draw::DestroySDL()
{
	TTF_Quit();
	IMG_Quit();

	// loops through unordered_map and deletes texture as well a 
	// map pair
	while (mapIndex != -1) {
		if (textureMap.find(mapIndex) != textureMap.end()) {
			SDL_DestroyTexture(textureMap.at(mapIndex));
			textureMap.erase(mapIndex);
		}
		mapIndex--;
	}

	textureMap.clear();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Draw::DestroyTexture(int key)
{
	if (textureMap.find(key) != textureMap.end()) {
		SDL_DestroyTexture(textureMap.at(key));
		textureMap.erase(key);

		// Specific optimization for video subsystems
		if (key == mapIndex)
			mapIndex--;
	} else {
		std::cout << "No value of key: " << key << " found" << std::endl;
	}
}

void Draw::DimBackground(uint8_t alpha) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, alpha);
	SDL_RenderFillRect(renderer, NULL);
}

SDL_Texture* Draw::ConvertTexture(SDL_Surface* surface){
	return  SDL_CreateTextureFromSurface(renderer, surface);
}
//temp function *DONT FORGET TO REMOVE*
void Draw::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

//return the running status of the game(temp function)
bool Draw::CheckRunning()
{
    return isRunning;
}
