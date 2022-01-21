//
// Created by navid on 29/08/2021.
//

#ifndef DICE_GAME_PROJECT_WINDOWCONTENT_H
#define DICE_GAME_PROJECT_WINDOWCONTENT_H

#include "requirement.h"
#include "Window.h"

class WindowContent {
public :
    WindowContent(Window* window) : _window(window){};
    virtual void process() = 0;
protected :
    Window* _window = nullptr;

};


#endif //DICE_GAME_PROJECT_WINDOWCONTENT_H
