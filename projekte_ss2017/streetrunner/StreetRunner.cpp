
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

void start_soundtrack() {
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    Mix_Music *music = Mix_LoadMUS("cool_tunes.mp3");
    Mix_PlayMusic(music, 1);
}

int main(int argc, char *argv[]) {
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Texture *bitmapTex = NULL;
    SDL_Texture *bitmapTex2 = NULL;
    SDL_Texture *bitmapTex3 = NULL;

    SDL_Texture *texture = NULL;

    SDL_Surface *bitmapSurface = NULL;
    SDL_Surface *bitmapSurface2 = NULL;
    SDL_Surface *bitmapSurface3 = NULL;

    SDL_Surface *image = NULL;


    int posX = 100, posY = 100, width = 1024, height = 768;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("StreetRunner", posX, posY, width, height, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    bitmapSurface = IMG_Load("far-buildings.png");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    bitmapSurface2 = IMG_Load("back-buildings.png");
    bitmapTex2 = SDL_CreateTextureFromSurface(renderer, bitmapSurface2);
    SDL_FreeSurface(bitmapSurface2);
    bitmapSurface3 = IMG_Load("foreground.png");
    bitmapTex3 = SDL_CreateTextureFromSurface(renderer, bitmapSurface3);
    SDL_FreeSurface(bitmapSurface3);

    image = IMG_Load("ballguy.png");
    texture = SDL_CreateTextureFromSurface(renderer,
        image);

    start_soundtrack();


    	int pos_x = 100;
    	int pos_y = 550;

    	int vel_x = 0;
    	int vel_y = 0;

    int MOVEMENT = 0;
    int MOVEMENT2 = 0;
    int MOVEMENT3 = 0;

    while (1) {


        SDL_Event a;
        if (SDL_PollEvent(&a)) {
            if (a.type == SDL_QUIT) {
                break;
            }
        }

        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite = (ticks / 50) % 28;
        SDL_Rect srcrectball = { sprite * 16, 0, 16, 34 };
        SDL_Rect dstrectball = { pos_x, pos_y, 80, 160 };

        SDL_Rect SrcR = {0, 0, 352, 192};
        SDL_Rect DstR = {MOVEMENT, 0, 1408, 768};
        SDL_Rect DstR2 = {MOVEMENT+1408, 0, 1408, 768};
        SDL_Rect DstR3 = {MOVEMENT2, 0, 1184, 768};
        SDL_Rect DstR4 = {MOVEMENT2+1184, 0, 1184, 768};
        SDL_Rect DstR5 = {MOVEMENT3, 0, 1184, 768};
        SDL_Rect DstR6 = {MOVEMENT3+1184, 0, 1184, 768};


        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bitmapTex, NULL, &DstR5);
        SDL_RenderCopy(renderer, bitmapTex, NULL, &DstR6);

        SDL_RenderCopy(renderer, bitmapTex2, NULL, &DstR3);
        SDL_RenderCopy(renderer, bitmapTex2, NULL, &DstR4);

        SDL_RenderCopy(renderer, bitmapTex3, &SrcR, &DstR);
        SDL_RenderCopy(renderer, bitmapTex3, &SrcR, &DstR2);

        SDL_RenderCopy(renderer, texture, &srcrectball, &dstrectball);

        SDL_RenderPresent(renderer);

        MOVEMENT -= 3;
        MOVEMENT2 -= 2;
        MOVEMENT3 -= 1;

        if  (MOVEMENT <= -1408) {
          MOVEMENT = 0;
        }
        if  (MOVEMENT2 <= -1184) {
          MOVEMENT2 = 0;
        }
        if  (MOVEMENT3 <= -1184) {
          MOVEMENT3 = 0;
        }

        int taste;

			SDL_Event e;
			if (SDL_PollEvent( &e )	!= 0 ) {
            	if( e.type == SDL_KEYDOWN ) {
            	    taste = e.key.keysym.sym;

          if (taste == SDLK_UP) {
              vel_y -= 10;
              }
          else if (taste == SDLK_DOWN) {
              vel_y += 10;
              }
          else if (taste == SDLK_LEFT) {
              vel_x -= 10;
              }
          else if (taste == SDLK_RIGHT) {
              vel_x += 10;
              }



              switch (vel_y){							//Limits velocity
                case 100:
                vel_y -= 10;
                break;
                case -100:
                vel_y += 10;
              }
              switch (vel_x){
                case 90:
                vel_x -= 10;
                break;
                case -90:
                vel_x += 10;
              }

              pos_y += vel_y;							//Applies velocity to position
              pos_x += vel_x;

                                          //Limits to the corners of the screen and bounces off
            if (pos_y > 625){
              pos_y = 625;
              vel_y -= 12;
            }
            if (pos_y < 525){
              pos_y = 525;
              vel_y += 12;
            }
            if (pos_x > 900){
              pos_x = 900;
              vel_x -= 12;
            }
            if (pos_x < 0){
              pos_x = 0;
              vel_x += 12;
            }
          }
        }
        SDL_Delay (40);
}



    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}
