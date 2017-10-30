
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
using namespace std;


//zeichnen der einzelnen Bloecke

void block_zeichnen(int x, int y, char kachel, SDL_Surface *block, SDL_Surface *surf) {
    SDL_Rect source;
    switch (kachel) {
        case '#': source = {0,  0, 30, 30}; break;
        case '_': source = {0, 30, 30, 30}; break;
        case 'a': source = {30, 0, 30, 30}; break;
    }
    SDL_Rect dest = {x*30, y*30, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest);
}

// Funktionen fuer 7 unterschiedlichen Blockarten und ihre jeweils 4 moeglichen Varianten

//Figur Quadrat

void figur1_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int Zustand, int Farbe, SDL_Surface *block, SDL_Surface *surf) {
    
    switch (Zustand) {
        case 1:
            x1 = x2 = x;
            x3 = x4 = x+1;
            y1 = y3 = y;
            y2 = y4 = y+30;
            break;
        case 2:
            x1 = x2 = x;
            x3 = x4 = x+1;
            y1 = y3 = y;
            y2 = y4 = y+30;
            break;
        case 3:
            x1 = x2 = x;
            x3 = x4 = x+1;
            y1 = y3 = y;
            y2 = y4 = y+30;
            break;
        case 4:
            x1 = x2 = x;
            x3 = x4 = x+1;
            y1 = y3 = y;
            y2 = y4 = y+30;
            break;
    }
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}

// Figur Stab

void figur2_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4,  int Zustand, int Farbe,SDL_Surface *block, SDL_Surface *surf) {
    
    switch (Zustand) {
        case 1:
            x1 = x;
            x2 = x+1;
            x3 = x+2;
            x4 = x+3;
            y1 = y2 = y3 = y4 =y;
            break;
        case 2:
            y1 = y;
            y2 = y+30;
            y3 = y+60;
            y4 = y+90;
            x1 = x2 = x3 = x4 = x;
            break;
        case 3:
            x1 = x;
            x2 = x+1;
            x3 = x+2;
            x4 = x+3;
            y1 = y2 = y3 = y4 =y;
            break;
        case 4:
            y1 = y;
            y2 = y+30;
            y3 = y+60;
            y4 = y+90;
            x1 = x2 = x3 = x4 = x;
            break;
    }
    
            
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}

//Figur spiegelverkehrtes 'L'

void figur3_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int Zustand, int Farbe, SDL_Surface *block, SDL_Surface *surf) {


    switch (Zustand) {
        case 1:
            x1 = x;
            x2 = x+1;
            x3 = x4 = x+2;
            y1 = y2 = y3 = y;
            y4 = y+30;
            break;
        case 2:
            y1 = y;
            y2 = y+30;
            y3 = y+60;
            y4 = y+60;
            x1 = x2 = x3 = x+1;
            x4 = x;
            break;
        case 3:
            x1 = x2 = x;
            x3 = x+1;
            x4 = x+2;
            y1 = y;
            y2 = y3 = y4 = y+30;
            break;
        case 4:
            y1 = y2 = y;
            y3 = y+30;
            y4 = y+60;
            x1 = x3 = x4 = x;
            x2 = x+1;
            break;
            
    }
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}

//Figur Treppe

void figur4_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int Zustand, int Farbe,SDL_Surface *block, SDL_Surface *surf) {

    
    switch (Zustand) {
        case 1:
            x1 = x2 = x+1;
            x3 = x4 = x;
            y1 = y;
            y2 = y3 = y+30;
            y4 = y+60;
            break;
        case 2:
            y1 = y2 = y;
            y3 = y4 = y+30;
            x1 = x;
            x2 = x3 = x+1;
            x4 = x+2;
            break;
        case 3:
            x1 = x2 = x+1;
            x3 = x4 = x;
            y1 = y;
            y2 = y3 = y+30;
            y4 = y+60;
            break;
        case 4:
            y1 = y2 = y;
            y3 = y4 = y+30;
            x1 = x;
            x2 = x3 = x+1;
            x4 = x+2;
            break;
            
    }
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}

