#include "game.h"
#include "mouvement.h"

void initialiserperso(perso *perso)
{

	perso->moveright=0;
	perso->moveleft=0;
	perso->jump=0;
	perso->jumping=0;
	perso->falling=0;
	perso->fall=1;
	perso->gravity=335;
	
	perso->mouvementspeed=30;
	perso->jumpspeed=20;
	perso->jumpheight=15;
	perso->a=0;
	perso->position.x = 100 ;
	perso->position.y = 335;

	perso->fond00 = IMG_Load("character/1.png");
	perso->fond0 = IMG_Load("character/2.png");
	perso->fond1 = IMG_Load("character/3.png");
	perso->fond2 = IMG_Load("character/4.png");
	perso->fond3 = IMG_Load("character/5.png");
	perso->fond4 = IMG_Load("character/6.png");
	perso->fonda = IMG_Load("character/8.png");
	perso->fondb = IMG_Load("character/9.png");
	perso->fondd = IMG_Load("character/10.png");
	perso->fonde = IMG_Load("character/7.png");
	perso->fond100 = IMG_Load("character/11.png");
	perso->fond10 = IMG_Load("character/12.png");
	perso->fond11 = IMG_Load("character/13.png");
	perso->fond12 = IMG_Load("character/14.png");
	perso->fond13 = IMG_Load("character/15.png");
	perso->fond14 = IMG_Load("character/16.png");
	perso->fond1a = IMG_Load("character/17.png");
	perso->fond1b = IMG_Load("character/18.png");
	perso->fond1d = IMG_Load("character/19.png");
	perso->fond1e = IMG_Load("character/20.png");
	perso->position.h=perso->fond00->h;
	perso->position.w=perso->fond00->w;
}

void freefurfaceperso(perso *perso)
{
	SDL_FreeSurface(perso->fond00);
	SDL_FreeSurface(perso->fond0);
	SDL_FreeSurface(perso->fond1);
	SDL_FreeSurface(perso->fond2);
	SDL_FreeSurface(perso->fond3);
	SDL_FreeSurface(perso->fonda);
	SDL_FreeSurface(perso->fondb);
	SDL_FreeSurface(perso->fondc);
	SDL_FreeSurface(perso->fond4);
	SDL_FreeSurface(perso->fondd);
	SDL_FreeSurface(perso->fonde);
	SDL_FreeSurface(perso->fond100);
	SDL_FreeSurface(perso->fond10);
	SDL_FreeSurface(perso->fond11);
	SDL_FreeSurface(perso->fond12);
	SDL_FreeSurface(perso->fond13);
	SDL_FreeSurface(perso->fond1a);
	SDL_FreeSurface(perso->fond1b);
	SDL_FreeSurface(perso->fond1c);
	SDL_FreeSurface(perso->fond14);
	SDL_FreeSurface(perso->fond1e);

}


int mouv(perso perso)
{
	if(perso.moveright==0&&perso.moveleft==0)
	{
		if(perso.prevleft==1)
			perso.animation=20;
		else
			perso.animation=10;
	}
	if(perso.jumping!=0)
	{
		if(perso.prevleft==1)
			perso.animation=13;
		else 
			perso.animation=4;
	}else if(perso.fall==1)
	{
		if(perso.prevleft==1)
			perso.animation=11;
		else
			perso.animation=1;
	}
	else if(perso.moveright==1)
	{
		switch(perso.animation)
		{
			case 10:
				perso.animation=1;
				break;
			case 1:
				perso.animation=2;
				break;
			case 2:
				perso.animation=3;
				break;
			case 3:
				perso.animation=4;
				break;
			case 4:
				perso.animation=5;
				break;
			case 5:
				perso.animation=6;
				break;
			case 6:
				perso.animation=7;
				break;
			case 7:
				perso.animation=9;
				break;
			case 8:
				perso.animation=9;
				break;
			case 9:
				perso.animation=1;
				break;
			default:
				perso.animation=10;
				break;
			}
		}

	else if(perso.moveleft==1)
	{
		switch(perso.animation){
			case 20:
				perso.animation=11;
				break;
			case 11:
				perso.animation=12;
				break;
			case 12:
				perso.animation=13;
				break;
			case 13:
				perso.animation=14;
				break;
			case 14:
				perso.animation=15;
				break;
			case 15:
				perso.animation=16;
				break;
			case 16:
				perso.animation=17;
				break;
			case 17:
				perso.animation=18;
				break;
			case 18:
				perso.animation=19;
				break;
			case 19:
				perso.animation=11;
				break;
			default:
				perso.animation=20;
				break;
		}	
	}
	return perso.animation ;
}


