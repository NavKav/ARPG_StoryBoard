//
// Created by David on 23/10/2022.
//

#include "WindowFrame.h"

WindowFrame::WindowFrame(Window& window) :
_window(window)
{

}

void WindowFrame::display() {
    unsigned int _numberOption = _optionList.size();
    if (_numberOption > (_window.getY() - 2*_window.getY()/10) / OPTION_SIZE ) {
        _numberOption = (_window.getY() - 2*_window.getY()/10) / OPTION_SIZE ;
    }
    _window.scaleIMG(_window.getX()/10,_window.getY()/10,_window.getX()/1.25,OPTION_SIZE * _numberOption + SHIFT,"image/option/frame.png");
    int n = _numberOption;

    auto it = _optionList.begin();
    int x0 = _window.getX()/10 +SHIFT;
    int y0 = _window.getY()/10 + SHIFT;
    for (unsigned int i = 0; i < n ; i++) {
        (*it)->display(x0,OPTION_SIZE * i + y0);
        it ++;
    }
}

void WindowFrame::insert(OptionLine* ol) {
    _optionList.push_front(ol);

}

