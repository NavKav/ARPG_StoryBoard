//
// Created by God on 27/11/2022.
//

#ifndef ARPG_STORYBOARD_OPTIONLINE_H
#define ARPG_STORYBOARD_OPTIONLINE_H


#include <string>
#include "../../core/Window.h"

class OptionLine { //abstract class
public:
    virtual void display(int x, int y) = 0; // definition of an abstract class =0 is enough, virtual => must define the function in every subclass
    //OptionLine() = default; // useless
    OptionLine(Window& window) : _window (window){};
protected:
    std::string _name;
    Window& _window;
};


#endif //ARPG_STORYBOARD_OPTIONLINE_H
