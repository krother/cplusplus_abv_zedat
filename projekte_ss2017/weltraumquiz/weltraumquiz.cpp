/*
 * Projektarbeit.cpp
 *
 *  Created on: 30.06.2017
 *      Author: sahel02_bk7
 */
// Weltraumquiz

// KR: Kommentare von Kristian Rother

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define FRAGE1 0
#define FRAGE2 1
#define FRAGE3 2
#define FRAGE4 3
#define FRAGE5 4
#define FRAGE6 5
#define FRAGE7 6
#define FRAGE8 7
#define THEEND 8

int main(int x, char** y) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Weltraumquiz", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // Bilder laden
    IMG_Init( IMG_INIT_PNG );
    // KR: habe das Verzeichnis jeweils hinzugefügt, damit es bei mir lief
    SDL_Surface *frage1 = IMG_Load("bilder/Frage1mitText.PNG");
    SDL_Surface *frage2 = IMG_Load("bilder/Frage2mitText.fw.png");
    SDL_Surface *frage3 = IMG_Load("bilder/Frage3mitText.fw.png");
    SDL_Surface *frage4 = IMG_Load("bilder/Frage4mit text.png");
    SDL_Surface *frage5 = IMG_Load("bilder/Frage5mitText.fw.png");
    SDL_Surface *frage6 = IMG_Load("bilder/Frage6mitText.fw.png");
    SDL_Surface *frage7 = IMG_Load("bilder/Frage7mit-Text.png");
    SDL_Surface *frage8 = IMG_Load("bilder/Frage8mitText.png");
    SDL_Surface *ende = IMG_Load("bilder/TheEnd.png");


    // Array "frage" erstellen
    string frage[9] = {"Frage 1", "Frage 2", "Frage 3", "Frage 4", "Frage 5", "Frage 6", "Frage 7", "Frage 8", "Ende"};
    	string eingabe;
    	int position = 0;

    // erste Ausgabe
    cout << frage[0] << endl;
    cout << ("Welche Option möchtest du wählen (a, b, c) ?") << endl;


    // while Schleife für Tasten
    // SDLK_a und SDLK_b und SDLK_c für die drei Antwortoptionen

    SDL_Event e;
    int taste = 0;

    do {
    	while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_KEYDOWN ) {
                taste = e.key.keysym.sym;

                //Frage 1, a und b falsch, c richtig
                if (position == FRAGE1)
                {
                    // KR: ideal wäre hier, die richtigen Antworten in einem Array nachzuschlagen,
                    //     für die Abgabe ist das auch so OK.

                	if (taste == SDLK_a && position > 0)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;

                	}
                	else if (taste == SDLK_b)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;
                	}
                	else if (taste == SDLK_c)
                	{
                		cout << ("Die Antwort ist richtig!") << endl;
                		position = 1;
                	}

                }

                //Frage 2, a und c falsch, b richtig
                else if (position == FRAGE2)

                {
                	if (taste == SDLK_a && position > 0)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;

                	}
                	else if (taste == SDLK_b)
                	{
                		cout << ("Die Antwort ist richtig!") << endl;
                		position = 2;
                	}
                	else if (taste == SDLK_c)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;
                	}
                }

                //Frage 3, b und c falsch, a richtig
                else if (position == FRAGE3)
                {

                	if (taste == SDLK_a && position > 0)
                	{
                		cout << ("Die Antwort ist richtig!") << endl;
                		position = 3;

                	}
                	else if (taste == SDLK_b)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;
                	}
                	else if (taste == SDLK_c)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;
                	}

                }

                //Frage 4, a und b falsch, c richtig
                if (position == FRAGE4)
                {

                	if (taste == SDLK_a && position > 0)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;

                	}
                	else if (taste == SDLK_b)
                	{
                		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                		position = position + 0;
                	}
                	else if (taste == SDLK_c)
                	{
                		cout << ("Die Antwort ist richtig!") << endl;
                		position = 4;
                	}

                }

                //Frage 5, a und c falsch, b richtig
                 if (position == FRAGE5)
                 {

                 	if (taste == SDLK_a && position > 0)
                 	{
                 		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                 		position = position + 0;

                 	}
                 	else if (taste == SDLK_b)
                 	{
                 		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                 		position = position + 0;
                 	}
                 	else if (taste == SDLK_c)
                 	{
                 		cout << ("Die Antwort ist richtig!") << endl;
                 		position = 5;
                 	}

                 }

                 //Frage 6, b und c falsch, a richtig
                               if (position == FRAGE6)
                               {

                               	if (taste == SDLK_a && position > 0)
                               	{
                               		cout << ("Die Antwort ist richtig!") << endl;
                               		position = 6;

                               	}
                               	else if (taste == SDLK_b)
                               	{
                               		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                               		position = position + 0;
                               	}
                               	else if (taste == SDLK_c)
                               	{
                               		cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                               		position = position + 0;
                               	}

                               }

                    //Frage 7, b und c falsch, a richtig
                        if (position == FRAGE7)
                        {

                           if (taste == SDLK_a && position > 0)
                                   {
                            	cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                                position = position + 0;
                                   }
                            else if (taste == SDLK_b)
                                {
                             	cout << ("Die Antwort ist richtig!") << endl;
                                position = 7;
                               	}
                            else if (taste == SDLK_c)
                                    {
                                   	cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                                    position = position + 0;
                                    }

                                    }

                        //Frage 8, b und c falsch, a richtig
                            if (position == FRAGE8)
                            {

                               if (taste == SDLK_a && position > 0)
                                       {
                                    cout << ("Die Antwort ist richtig!") << endl;
                                    position = 8;
                                       }
                                else if (taste == SDLK_b)
                                    {
                                    cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                                    position = position + 0; // KR: Diese Zeile tut nichts, kannst Du weglassen
                                    }
                                else if (taste == SDLK_c)
                                        {
                                        cout << ("Die Antwort ist falsch! Probiere es noch einmal!") << endl;
                                        position = position + 0;
                                        }

                                        }

    // KR: hier die Klammer von *1* hin, dann ist das Spiel flüssiger
            }
