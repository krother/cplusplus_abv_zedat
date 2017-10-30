#include "grafik.h"

Fenster::Fenster(int breite, int hoehe) {
    	win = SDL_CreateWindow("Snake", 100,100, breite, hoehe, SDL_WINDOW_SHOWN);
    	surf = SDL_GetWindowSurface(win);

        IMG_Init(IMG_INIT_PNG );
        hintergrund = IMG_Load("background.png");
    }

