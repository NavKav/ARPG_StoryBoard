//
// Created by navid on 03/09/2021.
//

#ifndef DICE_GAME_PROJECT_INPUT_H
#define DICE_GAME_PROJECT_INPUT_H

#include "requirement.h"

struct Input {
    SDL_KeyCode key;
    unsigned int u,v; // get start and end of keystroke
};

#endif //DICE_GAME_PROJECT_INPUT_H
