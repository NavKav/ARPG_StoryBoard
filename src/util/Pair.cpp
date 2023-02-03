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
    return {this->_x + rhs._x, this->_y + rhs._y};
}

Pair &Pair::operator+=(double x) {
    _x += x;
    _y += x;
    return (*this);
}

Pair &Pair::operator+=(const Pair& rhs) {
    _x += rhs._x;
    _y += rhs._y;
    return *this;
}

double Pair::norm() const {
    return sqrt(_x*_x + _y*_y);
}

double Pair::operator^(const Pair& rhs) const{
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

double Pair::x() const {
    return _x;
}

double Pair::y() const {
    return _y;
}

Pair Pair::operator*(double x) {
    _x *= x;
    _y *= x;
    return {_x*x, _y*x};
}

Pair &Pair::operator*=(double x) {
    _x *= x;
    _y *= x;
    return *this;
}

Pair& Pair::operator()(double x, double y) {
    _x += x;
    _y += y;
    return *this;
}

Pair Pair::operator-() const {
    return {-_x, -_y};
}
