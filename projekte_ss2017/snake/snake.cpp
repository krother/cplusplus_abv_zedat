//////////////////////////////////////////////////////////////
//															//
//															//
//		///////	///    //     ///     //   // ///////		//
//		//		// /   //    // //    //  //  //			//
//		///////	//  /  //   //   //   ////    /////			//
//			 //	//   / //  /////////  //  //  //			//
//		///////	//	  /// //      /// //   // ///////		//
//															//
//      Ein Spiel von Annemarie, Hee und Alex :)			//
//															//
//															//
//////////////////////////////////////////////////////////////

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "grafik.h"

using namespace std;

class Spielfeld{
public:
	vector<vector<char>> feld;
	bool weg;

	SDL_Surface *snaketiles;
	Spielfeld(SDL_Surface *felder){
		snaketiles = felder;
		weg = false;
		feld = {
				{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
				{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
			};
	}

	void zeichnen(SDL_Surface *surf){  // hier wird das Feld gezeichnet (mit Bilder)
		SDL_Rect source;
		SDL_Rect destination;
		   for (int i=0; i<19; i++){
			   for (int j=0; j<19; j++){
		    if (feld[j][i]=='#') {
		    	source = {x:32, y:32, w:32, h:32 };
		    }
		    else if (feld[j][i]=='_') {
		        source = {x:64, y:0, w:32, h:32 };
		    }
		    else if (feld[j][i]=='b') {
		          source = {x:0, y:64, w:32, h:32 };
		      }
		    else if (feld[j][i]=='t') {
		          source = {x:64, y:64, w:32, h:32 };
		      }
		    else if (feld[j][i]=='m') {
		          source = {x:130, y:64, w:32, h:32 };
		      }
		    else {
		    	continue; // zum nächsten schleifendurchlauf springen
		    }
		        destination = {x:i*32, y:j*32, w:32, h:32 } ;
		    SDL_BlitSurface(snaketiles, &source, surf, &destination);
		    }
		}
	}
	void zufallsfrucht(){
		int x = rand() % 17+1;
		int y = rand() % 17+1;
		int frucht = rand() % 3;
		char frucht_arten[3] = {'b', 't', 'm'};

        feld[x][y] = frucht_arten[frucht];
	}
};

class Snake{
public:
	//Eigenschaften
	SDL_Surface * held;
	int x;
	int y;
	int richtung;

	//Konstruktor
	Snake(SDL_Surface *snake){
			held = snake;
			x = 4;
			y = 4;
			richtung = SDLK_RIGHT; // das "snake" gleich zum Spielstart los läuft
		}

	//Methoden
	// Bewegung nur bis zum Rand, sonst game over
	void rechts (int geschwindigkeit){
		if (x < 18){
				x += geschwindigkeit;
		}
	} //void rechts
	void oben (int geschwindigkeit){
		if (y > 0){ // 0 für rand boom
		y -= geschwindigkeit;
		}
	}

	void unten (int geschwindigkeit){
		if (y < 18){
		y += geschwindigkeit;
		}
	}

	void links (int geschwindigkeit){
		if (x > 0){
		x -= geschwindigkeit;
		}
	}

	void malen (SDL_Surface *surf){  // "Snake" blickt in die zu laufende Richtung
		SDL_Rect source ;
		if (richtung == SDLK_RIGHT) {
    source = {x: 96, y:0, w:32, h:32};
		}
		if (richtung == SDLK_LEFT) {
			source = {x: 128, y:0, w:32, h:32};
		}
		if (richtung == SDLK_UP) {
				source = {x: 128, y:32, w:32, h:32};
			}
		if (richtung == SDLK_DOWN) {
				source = {x: 96, y:32, w:32, h:32};
			}
    SDL_Rect destination  = {x: x*32, y: y*32, w:900, h:600};
    SDL_BlitSurface(held, &source, surf, &destination);
	}

void bewegen() {  // Dauerbewegung der "snake"
	 switch (richtung) {
			 case SDLK_RIGHT: rechts(1);break;
			 case SDLK_LEFT: links(1); break;
		     case SDLK_UP: oben(1); break;
		     case SDLK_DOWN: unten(1); break;
    } //switch-schleife
}
};

int main(int a, char** b) {

	Fenster f (600,600);

	srand(time(NULL));

	    SDL_Surface *snaketiles = IMG_Load("snaketiles2.png");
	    SDL_Surface *gewonnen = IMG_Load("Gewonnen.png");
	    SDL_Surface *verloren = IMG_Load("Verloren.png");
	    SDL_Surface *titel = IMG_Load("Titel.png");

	Spielfeld brett(snaketiles);
	Snake s1(snaketiles);

    SDL_BlitSurface(titel, NULL, f.surf, NULL);
   // Titelschirm mit der "Aufgabe"
    SDL_UpdateWindowSurface(f.win);
    SDL_Delay(2000);

	 brett.zufallsfrucht(); // nur eine Frucht taucht auf

	int zaehler = 7;  // Zähler für die Früchte

	while (zaehler !=0 && brett.feld[s1.y][s1.x] != '#'){
		 SDL_Event e;
		            int taste;
		            while (SDL_PollEvent(&e) != 0) {

		             if (e.type == SDL_KEYDOWN) {
		                taste = e.key.keysym.sym;
		               switch (taste) {
		                               case SDLK_RIGHT:s1.richtung = SDLK_RIGHT; /*s1.rechts(1);*/break;
		                               case SDLK_LEFT:s1.richtung = SDLK_LEFT;/* s1.links(1);*/ break;
		                               case SDLK_UP:s1.richtung = SDLK_UP; /*s1.oben(1);*/ break;
		                               case SDLK_DOWN:s1.richtung = SDLK_DOWN;/* s1.unten(1);*/ break;
//Was passiert wenn wir die s1.rechts .. dingsis entfernen, dann verschwinden hoffentlich die lücken -> die lücke verschwindet wirklich !!!
    	                              } //switch-schleife
		             }//if-schleife
	                } // zweite while-Schleife

       s1.bewegen();
       //if an der stell eine banane/melone/traube liegt, dann einsammeln und neue frucht; neue zufallsfrucht erstellen
       if (brett.feld[s1.y][s1.x]=='b'){	// löschen leerzeichen anstatt b
	       zaehler --;
	       brett.feld[s1.y][s1.x]=' ';
	       brett.zufallsfrucht();
       }

       if (brett.feld[s1.y][s1.x]=='m'){
	       zaehler --;
	       brett.feld[s1.y][s1.x]=' ';
	       brett.zufallsfrucht();
        }

       if (brett.feld[s1.y][s1.x]=='t'){
	       zaehler --;
	       brett.feld[s1.y][s1.x]=' ';
	       brett.zufallsfrucht();
        }

SDL_BlitSurface(f.hintergrund, NULL, f.surf, NULL); // Hintergrund wird neu erstellt, altes wird überschrieben

	brett.zeichnen(f.surf); // feld wird gezeichnet

    s1.malen(f.surf); // "snake" wird gezeichnet

   SDL_UpdateWindowSurface(f.win);
   SDL_Delay(100);

	}//erste while-Schleife

     if (zaehler == 0) {  // gewonnen Bildschirm
          SDL_BlitSurface(gewonnen, NULL, f.surf, NULL);
     }

      if (brett.feld[s1.y][s1.x] == '#') {  // verloren Bildschirm
         SDL_BlitSurface(verloren, NULL, f.surf, NULL);
      }

      SDL_UpdateWindowSurface(f.win);
      SDL_Delay(1400);

	return 0;
} //main
