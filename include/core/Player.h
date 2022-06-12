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
#include "Window.h"
//#include "Input.h"

#define NUM_SDLK 1000 // maximum range of SDL key number
#define SDLK_RIGHTCLICK NUM_SDLK - 1
#define SDLK_LEFTCLICK NUM_SDLK - 2

class Player {
public :
    Player(Window& window, WindowContent* windowContent);
    void start();
    void stop();
    ~Player();
    void getMousePosition(int& x, int& y);
    bool keyDown();
    void send(const Input& input);
    Input operator[](unsigned int i);
    void setWindowContent(WindowContent *windowContent);

private :
    bool _boolLoop = true;
    Input _inputArr[NUM_SDLK] = {{false, 0, 0}};
    void manageInput();
    void takeInput(const SDL_Event& event);
    unsigned int _numberKeyDown = 0;
    WindowContent* _windowContent;
    Window& _window;
};


#endif //PROJECTTT_PLAYER_H
