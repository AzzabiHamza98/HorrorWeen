#include "game.h"
#include "collision.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    switch(bpp) {
    case 1:
        return *p;
        break;
    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

SDL_Rect collision(SDL_Rect camera)
{
	if(camera.x<0)
	{
	camera.x=0;
	}

	if(camera.x>10650)
	{
	camera.x=10650;
	}

	return camera ;
}

int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect camera)
{
	 int x ; 
	if((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+camera.x+posj.w>=posobj.x)&&(posj.x+camera.x<=posobj.x+posobj.w)) 
	{
		x=1 ; 
	}
	else x=0 ; 
	return x ;
}

int  collisionpit(int debut[],int fin[],int * gravity,int n,SDL_Rect posj,SDL_Rect camera )
{
	int x;
	for(int i=0;i<n;i++){
	if(posj.x+camera.x>debut[i]&&posj.x+camera.x<fin[i]){
	(*gravity)=660;
	return 1;
	}
	}
	return 0;
}

int collisionplatform(int debut[],int fin[],int *gravity,int n,SDL_Rect posj,SDL_Rect camera ,int haut[])
{
	int x;
	for(int i=0;i<n;i++){
	if(posj.x+camera.x>debut[i]&&posj.x+camera.x<fin[i]){
	if(posj.h>haut[i])
	(*gravity)=haut[i];
	return 1;

	}
	}
	return 0;

}
