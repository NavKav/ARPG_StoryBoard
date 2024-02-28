//
// Created by David on 27/11/2022.
//

#include "OptionLineToCheck.h"

void OptionLineToCheck::display(int x, int y) {
    _window.changeColor(255, 255, 255); // 255,255,255 = noir
    _window.changeFont("arial", 18); // police arial, taille 50 pixels de hauteur
    _window.writeText(x, y, _name + ": ");// écrit "Fullscreen" aux coordonnées (x,y) avec la couleur/police/taille sélectionnées
    int w = 0, h = 0;
    _window.textSizeOf(_name + ": ",w,h);
    if (_checked == false) {
        _window.scaleIMG(x + w, y, 30,25,"image/option/small_box.png");
    }
    else {
        _window.scaleIMG(x + 55, y + 55, _window.getX() / 1.25, _window.getY() / 10, "/option/checkedbox.png");
    }
}

OptionLineToCheck::OptionLineToCheck(std::string name,Window& window) : OptionLine(window) {
    _name = name;
}

