//
// Created by navid on 29/01/2023.
//

#include "UnitView.h"

/**
 *
 * @param x left top corner screen abscissa
 * @param y left top corner screen ordinate
 * @return true/false
 */
bool UnitView::isInScreen(double x, double y) {
    return  x < _unitModel._x
            && _unitModel._x < x + (double)_window.getX()/BLOCK_SIZE
            && y > _unitModel._y
            && _unitModel._y > y - (double)_window.getY()/BLOCK_SIZE;
}

UnitView::UnitView(UnitModel& unitModel, Window& window) :
_unitModel(unitModel),
_window(window)
{

}

bool UnitView::operator>(const UnitView& aux) const {
    return this->_unitModel._y < aux._unitModel._y
    || this->_unitModel._y == aux._unitModel._y
    && this->_unitModel._x < aux._unitModel._x;
}

const std::string& UnitView::getName() const {
    return _unitModel._name;
}
