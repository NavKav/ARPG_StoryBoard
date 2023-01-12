//
// Created by David on 14/10/2022.
//

#include "MenuButton.h"



MenuButton::MenuButton(int xAxis, int yAxis, int width, int length, string path) {
    _abs = xAxis;
    _ord = yAxis;
    _dimAbs = width;
    _dimOrd = length;
    _path = path;
}

void MenuButton::display(Window& window) const {
    window.drawIMG(_abs, _ord, _path);
}


bool MenuButton::isInside(int X, int Y) {
    if (X >= _abs && X <= _abs + _dimAbs && Y >= _ord && Y <= _ord + _dimOrd ) {
        return true;
    }
    else
        return false;
}

