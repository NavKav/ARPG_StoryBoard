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
    Pair& operator+=(float x);
    float norm() const;
    float operator^(Pair rhs) const;
    bool isLeftSide() const;
    bool isRightSide() const;
    float x();
    float y();
    Pair& operator*(float x);
private :
    double _x, _y;
} Velocity;


#endif //ARPG_STORYBOARD_PAIR_H
