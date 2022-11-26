//
// Created by navid on 27/10/2022.
//

#include "util/FrameRate.h"

using namespace std;

FrameRate::FrameRate() {
    gettimeofday(&_tp, NULL);
    _currentTime = _tp.tv_sec * 1000 + _tp.tv_usec / 1000;
}

void FrameRate::display() {
    gettimeofday(&_tp, NULL);
    time_t t = _tp.tv_sec * 1000 + _tp.tv_usec / 1000;

    cout << int(1000. / double(t - _currentTime)) << " fps\n";

    _currentTime = t;
}