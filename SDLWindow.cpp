#include "SDLWindow.h"
#include <SDL.h>

SDLWindow::SDLWindow()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOWEVENT);
}

SDLWindow::~SDLWindow()
{
	SDL_Quit();
}