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

#ifndef SHARKFIGHTER_ENEMY_H
#define SHARKFIGHTER_ENEMY_H

#include <cstdlib>
#include <SDL_system.h>
#include <SDL_rect.h>
#include <SDL_timer.h>


class Enemy {
public:
    Enemy(); //constructor
    double dist;
    int startX, startY, destX, destY, posX, posY;
    SDL_Rect enemyPos;

    // functions
    void timeCycle();
    bool setOnRenderer;
    bool damageDone;
};


#endif //SHARKFIGHTER_ENEMY_H
