//
// Created by David on 23/10/2022.
//

#include "game/option/WindowFrame.h"

WindowFrame::WindowFrame(int number, Window& window) :
_numberOption(number), // <=> _numberOption = number
_window(window)
{
    if (number > (_window.getY() - 2*_window.getY()/10) / OPTION_SIZE ) {
        _numberOption = (_window.getY() - 2*_window.getY()/10) / OPTION_SIZE ;
    }

}

void WindowFrame::display() {
    _window.scaleIMG(_window.getX()/10,_window.getY()/10,_window.getX()/1.25,OPTION_SIZE * _numberOption,"option/truc.png");
    int n = _optionList.size();
    if (n > (_window.getY() - 2*_window.getY()/10) / OPTION_SIZE ) {
        n = (_window.getY() - 2*_window.getY()/10) / OPTION_SIZE ;
    }
    auto it = _optionList.begin();
    int x0 = _window.getX()/10 +SHIFT;
    int y0 = _window.getY()/10 +SHIFT;
    for (unsigned int i = 0; i < n ; i++){
        (*it)->display(x0,100*i + y0);
        it ++;
    }
}

void WindowFrame::insert(OptionLine* ol) {
    _optionList.push_front(ol);

}

