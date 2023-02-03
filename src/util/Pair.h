//
// Created by navid on 12/01/2023.
//

#ifndef ARPG_STORYBOARD_PAIR_H
#define ARPG_STORYBOARD_PAIR_H

#include <cmath>

typedef
class Pair {
public :
    Pair(){};
    Pair(const Pair& rhs);
    Pair(double x, double y);
    Pair operator+(const Pair& rhs) const;
    Pair& operator+=(const Pair& rhs);
    Pair& operator+=(double x);
    Pair& operator*=(double x);
    double norm() const;
    double operator^(const Pair& rhs) const;
    bool isLeftSide() const;
    bool isRightSide() const;
    double x() const;
    double y() const;
    Pair operator*(double x);
    Pair& operator()(double x, double y);
    Pair operator-() const;
private :
    double _x, _y;
} Velocity;


#endif //ARPG_STORYBOARD_PAIR_H
