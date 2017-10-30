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

#include "Enemy.h"

/**
 * @brief sets initial values and creates path for enemy to travel
 * @details picks a random point outside visible area over the top screen limitation and a random point on the bottom
 * ground of the window and lets the enemy travel from the first upper point to the lower one.
 * @param world
 */
Enemy::Enemy() {
    dist = 0.;
    setOnRenderer = true; // is visible and not ready to be deleted
    damageDone = false; // still has damaging potential

    srand(SDL_GetTicks());
    startX = rand() % 1366;
    startY = (-20); // outside of visible scope
    destX = rand() % 1366;
    destY = 786;
    posX = startX;
    posY = startY;
}

/// position updates that happens every main game loop cycle
void Enemy::timeCycle() {
    // calculates the "game physics" for path travel of enemy
    int dX = destX - posX;
    int dY = destY - posY;
    dist = sqrt((dX*dX)+(dY*dY));
    //double speed = 6 / dist; // speed at which enemy moves
    double speed = 2 / dist; // speed at which enemy moves
    double xMoving = speed * dX;
    double yMoving = speed * dY;
    this->posX = (int) (xMoving + posX);
    this->posY = (int) (yMoving + posY);
    if (damageDone) { // needs some "tolerance" when arriving at dest because of calc inaccuracy to avoid graphic errors
        setOnRenderer = false;
    } else {
        enemyPos = {x:posX,y:posY,w:74,h:54};
    }
}
