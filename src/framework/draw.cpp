#include "framework/draw.hpp"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

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
	    printf("IMG_Init: Failed to init required jpg and png support!\n");
	    printf("IMG_Init: %s\n", IMG_GetError());
		isRunning = false;
		return false;
	}
	
    isRunning = true;

    window = SDL_CreateWindow("GAME", 0, 40, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    std::cout << "Game Started" << std::endl;

	return true;
}
//Copy a portion of the texture to the current rendering target.
void Draw ::CopyTexture(SDL_Rect srcRect, SDL_Rect dstRect)
{
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

Draw &Draw::getInstance()
{
    static Draw instanceptr;
    return instanceptr;
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

//load an image to the gpu texture (SDL_Texture*) Always load texture before using CopyTexture() or PresentTexture() call
void Draw::LoadTexture(std::string path){
    texture = IMG_LoadTexture(renderer, path.c_str()); // c_str to convert to char* from string
}

