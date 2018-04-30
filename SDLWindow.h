#include <SDL.h>

class SDLWindow
{
public:
	SDLWindow();
	~SDLWindow();

private:
	SDL_Window* window;
};

