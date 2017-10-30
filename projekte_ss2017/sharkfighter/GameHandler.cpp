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

Player player;
GameHandler::GameHandler() {
    if (!GameInit()) {
        fprintf( stderr, "Could not initialize the game environment. Closing.");
        exit(1);
    }
}

/**
 * \brief initializes the game and SDL environment
 * \return true if init was successful, false if not
 */
bool GameHandler::GameInit() {
    //SDL init
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return false; //error
    }
    // window init
    window = SDL_CreateWindow("SharkFighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf( stderr, "Error occured during window creation. Msg: %s\n", SDL_GetError());
        return false;
    }

    // renderer init
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        fprintf( stderr, "Error occured during renderer init. Msg: %s\n", SDL_GetError());
        return false;
    }

    if (TTF_Init() == -1) {
        fprintf( stderr, "Error occured during TTF init. Msg: %s\n", SDL_GetError());
        return false;
    }

    if(!TTF_WasInit() && TTF_Init()==-1) {
        fprintf(stderr,"Error occured during TTF_WasInit. TTF_Init: %s\n", TTF_GetError());
        exit(1);
    }

    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0) {
        fprintf(stderr,"Error occured during Mix_OpenAudio. Msg: %s\n", Mix_GetError());
        return false;
    }

    if (IMG_Init( IMG_INIT_PNG ) == -1) {
        fprintf( stderr, "Error occured during IMG init. Msg: %s\n", IMG_GetError());
        return false;
    }
       SDL_RaiseWindow(window); // sets window to foreground and puts focus on it

    return true; // init successful
}

/**
 * @brief initializes all initial values and starts game (menu)
 * @return 0 if exited correctly
 */
int GameHandler::gameStart() {
    // set all initial game values
    gameIsRunning = true;
    playerDirection = RIGHT;
    score = 0;
    spawnTime = 2000;
    priorTime = 0;
    destructionLevel = 0;

    // load all components
    if (loadComponents() == 1) {
        fprintf(stderr,"Error whilst loading game components. Abort.");
        exit(1);
    }

    int menuChoice = 0;
    bool menuShowing = true;
    while (menuShowing) {
        menuChoice = showStartMenu();
        switch (menuChoice) {
            case 1:
                run();
                break;
            case 3:
                if (showAbout() == 0) {menuShowing = false; break;}
                break; //finish up and leave program
            case 0:
                menuShowing = false;
                break;
            default:
                break;
        }
    }

    cleanComponents(); // cleans and destroyes all components
    return 0; // returns to main
}

/**
 * @brief Main game function includes main game loop
 */
void GameHandler::run() {
    gameIsRunning = true;
    isGameover = false;

    // main loop
    while (gameIsRunning) {
        gameEventHandling(); // calls event handling
        loopHandling();     // calls loop actions to be done every loop repetition
        drawingHandling();  // does all the drawing and rendering
        SDL_Delay(32);      // 32ms delay for loop
    }
}

/**
 * @brief Handles in-game events like moving via keyboard events, ...
 */
