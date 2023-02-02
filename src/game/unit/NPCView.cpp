//
// Created by navid on 21/01/2023.
//

#include "NPCView.h"

NPCView::NPCView(Window &window, UnitModel& unitModel) :
UnitView(unitModel, window)
{
}

/**
 *
 * @param x left top corner screen abscissa
 * @param y left top corner screen ordinate
 */
void NPCView::display(double xCorner, double yCorner) {
    _window.drawOn(DEFAULT);
    _window.drawIMG((int)((DIST(xCorner, _unitModel._x) + _window.getX()/BLOCK_SIZE%2) * BLOCK_SIZE -  46),
                    (int)((DIST(yCorner, _unitModel._y) + _window.getY()/BLOCK_SIZE%2) * BLOCK_SIZE - 101),
                    "unit/golem.png");
}
