#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "game.h"

int main ()
{
	Menu m;
	SDL_Init(SDL_INIT_VIDEO);   
	SDL_Surface *ecran =NULL;
	ecran=SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	background b;
	SDL_WM_SetCaption("HorrorWeen", NULL);
	b=initialiserBackground("menures/menu0.png",0,0);
	m=InitialiserMenu(b);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_Music *musique;

	musique = Mix_LoadMUS("menures/music.mp3");
	Mix_PlayMusic(musique, -1);
	AfficherMenu(m,ecran); 
	updateMenu(ecran);
	Mix_FreeMusic(musique);
	Mix_CloseAudio();
	SDL_Quit(); 
	return EXIT_SUCCESS;

}