// Festlegen was ist auf welcher Position
            if (position == FRAGE1)
            {
                    // KR: Der Teil in der Klammer ginge prima in eine Funktion zu packen
                    //     dann wird das Programm sehr viel kürzer
                    cout << frage[position] << endl;
                    SDL_BlitSurface(frage1, NULL, surf, NULL);
                    SDL_UpdateWindowSurface(win);
                    SDL_Delay(200);
            }

            else if (position == FRAGE2)
            {

                    cout << frage[position] << endl;
                    SDL_BlitSurface(frage2, NULL, surf, NULL);
                    SDL_UpdateWindowSurface(win);
                    SDL_Delay(200);
            }

            else if (position == FRAGE3)
            {

                    cout << frage[position] << endl;
                    SDL_BlitSurface(frage3, NULL, surf, NULL);
                    SDL_UpdateWindowSurface(win);
                    SDL_Delay(200);
            }

            else if (position == FRAGE4)
            {

                                cout << frage[position] << endl;
                                SDL_BlitSurface(frage4, NULL, surf, NULL);
                                SDL_UpdateWindowSurface(win);
                                SDL_Delay(200);
            }

            else if (position == FRAGE5)
            {

                                cout << frage[position] << endl;
                                SDL_BlitSurface(frage5, NULL, surf, NULL);
                                SDL_UpdateWindowSurface(win);
                                SDL_Delay(200);
            }

            else if (position == FRAGE6)
            {

                                cout << frage[position] << endl;
                                SDL_BlitSurface(frage6, NULL, surf, NULL);
                                SDL_UpdateWindowSurface(win);
                                SDL_Delay(200);
            }

            else if (position == FRAGE7)
                        {

                                            cout << frage[position] << endl;
                                            SDL_BlitSurface(frage7, NULL, surf, NULL);
                                            SDL_UpdateWindowSurface(win);
                                            SDL_Delay(200);
                        }

            else if (position == FRAGE8)
                        {

                                            cout << frage[position] << endl;
                                            SDL_BlitSurface(frage8, NULL, surf, NULL);
                                            SDL_UpdateWindowSurface(win);
                                            SDL_Delay(200);
                        }

            else if (position == THEEND)
            {
                    cout << frage[position] << endl;
                    SDL_BlitSurface(ende, NULL, surf, NULL);
                    SDL_UpdateWindowSurface(win);
                    SDL_Delay(200); //KR: besser längere Pause am Ende
            }

    } // KR: diese Klammer höher bei *1*, dann reagiert das Spiel besser.
    }
while (position != THEEND);
return 0;
   }
