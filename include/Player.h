//
// Created by navid on 04/06/2021.
//
/*
 * Player source of inputs Class. Manage events from the launching computer.
 * Shall not use thread according to SDL function SDL_PollEvent() documentation.
 * */

#ifndef PROJECTTT_PLAYER_H
#define PROJECTTT_PLAYER_H

#include "recquirement.h"

#define NUM_SDLK 1000 // maximum range of SDL key number

class Player {
public :
    Player();
    void start();
    void stop();
    ~Player();
    bool isPressed(SDL_KeyCode key);
    void getMousePosition(int& x, int& y);
private :
    bool _boolLoop = true;

    /* Inside range class definition of an Input */
    struct Input {
        bool pressed;
        unsigned int u,v; // get start and end of keystroke
    };
    Input _inputArr[NUM_SDLK] = {{false, 0, 0}};

    void takeInput(const SDL_Event& event);
};


#endif //PROJECTTT_PLAYER_H
