#include "game.h"





void game (SDL_Surface *ecran)
{
	int continuer = 1;
	perso perso ;
	SDL_Surface *imageback=NULL;
	SDL_Rect camera;
	SDL_Event event;
	char personom[20]="minisprite.png";
	char mapnom[20]="minimap.bmp";
	int r,run =1,running=1;

	imageback=Init_imagedefond(imageback ,&camera ,0, 0 );
	initialiserperso(&perso);


	while(continuer)
	{
		perso.fall=0;
		running=1,r=0 ;
		SDL_PollEvent(&event);
		switch(event.type)
	  	{

	        case SDL_QUIT:
	            continuer = 0;
		 	case SDL_KEYDOWN:
	            switch (event.key.keysym.sym)
	            {
					          			
					case SDLK_LEFT :
						perso.moveleft=1  ;
		            	break ;

					case SDLK_RIGHT :
						perso.moveright=1; 
						break ;
		
					case SDLK_UP :
						perso.jump=1; 
						break ;
		    	}
				break;
			case SDL_KEYUP:
	            switch (event.key.keysym.sym)
	            {
	 				case SDLK_ESCAPE:
			    		//continuer=0 ;
						break ;
		
					case SDLK_LEFT :
						perso.moveleft=0;	
	                   	break ;
					case SDLK_RIGHT :
						perso.moveright=0; 
						break ;
					case SDLK_UP :
						perso.jump=0; 
						break ;
		    	}
				break;
		}

	SDL_Delay(20);

	gravity(&perso);
	jumpin(&camera,&perso);
	perso.animation=mouv(perso);
	mouvement(&perso,&camera);

	SDL_BlitSurface(imageback, &camera, ecran, NULL);
	miniMap (ecran, perso.position, mapnom,personom ,camera);
	afficherperso(perso,ecran);

	SDL_Flip(ecran);
	}

	SDL_FreeSurface(imageback);  
	freefurfaceperso(&perso);
	SDL_Quit();
}