//Figur 'L'
void figur5_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int Zustand, int Farbe,SDL_Surface *block, SDL_Surface *surf) {
    
    switch (Zustand) {
        case 1:
            x1 = x2 = x3 = x;
            x4 = x+1;
            y1 = y;
            y2 = y+30;
            y3 = y4 = y+60;
            break;
        case 2:
            y1 = y2 = y3 = y+30;
            y4 = y;
            x1 = x;
            x2 = x+1;
            x3 = x4 = x+2;
            break;
        case 3:
            x1 = x;
            x2 = x3 = x4 = x+1;
            y1 = y2 = y;
            y3 = y+30;
            y4 = y+60;
            break;
        case 4:
            y1 = y2 = y3 =y;
            y4 = y+30;
            x1 = x4 = x;
            x2 = x+1;
            x3 = x+2;
            break;
            
    }
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}

//Figur Podest
void figur6_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int Zustand, int Farbe,SDL_Surface *block, SDL_Surface *surf) {
    
    switch (Zustand) {
        case 1:
            x1 = x;
            x2 = x4 = x+1;
            x3 = x+2;
            y1 = y2 = y3 = y;
            y4 = y+30;
            break;
        case 2:
            x1 = x2 = x3 = x;
            x4 = x+1;
            y1 = y;
            y2 = y4 = y+30;
            y3 = y+60;
            break;
        case 3:
            x1 = x;
            x2 = x4 = x+1;
            x3 = x+2;
            y1 = y2 = y3 = y+30;
            y4 = y;
            break;
        case 4:
            x1 = x2 = x3 = x+1;
            x4 = x;
            y1 = y;
            y2 = y4 = y+30;
            y3 = y+60;
            break;
            
    }
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}

//Figur Treppe gespiegelt
void figur7_zeichnen(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int Zustand, int Farbe,SDL_Surface *block, SDL_Surface *surf) {
    
    
    switch (Zustand) {
        case 1:
            x1 = x2 = x;
            x3 = x4 = x+1;
            y1 = y;
            y2 = y3 = y+30;
            y4 = y+60;
            break;
        case 2:
            y1 = y2 = y+30;
            y3 = y4 = y;
            x1 = x;
            x2 = x3 = x+1;
            x4 = x+2;
            break;
        case 3:
            x1 = x2 = x;
            x3 = x4 = x+1;
            y1 = y;
            y2 = y3 = y+30;
            y4 = y+60;
            break;
        case 4:
            y1 = y2 = y+30;
            y3 = y4 = y;
            x1 = x;
            x2 = x3 = x+1;
            x4 = x+2;
            break;
            
    }
    
    SDL_Rect source = {Farbe*30, 0, 30, 30};
    SDL_Rect dest1 = {x1*30, y1, 30, 30};
    SDL_Rect dest2 = {x2*30, y2, 30, 30};
    SDL_Rect dest3 = {x3*30, y3, 30, 30};
    SDL_Rect dest4 = {x4*30, y4, 30, 30};
    SDL_BlitSurface(block, &source, surf, &dest1);
    SDL_BlitSurface(block, &source, surf, &dest2);
    SDL_BlitSurface(block, &source, surf, &dest3);
    SDL_BlitSurface(block, &source, surf, &dest4);
}


//zeichnen des Spielfeldes
void spielfeld_zeichnen(char spielfeld[20][12], SDL_Surface *block, SDL_Surface *surf) {
    for(int x=0; x<12; x++) {
        for(int y=0; y<20; y++) {
            char kachel = spielfeld[y][x];
            block_zeichnen(x, y, kachel, block, surf);
        }
    }
}

//Bildschirm vor Beginn des Spiels
void spiel_beginn(SDL_Surface *beginn, SDL_Surface *surf, SDL_Window *win) {
    SDL_Rect source ={20, 0, 360, 600};
    SDL_Rect dest = {0, 0, 360, 600};
    bool weiter = false;
    while (!weiter)
    {
        SDL_BlitSurface(beginn, &source, surf, &dest);
        SDL_UpdateWindowSurface(win);
        SDL_Event e;
        if ( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_KEYDOWN ) {
                if (e.key.keysym.sym == 13) {
                    weiter = true;}
            }
        }
    }
}

//Bildschirm und Ausgabe nach Spielbeendigung
void game_over(int spielstand, int level, SDL_Surface *gameover, SDL_Surface *surf, SDL_Window *win) {
    SDL_Rect source ={20, 0, 360, 600};
    SDL_Rect dest = {0, 0, 360, 600};
    SDL_BlitSurface(gameover, &source, surf, &dest);
    cout << "Spiel beendet" <<endl;
    cout << "Herzlichen Glueckwunsch." << endl;
    cout << "Sie haben Level "<< level <<" erreicht und " << spielstand << " Punkte erzielt!" << endl;
    SDL_UpdateWindowSurface(win);
    SDL_Delay(3000);
}

