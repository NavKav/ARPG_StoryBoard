//
// Created by David on 27/11/2022.
//

#include "game/option/OptionLineMultiChoice.h"


void OptionLineMultiChoice::display(int x, int y) {
    int limit = (_window.getX() - 2*_window.getX()/10) / _choices.size();
    int position = 0;
    int w=0,h=0;

    _window.changeColor(255, 255, 255); // 255,255,255 = noir
    _window.changeFont("arial", 18); // police arial, taille 50 pixels de hauteur
    _window.writeText(x, y, _name + ": ");// écrit "Fullscreen" aux coordonnées (x,y) avec la couleur/police/taille sélectionnées
    _window.textSizeOf(_name + ": ",w,h);

    int x0 = w;

    for (std::string s : _choices){
        _window.writeText(x0 + x + MARGE *position, y, s);
        _window.textSizeOf(s,w,h);
        position += w;
    }


}

void OptionLineMultiChoice::insert(std::string choice) {
    _choices.push_front(choice);
}

OptionLineMultiChoice::OptionLineMultiChoice(std::string name, Window &window) :
OptionLine(window)
{
    _name = name;
}

