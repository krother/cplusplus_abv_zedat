cmake_minimum_required(VERSION 3.5)
project(sharkfighter)

set(CMAKE_CXX_STANDARD 14)

configure_file(img/water_backg.png img/water_backg.png COPYONLY)
configure_file(img/player_tiles.png img/player_tiles.png COPYONLY)
configure_file(img/fishR.png img/fishR.png COPYONLY)
configure_file(img/single_exp.png img/single_exp.png COPYONLY)
configure_file(fonts/hud_font.ttf fonts/hud_font.ttf COPYONLY)
configure_file(sounds/click.wav sounds/click.wav COPYONLY)
configure_file(sounds/ping.wav sounds/ping.wav COPYONLY)
configure_file(sounds/blast.wav sounds/blast.wav COPYONLY)
configure_file(sounds/bite.wav sounds/bite.wav COPYONLY)

set(SOURCE_FILES main.cpp GameHandler.cpp GameHandler.h Player.cpp Player.h Bullet.cpp Bullet.h Enemy.cpp Enemy.h)
add_executable(sharkfighter ${SOURCE_FILES})


INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

PKG_SEARCH_MODULE(SDL2_TTF REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2_MIX REQUIRED SDL2_mixer)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIX_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIX_LIBRARIES})