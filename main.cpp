#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include "SDLWindow.h"
#include <string>

#undef main
#define FILE_NAME ""


int main()
{
	char *file = new char[1000];

	Mix_Music *song = NULL;
	SDLWindow *window = NULL;

	window = new SDLWindow;

	std::cout << "Please enter the path name to your song: ";
	std::cin.getline(file, 1000);	

	#undef FILE_NAME
	#define FILE_NAME file

	Mix_OpenAudio(22096, MIX_DEFAULT_FORMAT, 2, 4096);
	song = Mix_LoadMUS(FILE_NAME); 

	while(song == NULL)
	{
		std::cerr << "ERROR\n";
		std::cerr << "Try again: ";
		std::cin.getline(file, 1000);

		#undef FILE_NAME
		#define FILE_NAME file

		song = Mix_LoadMUS(FILE_NAME);
	}

	bool isRunning = true;
	SDL_Event event;
	
	while (isRunning == true)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{	
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_p) //Press p to pause/resume
					{
						if(!Mix_PlayingMusic())
							Mix_PlayMusic(song, -1);

						else if(Mix_PausedMusic())
							Mix_ResumeMusic();

						else
							Mix_PauseMusic();
					}

					else if(event.key.keysym.sym == SDLK_n) //Press n to change songs
					{
						Mix_HaltMusic();
						std::cout << "Next song: ";
						std::cin.getline(file, 1000);

						#undef FILE_NAME
						#define FILE_NAME file

						song = Mix_LoadMUS(FILE_NAME);
					}	
				break;

				case SDL_QUIT:
					isRunning = false;
				break;
				}
		}
	} //end of isRunning loop

	delete window;
	delete [] file;
	Mix_FreeMusic(song);
	Mix_CloseAudio();
	Mix_Quit();
	
	return 0;
}


