//
// Created by navid on 26/01/2023.
//

#include "HeroView.h"

HeroView::HeroView(HeroModel &heroModel, Window &window):
UnitView(heroModel, window)
{

}

void HeroView::display(double xCorner, double yCorner) {
    _window.drawIMG(_unitModel._unitTemplate->_icon ,_window.getX()/2 - 45, _window.getY()/2 - 90);
}

bool HeroView::isInScreen(double x, double y) {
    return true;
}

bool HeroView::isHero() {
    return _unitModel.isHero();
}