void GameHandler::gameEventHandling() {
    while( SDL_PollEvent( &event ) != 0 ) {
        if (event.type == SDL_QUIT) { // window close event
            gameIsRunning = false;
            exit(1);
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) { // firing bullets via any mousebutton
            SDL_MouseButtonEvent click = event.button;
            desX = click.x;
            desY = click.y;
            emitBullet(player.posX+50, player.posY+50, desX, desY);
        }
        if( event.type == SDL_KEYDOWN ) { // movement inputs
            int key = event.key.keysym.sym;
            switch (key) {
                case SDLK_ESCAPE:
                    gameIsRunning = false; // due to this, exit to menu level
                    break;
                case SDLK_RIGHT:
                    playerDirection = RIGHT;
                    if(player.posX < 1366-80) {
                        player.posX += 10;
                    }
                    break;
                case SDLK_LEFT:
                    playerDirection = LEFT;
                    if(player.posX > -10){
                        player.posX-=10;
                    }
                    break;
                case SDLK_UP:
                    if (playerDirection == LEFT || playerDirection == J_LEFT) {
                        playerDirection = J_LEFT;
                    } else {
                        playerDirection = J_RIGHT;
                    }
                    if (player.posY > 0) {
                        player.posY-=50;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

/**
 * @brief performes tasks that are in game actions, like moving objects and creating
 * enemies
 */
void GameHandler::loopHandling() {

    /* This created "gravity" only on the player figure, meaning
     * the player if not on ground will move towards ground ("fall")
     * every loop cycle */
    if (freefallSituation()) { // checks if player is not on ground
        if((768-100)-player.posY < 2) {
            player.posY = (768-100)-player.posY;
        } else {
            player.posY += 2;
        }
        if (playerDirection == LEFT) {playerDirection = J_LEFT;}
        if (playerDirection == RIGHT) {playerDirection = J_RIGHT;}
    } else {
        if (playerDirection == J_LEFT) {playerDirection = LEFT;}
        if (playerDirection == J_RIGHT) {playerDirection = RIGHT;}
    }

    //let bullets position change every cycle
    for(int i = 0; i < bullets.size(); ++i) {
        bullets.at(i)->timeCycle();
        //delete them if not used anymore
        if (!bullets.at(i)->setOnRenderer) {
            delete(bullets.at(i));
            bullets.erase(bullets.begin()+i);
        }
    }
    //let enemies position change every cycle
    for(int i = 0; i < enemies.size(); ++i) {
        enemies.at(i)->timeCycle();
        //delete them if not used anymore
        if (!enemies.at(i)->setOnRenderer) {
            delete(enemies.at(i));
            enemies.erase(enemies.begin()+i);
        }
    }

    hitCheck(); //Checks for target hits/collisions and handles them

    gameoverCheck(); //Checks if game is gameover state and handles it

    spawnEnemy(); //Creates random enemies in game


}

/**
 * @brief Handles the drawing of objects and texts
 */
void GameHandler::drawingHandling() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr); // Renders background picture
    renderPlayer(playerDirection); //renders the player at the playerposition facing the right way (playerDirection)
    renderBullets();
    renderEnemy();

    showHealth();
    showDestruction();
    showScore();

    // goes through the not-yet-rendered explosions, renders them and clears them afterwards
    for (SDL_Rect* rect : explosions) {
        SDL_RenderCopy(renderer,explosion,nullptr,rect);
    }
    explosions.clear();

    //if gamestate is gameover, show message of it and wait 2s
    if (isGameover) {
        showGameOver();
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
    } else {
        SDL_RenderPresent(renderer);
    }
}

/**
 * @brief checks if game is over and sets isGameover flag, calls the rendering routine to state that message and
 * then resets all values for new game
 */
void GameHandler::gameoverCheck() {
    if (player.health == 0 || destructionLevel == 100) {
        isGameover = true;
        drawingHandling();
        resetValues();
        gameIsRunning = false; // due to this game returns to menu level
    }
}

/**
 * @brief emits new enemy if its time for a new one
 */
void GameHandler::spawnEnemy() {
    currentTime = SDL_GetTicks();
    if (currentTime > priorTime+spawnTime) {
        emitEnemy();
        priorTime = currentTime;
    }
}

/**
 * @brief Renders the player at current position and with current facing directions
 * @param figure
 */
void GameHandler::renderPlayer(unsigned int figure) {
    SDL_Rect srcRect = player.tileSelect(figure);
    SDL_Rect destRect = {x:player.posX,y:player.posY,w:100,h:100};
    SDL_RenderCopy(renderer,playerTiles,&srcRect,&destRect);
}

/**
 * @brief checks if player is higher than ground
 * @return false if not and true if player is higher than ground
 */
bool GameHandler::freefallSituation() {
    return player.posY != 768 - 100;
}

/// renders the health on screen
void GameHandler::showHealth() {
    std::string str = "Life: ";
    str += std::to_string(player.health);
    renderText(str,10,10,80,40,green);
}

/// renders the destruction level on screen
void GameHandler::showDestruction() {
    std::string str = "Destruction: ";
    str += std::to_string(destructionLevel);
    str += "%";
    renderText(str,110,10,150,40,dorange);
}

/// renders the score on screen
void GameHandler::showScore() {
    std::string str = "Score: ";
    str += std::to_string(score);
    str += "P";
    renderText(str,280,10,90,40,blue);
}

/**
 * @brief handles text rendering
 * @param string = string to be displayed
 * @param x = x pos of message rect
 * @param y = y pos of message rect
 * @param w = w pos of message rect
 * @param h = h pos of message rect
 * @param color = Color of text
 */
void GameHandler::renderText(std::string string, int x, int y, int w, int h, SDL_Color color) {
    SDL_Surface* messageSur = TTF_RenderUTF8_Blended(font, string.c_str(), color);
    SDL_Texture* messageTex = SDL_CreateTextureFromSurface(renderer,messageSur);
    SDL_Rect messageRect = {x:x,y:y,w:w,h:h};
    SDL_RenderCopy(renderer, messageTex, nullptr, &messageRect);
    SDL_FreeSurface(messageSur);
    SDL_DestroyTexture(messageTex);
}

/**
 * emits a new bullet on emitting event
 * @param srcX = origin x value of bullet (player position)
 * @param srcY = origin y value of bullet (player position)
 * @param desX = destination x value of bullet
 * @param desY = destination y value of bullet
 */
void GameHandler::emitBullet(int srcX, int srcY, int desX, int desY) {
    Mix_PlayChannel(-1, soundBullet,0); // plays sound
    bullets.push_back(new Bullet(srcX,srcY,desX,desY)); // adds new bullet to vector containing bullet objects
}

/// emits new enemy object and adds it to enemy-containing vector
void GameHandler::emitEnemy() {
    enemies.push_back(new Enemy());
}

/// renders all enemies from enemies vector
void GameHandler::renderEnemy() {
    SDL_Rect destRect;
    for(int i = 0; i < enemies.size(); ++i) {
        if (enemies.at(i)->setOnRenderer) {
            destRect = enemies.at(i)->enemyPos;
            SDL_RenderCopy(renderer, fish, nullptr, &destRect);
        }
    }
}

/// renders all bullets from bullets vector
void GameHandler::renderBullets() {
    SDL_Rect destRect;
    for(int i = 0; i < bullets.size(); ++i) {
        if (bullets.at(i)->setOnRenderer) {
            destRect = bullets.at(i)->bulletPos;
            SDL_RenderCopy(renderer, playerTiles, &bulletRect, &destRect);
        }
    }
}

/**
 * @brief checks every cycle for collisions between objects
 * @details checks for collisions between bullets and enemies and between enemies and player and triggers actions
 * @warning this way of checking for collisions is highly inefficient due to the amount of checks that need to be done
 * with increasing amount of objects
 */
void GameHandler::hitCheck() {
    playerPos = {x: player.posX, y:player.posY, w:50,h:50};
    for (int i = 0; i < enemies.size(); ++i) {
        if (SDL_HasIntersection(&enemies.at(i)->enemyPos, &playerPos)) {
            player.health -= 25; // intersection between player and enemy leads to descrease in health
            Mix_PlayChannel(-1, soundHealth,0);
            enemies.at(i)->setOnRenderer = false; // make enemy disappear
        }
        if (enemies.at(i)->dist < 8 && !enemies.at(i)->damageDone) {
            //destructionLevel += 10; // enemy hits ground, causes damage
            destructionLevel += 1; // enemy hits ground, causes damage
            enemies.at(i)->damageDone = true;
            Mix_PlayChannel(-1,soundDestruction,0);
        }
        for (int j = 0; j < bullets.size(); ++j) {
            if (SDL_HasIntersection(&enemies.at(i)->enemyPos, &bullets.at((j))->bulletPos)) {
                score++;
                Mix_PlayChannel(-1, soundScore,0);
                // adds an explosion the the explosions vector and sets rect where it should appear
                explosions.push_back(new SDL_Rect());
                explosions.back()->x = enemies.at(i)->enemyPos.x;
                explosions.back()->y = enemies.at(i)->enemyPos.y;
                explosions.back()->w = 60;
                explosions.back()->h = 60;
                enemies.at(i)->setOnRenderer = false;
                bullets.at(j)->setOnRenderer = false;

                // shorten respawn time to increase difficulty
                if (score < 10) {
                    spawnTime -= spawnTime * 0.018;
                } else if (score < 25){
                    spawnTime -= spawnTime * 0.008;
                }
            }
        }
    }

}

/// resets game values
void GameHandler::resetValues() {
    player.health = 100;
    destructionLevel = 0;
    score = 0;
    spawnTime = 2000;
    isGameover = false;
    bullets.clear();
    enemies.clear();
}

/**
 * @brief renders the menu
 * @return the given selection as in
 * @warning only renders once. Things get messed up, when window is covered for example (input will still work)
 */
int GameHandler::showStartMenu() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr); // add background

    std::string str1 = "Sharkfighter";
    std::string str2 = "(1) Play ";
    std::string str3 = "(2) Quit ";
    std::string str4 = "(3) About";
    std::string str5 = "Please press (1),(2) or (3)!";

    renderText(str1,(1366/2)-200,30,400,100,lblue);
    renderText(str2,(1366/2)-80,200,160,60,orange);
    renderText(str3,(1366/2)-80,280,160,60,orange);
    renderText(str4,(1366/2)-80,360,160,60,orange);
    renderText(str5,(1366/2)-200,440,400,50,dorange);

    SDL_RenderPresent(renderer);
    return startMenuEventHandling();
}

/**
 * @brief eventhandling of the start menu
 * @return selection (0 for quit, 1 for game start, 3 for about section)
 */
int GameHandler::startMenuEventHandling() {
    if (event.type != SDL_MOUSEMOTION) { // don't use mouse motion events
        while (SDL_WaitEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 0;
            }
            if (event.type == SDL_KEYDOWN) {
                int key = event.key.keysym.sym;
                switch (key) {
                    case SDLK_ESCAPE:
                        return 0;
                    case SDLK_1:
                        SDL_Delay(300); // short delay before game start
                        return 1;
                    case SDLK_2:
                        return 0;
                    case SDLK_3:
                        return 3;
                    default:
                        break;
                }
            }
        }
    }
}

