//
// Created by navid on 18/08/2021.
//

#ifndef DICE_GAME_PROJECT_REQUIREMENT_H
#define DICE_GAME_PROJECT_REQUIREMENT_H

#ifdef _WIN32
#include <windows.h>
#endif
#ifdef __unix__
#include <unistd.h>
#endif

#include <iostream>
#include <memory>
#include <unistd.h>
#include <ctime>

#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#define LOAD IMG_Load

struct Input {
    bool pressed;
    long int u,v;
    Sint32 mouseX = 0, mouseY = 0;
};


#endif //DICE_GAME_PROJECT_REQUIREMENT_H