void afficherperso(perso perso,SDL_Surface *ecran)
{
	switch(perso.animation)
	{
		case 0:
		SDL_BlitSurface(perso.fond00,NULL, ecran,&perso.position);
			break ;
		case 1:
		SDL_BlitSurface(perso.fond0,NULL, ecran,&perso.position);
			break ;
		case 2:
		SDL_BlitSurface(perso.fond1,NULL, ecran,&perso.position);
			break ;
		case 3:
		SDL_BlitSurface(perso.fond2,NULL, ecran,&perso.position);
			break ;
		case 4:
		SDL_BlitSurface(perso.fond3,NULL, ecran,&perso.position);
			break ;
		case 5:
		SDL_BlitSurface(perso.fond4,NULL, ecran,&perso.position);
			break ;
		case 6:
		SDL_BlitSurface(perso.fonda,NULL, ecran,&perso.position);
			break ;
		case 7:
		SDL_BlitSurface(perso.fondb,NULL, ecran,&perso.position);
			break ;
		case 8:
		SDL_BlitSurface(perso.fondc,NULL, ecran,&perso.position);
			break ;
		case 9:
		SDL_BlitSurface(perso.fondd,NULL, ecran,&perso.position);
			break ;

		case 10:
		SDL_BlitSurface(perso.fonde,NULL, ecran,&perso.position);
			break ;
		case 11:
		SDL_BlitSurface(perso.fond100,NULL, ecran,&perso.position);
			break ;
		case 12:
		SDL_BlitSurface(perso.fond10,NULL, ecran,&perso.position);
			break ;
		case 13:
		SDL_BlitSurface(perso.fond11,NULL, ecran,&perso.position);
			break ;
		case 14:
		SDL_BlitSurface(perso.fond12,NULL, ecran,&perso.position);
			break ;
		case 15:
		SDL_BlitSurface(perso.fond13,NULL, ecran,&perso.position);
			break ;
		case 16:
		SDL_BlitSurface(perso.fond14,NULL, ecran,&perso.position);
			break ;
		case 17:
		SDL_BlitSurface(perso.fond1a,NULL, ecran,&perso.position);
			break ;
		case 18:
		SDL_BlitSurface(perso.fond1b,NULL, ecran,&perso.position);
			break ;
		case 19:
		SDL_BlitSurface(perso.fond1d,NULL, ecran,&perso.position);
			break ;

		case 20:
		SDL_BlitSurface(perso.fond1e,NULL, ecran,&perso.position);
			break ;
	}
}



void mouvement(perso *perso,SDL_Rect *camera)
{
	(*camera)=collision((*camera));
	if(camera->x>=0&&camera->x<=11000)
	{
		if(perso->moveright==1)
		{
			if (perso->position.x>=600 && camera->x<=10600)
		        camera->x += perso->mouvementspeed/2;
		    else if (perso->position.x<=1190)
		        perso->position.x +=perso->mouvementspeed;
			(*camera)=collision((*camera));
		}
		if(perso->moveleft==1)
		{
			if(perso->position.x<=250 && camera->x>=0)
		        camera->x -= perso->mouvementspeed/2;
		    else if (perso->position.x>=0) 
		        perso->position.x -=perso->mouvementspeed;
		    (*camera)=collision((*camera));
		}
	}
}

void jumpin(SDL_Rect *camera,perso *perso)
{
	int lateralspeed = 0.5;

	if((perso->jump==1||(perso->jumping)!=0)&&((perso->jumping)<perso->jumpheight)&&(perso->falling)==0)
	{
		perso->position.y-=perso->jumpspeed-(perso->jumping);
		(perso->jumping)++;
	}else{
		(perso->jumping)=0;
		(perso->falling)=1;
	}
}

void gravity(perso *perso)
{
	if((perso->falling)==1)
	{	
		if(perso->position.y<perso->gravity)
		{
			      printf("meni\n");

			perso->position.y+=perso->jumpspeed;
			perso->fall=1;
		}else
			(perso->falling)=0;
	}

}