/**
 * @brief renders the about section
 * @return 0 for quit and 1 for back to menu
 * @warning only renders once. Things get messed up, when window is covered for example (input will still work)
 */
int GameHandler::showAbout() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);

    std::string str1 = "Sharkfighter";
    std::string str2 = "Game Project for ABV C++ Programmierung SoSe17 at FU Berlin/Zedat";
    std::string str3 = "Sebastian Kulich";
    std::string str4 = "input@grmlber.de";
    std::string str5 = "This software is published under the terms";
    std::string str6 = "of the MIT-License. You should have received";
    std::string str7 = "a copy of these terms with this software.";
    std::string str8 = "Feedback is always welcome!";
    std::string str9 = "No fishs nor sharks have been hurt during the making of this game :-)";

    renderText(str1,(1366/2)-200,30,400,100,lblue);
    renderText(str2,(1366/2)-400,150,800,40,black);
    renderText(str3,(1366/2)-150,210,300,50,black);
    renderText(str4,(1366/2)-100,260,200,30,black);
    renderText(str5,(1366/2)-130,520,280,25,grey);
    renderText(str6,(1366/2)-130,550,280,25,grey);
    renderText(str7,(1366/2)-130,580,280,25,grey);
    renderText(str8,(1366/2)-180,300,360,50,lblue);
    renderText(str9,(1366/2)-320,720,640,25,green);

    SDL_RenderPresent(renderer);

    if (event.type != SDL_MOUSEMOTION) {
        while (SDL_WaitEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 0;
            }
            if (event.type == SDL_KEYDOWN) {
                int key = event.key.keysym.sym;
                switch (key) {
                    case SDLK_ESCAPE:
                        return 0;
                    default:
                        return 1;
                }
            }
        }
    }
}

