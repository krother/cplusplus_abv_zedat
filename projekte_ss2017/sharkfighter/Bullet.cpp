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

#include "Bullet.h"



/**
 * constructor sets initial values
 * @param srcX = source x value (player pos)
 * @param srcY = source y value (player pos)
 * @param desX = destination x value (via mousebutton event)
 * @param desY = destination y value (via mousebutton event)
 */
Bullet::Bullet(int srcX, int srcY, int desX, int desY) {
    setOnRenderer = true;

    posX = srcX;
    posY = srcY;
    this->desX = desX;
    this->desY = desY;
    bulletPos = {x:posX,y:posY,w:16,h:12};
}

/// changes the bullets position every main game loop cycle
void Bullet::timeCycle() {
    // handles game "physics" of path and speed to travel
    int dX = desX - posX;
    int dY = desY - posY;
    double dist = sqrt((dX*dX)+(dY*dY));
    double speed = 12 / dist; // speed at which Bullets move
    double xMoving = speed * dX;
    double yMoving = speed * dY;
    this->posX = (int) (xMoving + posX);
    this->posY = (int) (yMoving + posY);
    if (dist < 8) {// needs some "tolerance" when arriving at dest because of calc inaccuracy to avoid graphic errors
        setOnRenderer = false;
    } else {
        bulletPos = {x:posX,y:posY,w:16,h:12};
    }
}


