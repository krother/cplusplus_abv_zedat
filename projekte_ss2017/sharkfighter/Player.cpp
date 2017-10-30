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

#include "Player.h"

#define MAX_HEALTH 100

/// sets initial values
Player::Player() {
    this->health = MAX_HEALTH; // sets initial player health to 100 (max)
    this->posX = 1366/2; // start position of player
    this->posY = 768-100;
}

/**
 * @brief returns the selected tile for current player state
 * @param figure is the tile demanded
 * @return the tile SDL_Rect
 */
SDL_Rect Player::tileSelect(unsigned int figure) {
    SDL_Rect selection;
    switch (figure) {
        case 0:                //case 0: standing right
            selection = {x:8, y:11, w:50, h:50};
            break;
        case 1:                //case 1: standing left
            selection = {x:59, y:11, w:50, h:50};
            break;
        case 2:                //case 2: jumping right
            selection = {x:212, y:11, w:50, h:50};
            break;
        case 3:                //case 3: jumping left
            selection = {x:263, y:11, w:50, h:50};
            break;
        default:
            selection = {x:8, y:11, w:50, h:50};
            break;

    }
    return selection;
}