//Spiel pausieren
void spiel_stop(SDL_Surface *stop, SDL_Surface *surf, SDL_Window *win) {
    SDL_Rect source ={0, 0, 50, 50};
    SDL_Rect dest = {155, 275, 50, 50};
    bool weiter = false;
    while (!weiter)
    {
        SDL_BlitSurface(stop, &source, surf, &dest);
        SDL_UpdateWindowSurface(win);
        SDL_Event e;
        if ( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_KEYDOWN ) {
                if (e.key.keysym.sym == 32) {
                    weiter = true;}
            }
        }
    }
}


//Hauptprogramm
int main(int, char **) {
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("TrojTris", 100, 100, 360, 600, SDL_WINDOW_SHOWN);
    SDL_Surface* surf = SDL_GetWindowSurface(win);
    
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *Hintergrund = IMG_Load("background.png");
    SDL_Surface *block = IMG_Load("blocks.png");
    SDL_Surface *gameover = IMG_Load("gameover.png");
    SDL_Surface *pause = IMG_Load("Pause.png");
    SDL_Surface *start = IMG_Load("trojtris.png");
    
 //Zufallsvariablen für Blockart und Farbe
    srand((unsigned)time(NULL));
    int zufall = rand() % 7 + 1;
    int Farbe = rand() % 3 + 2;
    
 //Spielfeld
    char spielfeld[20][12] = {
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
 

    };
    
    spiel_beginn(start, surf, win);
    
 //Definition nötiger Variablen
    int figur_x = 5;
    int figur_y = 0;
    
    int x_neu = 5;
    int y_neu = 0;
    int Zustand = 1;
    
    int pruefen = 0;
    int Punkte = 0;
    int Geschwindigkeit = 1;

//Beginn der Tastenabfrage mittels Schleife
    SDL_Event e;
    bool ende = false;
    bool neuer_block = false;
    while (!ende) {
        
//Ueberpruefung ob Spiel verloren
        for (int over=1; over<12; over++) {
            if (spielfeld[0][over] == 'a') {
                ende = true;
            }
        }
//neuen Block ins Spiel bringen
        if (neuer_block == true) {
            y_neu = 0;
            x_neu = 5;
            zufall = rand() % 7 + 1;
            Farbe = rand() % 3 + 2;
            neuer_block = false;
        }
        
        y_neu += Geschwindigkeit;
        
        
        figur_y = y_neu;
        figur_x = x_neu;

//konkrete Tastaturabfrage
        if ( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_KEYDOWN ) {
                switch (e.key.keysym.sym) {
                    case 27: ende = true; break;
                    case 32: spiel_stop(pause, surf, win); break;
                    case SDLK_UP: Zustand += 1; break;
                    case SDLK_DOWN: y_neu += 10*Geschwindigkeit; break;
                    case SDLK_LEFT: x_neu -= 1; break;
                    case SDLK_RIGHT: x_neu += 1;
                        break;
                }
            }
            
        }
        
       if (Zustand == 5) {Zustand = 1;}
       if (x_neu == 0) {x_neu = 1;};
        
        int y_pos = figur_y/30;
        int x_pos = figur_x;
        
//Ueberpruefung des Standortes der einzelnen Bloecke um Kollision zu ueberpruefen und zu vermeiden,
//dass der Block ueber den rechten Rand hinaus geht.
        
        switch(zufall){
            case 1:
                if (x_neu >= 10) {x_neu = 9;}
                
                if (spielfeld[y_pos+2][x_pos] == '#' ||
                        spielfeld[y_pos+2][x_pos] == 'a' ||
                        spielfeld[y_pos+2][x_pos+1] == '#' ||
                        spielfeld[y_pos+2][x_pos+1] == 'a')
                {
                spielfeld[y_pos][x_pos] = 'a';
                spielfeld[y_pos+1][x_pos] = 'a';
                spielfeld[y_pos][x_pos+1] = 'a';
                spielfeld[y_pos+1][x_pos+1] = 'a';
                neuer_block = true;
                    };
                break;
            
            case 2: if (Zustand == 1 || Zustand == 3)
                    {   if (x_neu >= 8) {x_neu = 7;}
                        if (spielfeld[y_pos+1][x_pos] == '#' ||
                            spielfeld[y_pos+1][x_pos] == 'a' ||
                            spielfeld[y_pos+1][x_pos+1] == '#' ||
                            spielfeld[y_pos+1][x_pos+1] == 'a' ||
                            spielfeld[y_pos+1][x_pos+2] == '#' ||
                            spielfeld[y_pos+1][x_pos+2] == 'a' ||
                            spielfeld[y_pos+1][x_pos+3] == '#' ||
                            spielfeld[y_pos+1][x_pos+3] == 'a' )
                        {
                            spielfeld[y_pos][x_pos] = 'a';
                            spielfeld[y_pos][x_pos+1] = 'a';
                            spielfeld[y_pos][x_pos+2] = 'a';
                            spielfeld[y_pos][x_pos+3] = 'a';
                            neuer_block = true;
                        };
                
                    }
                if (Zustand == 2 || Zustand == 4)
                {   if (x_neu >= 11) {x_neu = 10;}
                    if (spielfeld[y_pos+4][x_pos] == '#' ||
                        spielfeld[y_pos+4][x_pos] == 'a' )
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+2][x_pos] = 'a';
                        spielfeld[y_pos+3][x_pos] = 'a';
                        neuer_block = true;
                    };
                    
                };
                break;
                
                
            case 3:
                switch(Zustand){
                    case 1:
                        if (x_neu >= 9) {x_neu = 8;}
                        if (spielfeld[y_pos+1][x_pos] == '#' ||
                                spielfeld[y_pos+1][x_pos] == 'a' ||
                                spielfeld[y_pos+1][x_pos+1] == '#' ||
                                spielfeld[y_pos+1][x_pos+1] == 'a' ||
                                spielfeld[y_pos+2][x_pos+2] == '#' ||
                                spielfeld[y_pos+2][x_pos+2] == 'a' )
                            {
                                spielfeld[y_pos][x_pos] = 'a';
                                spielfeld[y_pos][x_pos+1] = 'a';
                                spielfeld[y_pos][x_pos+2] = 'a';
                                spielfeld[y_pos+1][x_pos+2] = 'a';
                                neuer_block = true;
                            }; break;
                    case 2:
                        if (x_neu >= 10) {x_neu = 9;}
                        if (spielfeld[y_pos+3][x_pos] == '#' ||
                                spielfeld[y_pos+3][x_pos] == 'a' ||
                                spielfeld[y_pos+3][x_pos+1] == '#' ||
                                spielfeld[y_pos+3][x_pos+1] == 'a')
                    {
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+2][x_pos+1] = 'a';
                        spielfeld[y_pos+2][x_pos] = 'a';
                        neuer_block = true;
                    }; break;
                    case 3:
                        if (x_neu >= 9) {x_neu = 8;}
                        if (spielfeld[y_pos+2][x_pos] == '#' ||
                                spielfeld[y_pos+2][x_pos] == 'a' ||
                                spielfeld[y_pos+2][x_pos+1] == '#' ||
                                spielfeld[y_pos+2][x_pos+1] == 'a' ||
                                spielfeld[y_pos+2][x_pos+2] == '#' ||
                                spielfeld[y_pos+2][x_pos+2] == 'a')
                    {
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+2] = 'a';
                        spielfeld[y_pos][x_pos] = 'a';
                        neuer_block = true;
                    }; break;
                        
                    case 4:
                        if (x_neu >= 10) {x_neu = 9;}
                        if (spielfeld[y_pos+3][x_pos] == '#' ||
                                spielfeld[y_pos+3][x_pos] == 'a' ||
                                spielfeld[y_pos+1][x_pos+1] == '#' ||
                                spielfeld[y_pos+1][x_pos+1] == 'a')
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+2][x_pos] = 'a';
                        neuer_block = true;
                    }; break;
                };
                break;
                
            case 4: if (Zustand == 2 || Zustand == 4)
            {   if (x_neu >= 9) {x_neu = 8;}
                if (spielfeld[y_pos+1][x_pos] == '#' ||
                    spielfeld[y_pos+1][x_pos] == 'a' ||
                    spielfeld[y_pos+2][x_pos+1] == '#' ||
                    spielfeld[y_pos+2][x_pos+1] == 'a' ||
                    spielfeld[y_pos+2][x_pos+2] == '#' ||
                    spielfeld[y_pos+2][x_pos+2] == 'a' )
                {
                    spielfeld[y_pos][x_pos] = 'a';
                    spielfeld[y_pos][x_pos+1] = 'a';
                    spielfeld[y_pos+1][x_pos+1] = 'a';
                    spielfeld[y_pos+1 ][x_pos+2] = 'a';
                    neuer_block = true;
                };
                
            }
                if (Zustand == 1 || Zustand == 3)
                {   if (x_neu >= 10) {x_neu = 9;}
                    if (spielfeld[y_pos+3][x_pos] == '#' ||
                        spielfeld[y_pos+3][x_pos] == 'a' ||
                        spielfeld[y_pos+2][x_pos+1] == '#' ||
                        spielfeld[y_pos+2][x_pos+1] == 'a')
                    {
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+2][x_pos] = 'a';
                        neuer_block = true;
                    }; break;
                    
                };
                
                break;
                
            case 5:
                switch(Zustand){
                    case 1:
                        if (x_neu >= 10) {x_neu = 9;}
                        if (spielfeld[y_pos+3][x_pos] == '#' ||
                                spielfeld[y_pos+3][x_pos] == 'a' ||
                                spielfeld[y_pos+3][x_pos+1] == '#' ||
                                spielfeld[y_pos+3][x_pos+1] == 'a' )
                                
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+2][x_pos] = 'a';
                        spielfeld[y_pos+2][x_pos+1] = 'a';
                        neuer_block = true;
                    }; break;
                    case 2:
                        if (x_neu >= 9) {x_neu = 8;}
                        if (spielfeld[y_pos+2][x_pos] == '#' ||
                                spielfeld[y_pos+2][x_pos] == 'a' ||
                                spielfeld[y_pos+2][x_pos+1] == '#' ||
                                spielfeld[y_pos+2][x_pos+1] == 'a' ||
                                spielfeld[y_pos+2][x_pos+2] == '#' ||
                                spielfeld[y_pos+2][x_pos+2] == 'a' )
                    {
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+2] = 'a';
                        spielfeld[y_pos][x_pos+2] = 'a';
                        neuer_block = true;
                    }; break;
                    case 3:
                        if (x_neu >= 10) {x_neu = 9;}
                        if (spielfeld[y_pos+1][x_pos] == '#' ||
                                spielfeld[y_pos+1][x_pos] == 'a' ||
                                spielfeld[y_pos+3][x_pos+1] == '#' ||
                                spielfeld[y_pos+3][x_pos+1] == 'a' )
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+2][x_pos+1] = 'a';
                        neuer_block = true;
                    }; break;
                    case 4:
                        if (x_neu >= 9) {x_neu = 8;}
                        if (spielfeld[y_pos+2][x_pos] == '#' ||
                                spielfeld[y_pos+2][x_pos] == 'a' ||
                                spielfeld[y_pos+1][x_pos+1] == '#' ||
                                spielfeld[y_pos+1][x_pos+1] == 'a'||
                                spielfeld[y_pos+1][x_pos+2] == '#' ||
                                spielfeld[y_pos+1][x_pos+2] == 'a')
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos][x_pos+2] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        neuer_block = true;
                    }; break;
                }; break;
                
            case 6:
                switch(Zustand){
                    case 1:
                        if (x_neu >= 9) {x_neu = 8;}
                        if (spielfeld[y_pos+1][x_pos] == '#' ||
                                spielfeld[y_pos+1][x_pos] == 'a' ||
                                spielfeld[y_pos+2][x_pos+1] == '#' ||
                                spielfeld[y_pos+2][x_pos+1] == 'a' ||
                                spielfeld[y_pos+1][x_pos+2] == '#' ||
                                spielfeld[y_pos+1][x_pos+2] == 'a' )
                        
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos][x_pos+2] = 'a';
                        neuer_block = true;
                    }; break;
                    case 2:
                        if (x_neu >= 10) {x_neu = 9;}
                        if (spielfeld[y_pos+3][x_pos] == '#' ||
                                spielfeld[y_pos+3][x_pos] == 'a' ||
                                spielfeld[y_pos+2][x_pos+1] == '#' ||
                                spielfeld[y_pos+2][x_pos+1] == 'a' )
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+2][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        neuer_block = true;
                    }; break;
                    case 3:
                        if (x_neu >= 9) {x_neu = 8;}
                        if (spielfeld[y_pos+2][x_pos] == '#' ||
                                spielfeld[y_pos+2][x_pos] == 'a' ||
                                spielfeld[y_pos+2][x_pos+1] == '#' ||
                                spielfeld[y_pos+2][x_pos+1] == 'a' ||
                                spielfeld[y_pos+2][x_pos+2] == '#' ||
                                spielfeld[y_pos+2][x_pos+2] == 'a' )
                    {
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+2] = 'a';
                        neuer_block = true;
                    }; break;
                    case 4:
                        if (x_neu >= 10) {x_neu = 9;}
                        if (spielfeld[y_pos+2][x_pos] == '#' ||
                                spielfeld[y_pos+2][x_pos] == 'a' ||
                                spielfeld[y_pos+3][x_pos+1] == '#' ||
                                spielfeld[y_pos+3][x_pos+1] == 'a')
                    {
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos][x_pos+1] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+2][x_pos+1] = 'a';
                        neuer_block = true;
                    }; break;
                }; break;
                
                
            case 7: if (Zustand == 2 || Zustand == 4)
            {   if (x_neu >= 9) {x_neu = 8;}
                if (spielfeld[y_pos+2][x_pos] == '#' ||
                    spielfeld[y_pos+2][x_pos] == 'a' ||
                    spielfeld[y_pos+2][x_pos+1] == '#' ||
                    spielfeld[y_pos+2][x_pos+1] == 'a' ||
                    spielfeld[y_pos+1][x_pos+2] == '#' ||
                    spielfeld[y_pos+1][x_pos+2] == 'a' )
                {
                    spielfeld[y_pos+1][x_pos] = 'a';
                    spielfeld[y_pos][x_pos+1] = 'a';
                    spielfeld[y_pos+1][x_pos+1] = 'a';
                    spielfeld[y_pos][x_pos+2] = 'a';
                    neuer_block = true;
                };
                
            }
                if (Zustand == 1 || Zustand == 3)
                {   if (x_neu >= 10) {x_neu = 9;}
                    if (spielfeld[y_pos+2][x_pos] == '#' ||
                        spielfeld[y_pos+2][x_pos] == 'a' ||
                        spielfeld[y_pos+3][x_pos+1] == '#' ||
                        spielfeld[y_pos+3][x_pos+1] == 'a')
                    {
                        spielfeld[y_pos][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos] = 'a';
                        spielfeld[y_pos+1][x_pos+1] = 'a';
                        spielfeld[y_pos+2][x_pos+1] = 'a';
                        neuer_block = true;
                    }
                };break;
        }
        
