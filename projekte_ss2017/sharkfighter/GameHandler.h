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

#ifndef SHARKFIGHTER_GAMEHANDLER_H
#define SHARKFIGHTER_GAMEHANDLER_H

//SDL includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//misc includes
#include <string>
#include <vector>
#include <cstdio>

//own classes includes
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


//const values
const int RIGHT = 0;
const int LEFT = 1;
const int J_RIGHT = 2;
const int J_LEFT = 3;

class GameHandler {
public:
    GameHandler();
    int gameStart();

private:
    // functions
    void run();
    bool GameInit();
    int showStartMenu();
    int showAbout();
    void gameEventHandling();
    int startMenuEventHandling();
    void loopHandling();
    void drawingHandling();
    void renderPlayer(unsigned int figure);
    void renderBullets();
    void renderEnemy();
    SDL_Texture* loadTexture(std::string filePath);
    bool freefallSituation();
    void showHealth();
    void showDestruction();
    void showScore();
    void emitBullet(int srcX, int srcY, int desX, int desY);
    void emitEnemy();
    void hitCheck();
    void resetValues();
    void showGameOver();
    void gameoverCheck();
    void spawnEnemy();
    void renderText(std::string string, int x, int y, int w, int h, SDL_Color color);
    int loadComponents(); // loads all needed textures, sounds, fonts
    void cleanComponents(); // cleans up and destroyes all textures, sounds, fonts
    TTF_Font* loadFont(std::string filePath);
    Mix_Chunk* loadSoundChunk(std::string filePath);

    // SDL basics
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    // variables and flags
    int destructionLevel;
    bool gameIsRunning;
    int playerDirection;
    int score;
    int desX, desY;
    unsigned int priorTime, currentTime;
    float spawnTime;
    bool isGameover;

    //SDL_Rects
    SDL_Rect bulletRect = {x:204,y:250,w:8,h:6}; // Bullet on tiles set
    SDL_Rect playerPos;

    // Graphics / textures
    SDL_Texture* background = nullptr;
    SDL_Texture* playerTiles = nullptr;
    SDL_Texture* fish = nullptr;
    SDL_Texture* explosion = nullptr;

    // fonts
    TTF_Font* font;

    // vectors
    std::vector<Bullet*> bullets; // for dynamically adding active bullets
    std::vector<Enemy*> enemies; // for dynamically adding active bullets
    std::vector<SDL_Rect*> explosions;

    // SDL_Colors
    SDL_Color orange = {235,120,0,235};
    SDL_Color dorange = {165,75,20,255};
    SDL_Color blue = {10,0,160,255};
    SDL_Color lblue = {20,0,180,225};
    SDL_Color green = {0,165,30,255};
    SDL_Color black = {0,0,0,255};
    SDL_Color grey = {220,220,220,255};

    // sound chunks
    Mix_Chunk* soundBullet = nullptr;
    Mix_Chunk* soundScore = nullptr;
    Mix_Chunk* soundDestruction = nullptr;
    Mix_Chunk* soundHealth = nullptr;

};


#endif //SHARKFIGHTER_GAMEHANDLER_H
