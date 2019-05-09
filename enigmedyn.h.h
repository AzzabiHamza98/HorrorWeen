#ifndef ENIGMEDYN_H_INCLUDED
#define ENIGMEDYN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"


typedef struct
{
	SDL_Rect tab[4][4];
	char nomimage[30];
}Enigmex;
//typedef struct Enigme Enigme;
int enig(SDL_Surface *screen );






#endif /* FONCTIONS_H_ */
