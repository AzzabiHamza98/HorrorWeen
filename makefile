game:main.o game.o background.o menufunction.o minimap.o mouvement.o collision.o
	gcc main.o game.o background.o menufunction.o minimap.o mouvement.o collision.o -o game -lSDL  -lSDL_image -lSDL_mixer -g
menufunction.o:menufunction.c
	gcc -c menufunction.c -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
game.o:game.c
	gcc -c game.c -lSDL -lSDL_image -lSDL_mixer -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_image -lSDL_mixer -g
menufunction.o:menufunction.c
	gcc -c menufunction.c -lSDL -lSDL_image -lSDL_mixer -g
minimap.o:minimap.c
	gcc -c minimap.c -lSDL -lSDL_image -lSDL_mixer -g
mouvement.o:mouvement.c
	gcc -c mouvement.c -lSDL -lSDL_image -lSDL_mixer -g
collision.o:collision.c
	gcc -c collision.c -lSDL -lSDL_image -lSDL_mixer -g
