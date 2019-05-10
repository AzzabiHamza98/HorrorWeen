#ifndef PLAYERMOV_H_INCLUDED
#define PLAYERMOV_H_INCLUDED
#include "game.h"


typedef struct 
{
	int a;
	int moveright;
	int moveleft;
	int jump;
	int prevright;
	int prevleft;
	int mouvementspeed;
	int jumpspeed;
	int jumpheight;
	int jumping;
	int falling;
	int animation;
	int fall;
	int gravity;
	
	SDL_Rect position;
	SDL_Surface *fond00;
	SDL_Surface *fond0;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
	SDL_Surface *fondc;
	SDL_Surface *fondd;
	SDL_Surface *fonde;
	SDL_Surface *fond100;
	SDL_Surface *fond10;
	SDL_Surface *fond11;
	SDL_Surface *fond12;
	SDL_Surface *fond13;
	SDL_Surface *fond14;
	SDL_Surface *fond1a;
	SDL_Surface *fond1b;
	SDL_Surface *fond1c;
	SDL_Surface *fond1d;
	SDL_Surface *fond1e;

}perso;

void gravity(perso *perso);
void jumpin(SDL_Rect *camera,perso *perso);
void initialiserperso(perso *perso);
void freefurfaceperso(perso *perso);
int mouv(perso perso);
void mouvement(perso *perso,SDL_Rect *camera);
void afficherperso(perso perso,SDL_Surface *ecran);


#endif 