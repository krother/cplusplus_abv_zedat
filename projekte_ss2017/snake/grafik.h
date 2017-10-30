#ifndef GRAFIK_H_
#define GRAFIK_H_
#include <SDL.h>
#include <SDL_image.h>

class Fenster {
  public:
    SDL_Window *win;
    SDL_Surface *surf;
    SDL_Surface *hintergrund;

    Fenster(int, int);
};

#endif /* GRAFIK_H_ */

