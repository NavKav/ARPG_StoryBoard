//
// Created by navid on 04/06/2021.
//
/*
 * Player source of inputs Class. Manage events from the launching computer.
 * Shall not use thread according to SDL function SDL_PollEvent() documentation.
 * */

#ifndef PROJECTTT_PLAYER_H
#define PROJECTTT_PLAYER_H

#include "requirement.h"
#include "WindowContent.h"
#include "Input.h"

#define NUM_SDLK 1000 // maximum range of SDL key number

class Player {
public :
    Player(WindowContent* windowContent);
    void start();
    void stop();
    ~Player();
    void getMousePosition(int& x, int& y);
    bool keyDown();
    void send(const Input& input);

private :
    bool _boolLoop = true;
    unsigned int _numberKeyDown = 0;
    WindowContent* _windowContent;


    Input takeInput(const SDL_Event& event);
};


#endif //PROJECTTT_PLAYER_H
