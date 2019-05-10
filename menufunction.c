#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"menu.h"
#include "game.h"

background initialiserBackground (char* chemin,int x,int y)
{
    background b;
    b.fond=IMG_Load(chemin);
    b.positionFond.x=x;
    b.positionFond.y=y;
    return b;
}

Menu InitialiserMenu(background b)
{
    Menu m;
    m.b=b;
    m.but=Mix_LoadMUS("menures/button.wav");
    return m;
}
void AfficherMenu(Menu m,SDL_Surface *ecran )
{	 
    SDL_BlitSurface(m.b.fond,NULL,ecran,0);
    SDL_Flip(ecran);
    SDL_Delay(10);
}

void updateMenu(SDL_Surface *ecran)
{
    Mix_Chunk *but;
    int press;
    press=1;
    int cont;
    cont=1;
    int i=0;
    int sound=100;
    int volume =2;
    int mode =1;
    int manette=0;  
    SDL_Surface *image=NULL,*image1=NULL,*image2=NULL,*image3=NULL,*image4=NULL;
    image=  IMG_Load("menures/menu1.png");
    image2= IMG_Load("menures/menu2.png");
    image3= IMG_Load("menures/menu3.png");
    image4= IMG_Load("menures/menu0.png");
    SDL_Event event;
    but=Mix_LoadWAV("menures/button.wav");
    while(cont)
    {
        Mix_VolumeMusic(sound);
        if(volume==2)
        sound=100;
        else if(volume==1)
        sound=50;
        else if(volume==0)
        sound=0;

        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:

        switch(event.key.keysym.sym)
                    {

                    case SDLK_RETURN: 
                        if (i==1)
                        { 
                            game(ecran);
                        }
                        else if (i==2)
                        {

                        }
                        else if (i==3)
                        {
                            SDL_Quit();
                        }

                        break;

                    case SDLK_DOWN:
                        i++;
                        if(i==4)
                        {
                            i=1;
                        
                        }
                        if(i==1)
                        {

                            SDL_BlitSurface(image,NULL, ecran,0);
                            SDL_Flip(ecran);
                       
                            Mix_PlayChannel(1,but,0);
                            SDL_Delay(100);

                        }
                        if(i==2)
                        {
                            SDL_BlitSurface(image2,NULL, ecran,0);
                            SDL_Flip(ecran);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);
                            Mix_PlayChannel(1, but, 0);     
                            SDL_Delay(100);}
                        if(i==3)
                        {
                            SDL_BlitSurface(image3,NULL, ecran, 0);
                            SDL_Flip(ecran);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);   
                        }
                        break;
                    case SDLK_UP: 
                        i--;
                        if(i<0)
                        {
                               i=3;
                        }
                        
                        if(i==1)
                        {
                            SDL_BlitSurface(image,NULL, ecran,0);
                            SDL_Flip(ecran);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);   
                        }
                        if(i==2)
                        {
                            SDL_BlitSurface(image2,NULL, ecran,0);
                            SDL_Flip(ecran);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100); 
                        }
                        if(i==3)
                        {
                            SDL_BlitSurface(image3,NULL, ecran,0);
                            SDL_Flip(ecran);
                            SDL_Delay(100);
                            Mix_PlayChannel(1, but, 0);
                            SDL_Delay(100);
                        }
                        break;        
                    }
        }    
    }
}