//ueberpruefen ob eine Zeile geloescht werden muss/ Punkte dazu zählen.
        for (int y=0; y<19; y++){
                 pruefen = 0;
                 for(int x=0; x<12; x++) {
                     if (spielfeld[y][x] == '_'){
                         pruefen++;
                     }
                 }
                     if (pruefen == 0){
                         Punkte++;
                         for (int y1=y; y1>0; y1--)
                             for(int x=0; x<12; x++) {
                                 spielfeld[y1][x] = spielfeld[y1-1][x];
                                 spielfeld[0][x] = '_';
                                 spielfeld[0][0] = '#';
                                 spielfeld[0][11] = '#';
                         }
//Erhoehung der Schwierigkeit nach 10 geloeschten Zeilen.
                         if (Punkte % 10 == 0) {Geschwindigkeit += 1;}
                     }
        }
        
//alles zeichnen
        
        SDL_BlitSurface(Hintergrund, NULL, surf, NULL);
        spielfeld_zeichnen(spielfeld, block, surf);
        switch(zufall){
                case 1: figur1_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
                case 2: figur2_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
                case 3: figur3_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
                case 4: figur4_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
                case 5: figur5_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
                case 6: figur6_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
                case 7: figur7_zeichnen(figur_x, figur_y, 0, 0, 0, 0, 0, 0, 0, 0, Zustand, Farbe, block, surf); break;
            }
        SDL_UpdateWindowSurface(win);
        SDL_Delay(20);
        
            }
    game_over(Punkte, Geschwindigkeit, gameover, surf, win);
}
