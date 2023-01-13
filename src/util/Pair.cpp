//
// Created by navid on 12/01/2023.
//

#include "Pair.h"

Pair::Pair(double x, double y) :
_x(x),
_y(y)
{

}

Pair Pair::operator+(const Pair& rhs) const {
    return Pair(this->_x + rhs._x, this->_y + rhs._y);
}

Pair &Pair::operator+=(float x) {
    _x += x;
    _y += x;
    return (*this);
}

Pair &Pair::operator+=(const Pair& rhs) {
    _x += rhs._x;
    _y += rhs._y;
    return *this;
}

float Pair::norm() const {
    return sqrt(_x*_x + _y*_y);
}

float Pair::operator^(Pair rhs) const{
    return _x*rhs._x + _y*rhs._y;
}

bool Pair::isLeftSide() const{
    return _x < 0;
}

bool Pair::isRightSide() const{
    return _x > 0;
}

Pair::Pair(const Pair &rhs) :
_x(rhs._x),
_y(rhs._y)
{

}

float Pair::x() {
    return _x;
}

float Pair::y() {
    return _y;
}

Pair &Pair::operator*(float x) {
    _x *= x;
    _y *= x;
    return *this;
}
