#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;


int main(int x, char** y) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Das Ziel ist der Weg", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    // Bilder laden
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *picture1 = IMG_Load("bilder/Picture1NN.png");
    SDL_Surface *picture2 = IMG_Load("bilder/picture2NN.png");
    SDL_Surface *picture3 = IMG_Load("bilder/picture3N.png");
    SDL_Surface *picture4 = IMG_Load("bilder/picture4N.png");
    SDL_Surface *picture5 = IMG_Load("bilder/Picture5N.png");
    SDL_Surface *picture6 = IMG_Load("bilder/Picture6NN.png");
    SDL_Surface *picture7 = IMG_Load("bilder/Picture7N.png");
    SDL_Surface *picture8 = IMG_Load("bilder/Picture8N.png");
    SDL_Surface *picture9 = IMG_Load("bilder/Picture9N.png");
    SDL_Surface *picture10 = IMG_Load("bilder/Picture10N.png");
    SDL_Surface *picture11 = IMG_Load("bilder/Picture11NN.png");
    SDL_Surface *picture12 = IMG_Load("bilder/picture12NN.png");
    SDL_Surface *picture13 = IMG_Load("bilder/Picture13N.png");
    SDL_Surface *picture14 = IMG_Load("bilder/Picture14N.png");
    SDL_Surface *picture15 = IMG_Load("bilder/AugeN.png");
    SDL_Surface *picture16 = IMG_Load("bilder/Picture6Nend.png");
    SDL_Surface *picture17 = IMG_Load("bilder/Picture11Nend.png");
    SDL_Surface *picture18 = IMG_Load("bilder/picture12Nend.png");

    SDL_Surface *FruhstuckStand = IMG_Load("bilder/FruhstuckStand.png");
    SDL_Surface *StopuhrStand = IMG_Load("bilder/StopuhrStand.png");
    SDL_Surface *TicketStand = IMG_Load("bilder/TicketStand.png");

    string eingabe;
    int position = 1;
    bool fruhstuck = false;
    bool ticket = false;
    bool verspatung = false;
    int answer;

    SDL_Event e;
    int taste = 0;
    do {
                answer = 3;
                while( SDL_PollEvent( &e ) != 0 ) {

                if( e.type == SDL_KEYDOWN ) {
                    taste = e.key.keysym.sym;
                    if (taste == SDLK_j) {
                                answer = true;
                    }
                    else if (taste == SDLK_n) {
                                answer = false;
                    }
                }

                if (position == 1) {
                SDL_BlitSurface(picture1, NULL, surf, NULL);
                fruhstuck = false;
                ticket = false;
                verspatung = false;
                         if (answer == true) {
                            position += 1;
                            answer = 3;                //Hilfsmittel!
                        }
                        else if (answer == false) {
                            position += 6;
                            answer = 3;
                        }
                }
                if (position == 2) {
                SDL_BlitSurface(picture2, NULL, surf, NULL);
                        if (answer == true) {
                               position += 1;
                               fruhstuck = true;
                               answer = 3;
                        }
                        else if (answer == false) {
                            position += 1;
                            answer = 3;
                         }
                }
                else if (position == 3) {
                SDL_BlitSurface(picture3, NULL, surf, NULL);
                        if (answer == true) {
                            position += 1;
                            ticket = true;
                            verspatung = true;
                            answer = 3;
                        }
                        else if (answer == false) {
                            position += 1;
                            answer = 3;
                        }
                }
                else if (position == 4) {
                SDL_BlitSurface(picture4, NULL, surf, NULL);
                        if (ticket == true && answer == true) {
                            position += 1;
                            answer = 3;
                        }
                        else if (ticket == false && answer == false) {
                            position += 4;
                            answer = 3;
                        }
                        else if (ticket == false && answer == true) {
                            position += 11;
                            answer = 3;
                        }
                        else if (ticket == true && answer == false) {
                            position += 11;
                            answer = 3;
                        }
                 }
                else if (position == 5) {
                SDL_BlitSurface(picture5, NULL, surf, NULL);
                        if (answer == true) {
                            position += 1;
                               answer = 3;
                        }
                        else if (answer == false) {
                               position += 9;
                               answer = 3;
                        }
                }
                else if (position == 6) {
                        SDL_BlitSurface(picture6, NULL, surf, NULL);
                        if (answer == true){
                            position += 10;
                            answer = 3;
                        }
                        else if (answer == false) {
                            position -= 5;
                            answer = 3;
                        }
                }
                else if (position == 7) {
                        SDL_BlitSurface(picture7, NULL, surf, NULL);
                        if (answer == true){
                            position += 7;
                            answer = 3;
                        }
                }
                else if (position == 8) {
                        SDL_BlitSurface(picture8, NULL, surf, NULL);
                        if (answer == true && fruhstuck == true) {
                            position += 5;
                            answer = 3;
                        }
                        else if (answer == false && fruhstuck == false) {
                            position += 1;
                            answer = 3;
                        }
                        else if (fruhstuck == false && answer == true) {
                            position += 7;
                            answer = 3;
                        }
                        else if (fruhstuck == true && answer == false) {
                            position += 7;
                            answer = 3;
                        }
                }
                else if (position == 9) {
                        SDL_BlitSurface(picture9, NULL, surf, NULL);
                        if (answer == true) {
                            position += 1;
                            answer = 3;
                        }
                         else if (answer == false) {
                             position += 3;
                             answer = 3;
                         }
                }
                else if (position == 10) {
                        SDL_BlitSurface(picture10, NULL, surf, NULL);
                        if (answer == true) {
                            position += 1;
                            answer = 3;
                        }
                        else if (answer == false){
                            position += 4;
                            answer = 3;
                        }
                }
                else if (position == 11) {
                        SDL_BlitSurface(picture11, NULL, surf, NULL);
                        if (answer == true){
                            position += 6;
                            answer = 3;
                        }
                        else if (answer == false) {
                            position -= 10;
                            answer = 3;
                        }
                }
                else if (position == 12) {
                        SDL_BlitSurface(picture12, NULL, surf, NULL);
                        if (answer == true){
                            position += 6;
                            answer = 3;
                        }
                        else if (answer == false) {
                            position -= 11;
                            answer = 3;
                        }
                }
                else if (position == 13) {
                           SDL_BlitSurface(picture13, NULL, surf, NULL);
                           verspatung = true;
                           if (answer == true) {
                               position -= 8;
                               answer = 3;
                           }
                }
                else if (position == 14){
                    SDL_BlitSurface(picture14, NULL, surf, NULL);
                    fruhstuck = false;
                    ticket = false;
                    verspatung = false;
                    if (answer == true) {
                        position -=13;
                        answer = 3;
                    }
                    else if (answer == false) {
                        position -=13;
                        answer = 3;
                    }
                }
                else if (position == 15){
                    SDL_BlitSurface(picture15, NULL, surf, NULL);
                    fruhstuck = false;
                    ticket = false;
                    verspatung = false;
                    if (answer == true){
                        position -= 14;
                        answer = 3;
                    }
                }
                else if (position == 16){
                SDL_BlitSurface(picture16, NULL, surf, NULL);
                SDL_Delay(5000);
                }
                else if (position == 17){
                SDL_BlitSurface(picture17, NULL, surf, NULL);
                SDL_Delay(5000);
                }
                else if (position == 18){
                SDL_BlitSurface(picture18, NULL, surf, NULL);
                SDL_Delay(5000);
                }


                if (fruhstuck == true){
                SDL_BlitSurface(FruhstuckStand, NULL, surf, NULL);
                }
                if (ticket == true){
                SDL_BlitSurface(TicketStand, NULL, surf, NULL);
                }
                if (verspatung == true){
                SDL_BlitSurface(StopuhrStand, NULL, surf, NULL);
                }

                SDL_UpdateWindowSurface(win);
                SDL_Delay(20);
            }
    }
    while (position < 16);
    return 0;

}

