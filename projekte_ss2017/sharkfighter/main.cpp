// Copyright (c) 2017 Sebastian Kulich <input@grmlber.de>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "GameHandler.h"

void printAllVersionInfo();

int main(int argc, char **argv) {
    GameHandler game; // create gane instance

    printAllVersionInfo();

    return game.gameStart();
}

/**
 * Prints out all the versions of the SDL parts used for compiling and also the versions
 * of those they have been linked against. Mainly for debugging purposes in case of program crashes.
 */
void printAllVersionInfo() {
    printf("VERSION INFORMATIONS:\n");

    //SDL VERSION OUTPUT
    SDL_version compVerSDL;
    SDL_version linkVerSDL;
    SDL_VERSION(&compVerSDL);
    SDL_GetVersion(&linkVerSDL);
    printf("SDL compile version: %d.%d.%d\n",
           compVerSDL.major,
           compVerSDL.minor,
           compVerSDL.patch);
    printf("SDL linked version: %d.%d.%d\n",
           linkVerSDL.major,
           linkVerSDL.minor,
           linkVerSDL.patch);

    // IMG VERSION OUTPUT
    SDL_version compVerIMG;
    const SDL_version *linkVerIMG=IMG_Linked_Version();
    SDL_MIXER_VERSION(&compVerIMG);
    printf("SDL_image compile version: %d.%d.%d\n",
           compVerIMG.major,
           compVerIMG.minor,
           compVerIMG.patch);
    printf("SDL_image linked version: %d.%d.%d\n",
           linkVerIMG->major,
           linkVerIMG->minor,
           linkVerIMG->patch);

    // TTF VERSION OUTPUT
    SDL_version compVerTTF;
    const SDL_version *linkVerTTF=TTF_Linked_Version();
    SDL_TTF_VERSION(&compVerTTF);
    printf("SDL_ttf compile version: %d.%d.%d\n",
           compVerTTF.major,
           compVerTTF.minor,
           compVerTTF.patch);
    printf("SDL_ttf linked version: %d.%d.%d\n",
           linkVerTTF->major,
           linkVerTTF->minor,
           linkVerTTF->patch);

    //MIXER VERSION OUTPUT
    SDL_version compVerMIX;
    const SDL_version *linkVerMIX=Mix_Linked_Version();
    SDL_MIXER_VERSION(&compVerMIX);
    printf("SDL_mixer compile version: %d.%d.%d\n",
           compVerMIX.major,
           compVerMIX.minor,
           compVerMIX.patch);
    printf("SDL_mixer linked version: %d.%d.%d\n",
           linkVerMIX->major,
           linkVerMIX->minor,
           linkVerMIX->patch);

    printf("END OF VERSION INFORMATION\n\n");


}