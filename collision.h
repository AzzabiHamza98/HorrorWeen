#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "mouvement.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y);
SDL_Rect collision(SDL_Rect camera);
int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect camera);
int  collisionpit(int debut[],int fin[],int * gravity,int n,SDL_Rect posj,SDL_Rect camera );
int collisionplatform(int debut[],int fin[],int *gravity,int n,SDL_Rect posj,SDL_Rect camera ,int haut[]);

#endif