/// displays gameover box
void GameHandler::showGameOver() {
    // create black background box for text to be printed on for better visibility
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_Rect backgroundRect = {x:(1366/2)-200, y:200,w:400,h:250};
    SDL_RenderDrawRect(renderer, &backgroundRect);
    SDL_RenderFillRect(renderer,&backgroundRect);
    std::string str1 = "Game Over";
    std::string str2 = "Your Score: ";
    str2 += std::to_string(score);
    renderText(str1,(1366/2)-150,220,300,100,green);
    renderText(str2,(1366/2)-170,320,340,100,dorange);
}

/// Destroys and cleans up all components and closes SDL
void GameHandler::cleanComponents() {
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(playerTiles);
    SDL_DestroyTexture(fish);
    SDL_DestroyTexture(explosion);
    Mix_FreeChunk(soundBullet);
    Mix_FreeChunk(soundDestruction);
    Mix_FreeChunk(soundHealth);
    Mix_FreeChunk(soundScore);
    soundBullet, soundHealth, soundScore, soundDestruction = nullptr;
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

/**
 * @brief Loads all necessary game components
 * @return 0 if all fine, 1 if error occured
 */
int GameHandler::loadComponents() {
    //Textures
    background = loadTexture("img/water_backg.png");
    if (!background) {return 1;}
    playerTiles = loadTexture("img/player_tiles.png");
    if (!playerTiles) {return 1;}
    fish = loadTexture("img/fishR.png");
    if (!fish) {return 1;}
    explosion = loadTexture("img/single_exp.png");
    if (!explosion) {return 1;}

    //Fonts
    font = loadFont("fonts/hud_font.ttf");
    if (!font) {return 1;}

    //Sounds
    soundBullet = loadSoundChunk("sounds/click.wav");
    if (!soundBullet) {return 1;}
    soundScore = loadSoundChunk("sounds/ping.wav");
    if (!soundScore) {return 1;}
    soundHealth = loadSoundChunk("sounds/bite.wav");
    if (!soundHealth) {return 1;}
    soundDestruction = loadSoundChunk("sounds/blast.wav");
    if (!soundDestruction) {return 1;}

    return 0;
}

/**
 * @brief Tries to create a texture from given file
 * @param filePath location of the file
 * @return the texture or null if not successful
 */
SDL_Texture *GameHandler::loadTexture(std::string filePath) {
    SDL_Texture* texture = nullptr; // creates new, empty texture
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if(!surface) {
        printf("IMG_Load error: %s\n", IMG_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture) {
        printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface); // delete loaded surface
    return texture;
}

/**
 * @brief Tries to load font from given file
 * @param filePath location of the file
 * @return the font or null if not successful
 */
TTF_Font *GameHandler::loadFont(std::string filePath) {
    TTF_Font* font = nullptr;
    font = TTF_OpenFont(filePath.c_str(),96);
    if (!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    return font;
}

/**
 * @brief Tries to load sound chunk from given file
 * @param filePath location of the file
 * @return the sound chunk or null if not successful
 */
Mix_Chunk *GameHandler::loadSoundChunk(std::string filePath) {
    Mix_Chunk* sound = nullptr;
    sound = Mix_LoadWAV(filePath.c_str());
    if (!sound) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
    }
    return sound;
}






